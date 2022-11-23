#include "multmatrix_imp.h"
#include "multmatrix_stub.h"
#include "serialize.h"

multMatrix_imp::multMatrix_imp(int clientId) {
	this->clientId = clientId;
	mult = new multMatrix();
}

multMatrix_imp::~multMatrix_imp() {
	delete mult;
	closeConnection(clientId);
}

void multMatrix_imp::recvOp() {
	int* typeOp = nullptr;
	int typeOpSize = 0;
	
	do {
		if(!typeOp) delete[] typeOp;
		recvMSG(clientId, (void**) &typeOp, &typeOpSize);
		switch (typeOp[0]) {
			case OP_END:
				std::cout << "FIN COMUNICACION" << std::endl;
				break;
			case OP_IDENTIDAD:
				recvIdentity();
				break;
			case OP_RAND:
				recvRandMatrix();
				break;
			case OP_READ:
				recvReadMatrix();
				break;
			case OP_MULT:
				recvMultMatrix();
				break;
			case OP_WRITE:
				recvWriteMatrix();
				break;
			default:
				std::cout << "ERROR Operacion: " << typeOp[0] << " no valida" << std::endl;
				break;
		}
	} while(typeOp[0] != OP_END);
	if(!typeOp) delete[] typeOp;
}

void multMatrix_imp::recvIdentity() {

	int* recvBuff = nullptr;
    int recvBufSize = 0;
	
    int rows = 0;
    int cols = 0;

    recvMSG(clientId, (void**)&recvBuff, &recvBufSize);
    rows = ((int*)recvBuff)[0]; delete[] recvBuff;

    recvMSG(clientId, (void**)&recvBuff, &recvBufSize);
    cols = ((int*)recvBuff)[0]; delete[] recvBuff;

	matrix_t* identMat = mult->createIdentity(rows, cols);
	
	std::vector<int>* identVec = serializeMatrix(identMat);
	int length = identVec->size();

	sendMSG(clientId, (const void*) identVec->data(), length*sizeof(int));
	
	delete[] recvBuff;
	// borrar la matriz me da segmentation fault, quizas este siendo usada todavia
	//delete[] identMat->data;
    //delete[] identMat;
	//identVec->clear();
}

void multMatrix_imp::recvRandMatrix() {
	
	int* recvBuff = nullptr;
    int recvBufSize = 0;
	
    int rows = 0;
    int cols = 0;

    recvMSG(clientId, (void**)&recvBuff, &recvBufSize);
    rows = ((int*)recvBuff)[0]; delete[] recvBuff;

    recvMSG(clientId, (void**)&recvBuff, &recvBufSize);
    cols = ((int*)recvBuff)[0]; delete[] recvBuff;

	matrix_t* randMat = mult->createRandMatrix(rows, cols);
	
	std::vector<int>* randVec = serializeMatrix(randMat);
	int length = randVec->size();
	
	sendMSG(clientId, (const void*) randVec->data(), length*sizeof(int));

	delete[] recvBuff;
	//delete[] randMat->data;
    //delete[] randMat;
	//randVec->clear();
}

void multMatrix_imp::recvReadMatrix() {
	char* recvBuffFileName = nullptr;
	int recvBuffSize = 0;
	
	recvMSG(clientId, (void**) &recvBuffFileName, &recvBuffSize);
	recvBuffFileName[recvBuffSize] = '\0';

	matrix_t* fileContent = mult->readMatrix(recvBuffFileName);
	
	std::vector<int>* vecFile = serializeMatrix(fileContent);
	int length = vecFile->size();
	
	sendMSG(clientId, (const void*) vecFile->data(), length*sizeof(int));
	
	delete[] recvBuffFileName;
	//delete[] fileContent->data;
	//delete[] fileContent;
	//vecFile->clear();
}


void multMatrix_imp::recvMultMatrix() {
	int* recvBuff = nullptr;
    int recvBuffSize = 0;

	recvMSG(clientId, (void**)&recvBuff, &recvBuffSize);
	std::vector<int>* vec1 = new std::vector<int>();
	vec1->reserve(recvBuffSize);
	vec1->resize(recvBuffSize);
	memcpy(vec1->data(), recvBuff, recvBuffSize);
	matrix_t* m1 = deserializeMatrix(vec1);
	
	delete[] recvBuff;
	recvBuffSize = 0;
	
	recvMSG(clientId, (void**)&recvBuff, &recvBuffSize);
	std::vector<int>* vec2 = new std::vector<int>();
	vec2->reserve(recvBuffSize);
	vec2->resize(recvBuffSize);
	memcpy(vec2->data(), recvBuff, recvBuffSize);
	matrix_t* m2 = deserializeMatrix(vec2);

    matrix_t* matRes = mult->multMatrices(m1, m2);
	
	std::vector<int>* vecRes = serializeMatrix(matRes);
	int length = vecRes->size();
    sendMSG(clientId, (const void*)vecRes->data(), length*sizeof(int));
	
	delete[] recvBuff;
	//vec1->clear();
	//vec2->clear();
	//vecRes->clear();
	//delete[] m1->data;
    //delete[] m1;
	//delete[] m2->data;
    //delete[] m2;
	//delete[] matRes->data;
    //delete[] matRes;
}

void multMatrix_imp::recvWriteMatrix() {
	char* recvBuffFileName = nullptr;
	int* recvBuff = nullptr;
	int recvBuffSize = 0;

	recvMSG(clientId, (void**) &recvBuffFileName, &recvBuffSize);
	recvBuffFileName[recvBuffSize] = '\0';

	delete[] recvBuff;
    recvBuffSize = 0;
	
    recvMSG(clientId, (void**)&recvBuff, &recvBuffSize);
	
	std::vector<int>* vec = new std::vector<int>();
	vec->reserve(recvBuffSize);
	vec->resize(recvBuffSize);
	memcpy(vec->data(), recvBuff, recvBuffSize);
	matrix_t* mat = deserializeMatrix(vec);
	
	mult->writeMatrix(mat, recvBuffFileName);
	
	delete[] recvBuffFileName;
	delete[] recvBuff;
	//vec->clear();
	//delete[] mat->data;
	//delete[] mat;
}