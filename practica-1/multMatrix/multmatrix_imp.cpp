#include "multmatrix_imp.h"
#include "multmatrix_stub.h"
#include "serialize.h"
//#include "utils.h"

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
				cout << "FIN COMUNICACION" << endl;
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
				cout << "ERROR Operacion: " << typeOp[0] << " no valida" << endl;
				break;
		}
	} while(typeOp[0] != OP_END);
	if(!typeOp) delete[] typeOp;
}

void multMatrix_imp::recvIdentity() {

	// Crea matriz identidad
	// Recibe rows cols 
	// Llama a funcion main
	// Manda matriz serializada
	int* recvBuff = nullptr;
    int recvBufSize = 0;
    int rows = 0;
    int cols = 0;
    int res = 0;

    recvMSG(clientId, (void**)&recvBuff, &recvBufSize);
    rows = ((int*)recvBuff)[0]; delete[] recvBuff;

    recvMSG(clientId, (void**)&recvBuff, &recvBufSize);
    cols = ((int*)recvBuff)[0]; delete[] recvBuff;

	matrix_t* identMat = mult->createIdentity(rows, cols);
	int* identArr = serializeMatrix(identMat);
	int length = identMat->rows * identMat->cols + 2;

	sendMSG(clientId, (void**) &identArr, length);

}

void multMatrix_imp::recvRandMatrix() {
	// Crea matriz aleatoria
	// Recibe rows cols 
	// Llama a funcion main
	// Manda matriz serializada
	int* recvBuff = nullptr;
    int recvBufSize = 0;
    int rows = 0;
    int cols = 0;
    int res = 0;

    recvMSG(clientId, (void**)&recvBuff, &recvBufSize);
    rows = ((int*)recvBuff)[0]; delete[] recvBuff;

    recvMSG(clientId, (void**)&recvBuff, &recvBufSize);
    cols = ((int*)recvBuff)[0]; delete[] recvBuff;

	matrix_t* randMat = mult->createRandMatrix(rows, cols);
	int* randArr = serializeMatrix(randMat);
	int length = randMat->rows * randMat->cols + 2;

	sendMSG(clientId, (void**) &randArr, length);
}

void multMatrix_imp::recvReadMatrix() {
	// Lee matriz de un archivo
	char* recvBuffFileName = nullptr;
	int recvBuffSize = 0;
	
	recvMSG(clientId, (void**) &recvBuffFileName, &recvBuffSize);
	
	string* fileName = new string(recvBuffFileName);
	matrix_t* fileContent = mult->readMatrix(fileName);
	int* matrix = serializeMatrix(fileContent);

	int length = fileContent->rows * fileContent->cols + 2;

	sendMSG(clientId, (void**) &matrix, length);
	
	delete fileName;
	delete fileContent;
	delete[] recvBuffFileName;
}


void multMatrix_imp::recvMultMatrix() {
	// Multiplica dos matrices
	byte* recvBuff = nullptr;
    int recvBufSize = 0;

    recvMSG(clientId, (void**)&recvBuff, &recvBufSize);
	matrix_t* matrix1 = deserializeMatrix(recvBuff);
	// Deserializar
    delete[] recvBuff;

    recvMSG(clientId, (void**)&recvBuff, &recvBufSize);
    // Deserializar
	matrix_t* matrix2 = deserializeMatrix(recvBuff);
	delete[] recvBuff;

    matrix_t* res = mult->multMatrices(matrix1, matrix2);
	// Serializar
	int* resArr = serializeMatrix(res);
	int length = res->cols * res->rows + 2;

    sendMSG(clientId, (const void*)&resArr, length);
    delete matrix1;
    delete matrix2;
	
}

void multMatrix_imp::recvWriteMatrix() {
	// Escribe matriz a archivo
	// Lee matriz de un archivo
	char* recvBuffFileName = nullptr;
	int recvBuffSize = 0;
	
	recvMSG(clientId, (void**) &recvBuffFileName, &recvBuffSize);
	
	string* fileName = new string(recvBuffFileName);
	delete[] recvBuff;

	recvMSG(clientId, (void**) &recvBuff, &recvBuffSize);
	matrix_t* matrix = deserializeMatrix(recvBuff);
	mult->writeMatrix(matrix, fileName);

}
























