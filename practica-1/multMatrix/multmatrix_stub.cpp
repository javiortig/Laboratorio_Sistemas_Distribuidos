#include "multmatrix_stub.h"
#include "serialize.h"
#include "utils.h"

#define PORT        60001
#define SERVER_IP   "44.197.149.124"

using namespace std;

multMatrix_stub::multMatrix_stub() {
	serverId = initClient((char*)SERVER_IP, PORT);
	if(serverId < 0) cout << "ERROR " << __FILE__ << ": " << __LINE__ << endl;
}

matrix_t* multMatrix_stub::readMatrix(const char* fileName) {
	int typeOp = OP_READ;
	sendMSG(serverId, (const void*) &typeOp, sizeof(int));
	
	int length = strlen(fileName);
	sendMSG(serverId, (const void*) fileName, length);

	int* recvBuff = nullptr;
	int recvBuffSize = 0;
	
    recvMSG(serverId, (void**)&recvBuff, &recvBuffSize);
	std::vector<int>* vec = new std::vector<int>();
	vec->reserve(recvBuffSize);
	vec->resize(recvBuffSize);
	memcpy(vec->data(), recvBuff, recvBuffSize);
	matrix_t* mat = deserializeMatrix(vec);
	
	delete[] recvBuff;
	//vec->clear();
	
	return mat;
}

matrix_t* multMatrix_stub::multMatrices(matrix_t* m1, matrix_t *m2) {
	int typeOp = OP_MULT;
	sendMSG(serverId, (const void*) &typeOp, sizeof(int));
	
	int* recvBuff = nullptr;
	int recvBuffSize = 0;
	
	vector<int>* v1 = serializeMatrix(m1);
	int length1 = v1->size();
	sendMSG(serverId, (const void*) v1->data(), length1*sizeof(int));
	
	vector<int>* v2 = serializeMatrix(m2);
	int length2 = v2->size();
	sendMSG(serverId, (const void*) v2->data(), length2*sizeof(int));

    recvMSG(serverId, (void**)&recvBuff, &recvBuffSize);
	std::vector<int>* v3 = new std::vector<int>();
	v3->reserve(recvBuffSize);
	v3->resize(recvBuffSize);
	memcpy(v3->data(), recvBuff, recvBuffSize);
	matrix_t* matRes = deserializeMatrix(v3);
	
	delete[] recvBuff;
	//v1->clear();
	//v2->clear();
	//v3->clear();
	
	return matRes;
}	
	


void multMatrix_stub::writeMatrix(matrix_t* m, const char *fileName) {
	int typeOp = OP_WRITE;
	sendMSG(serverId, (const void*) &typeOp, sizeof(int));
	
	int length = strlen(fileName);
	
	sendMSG(serverId, (const void*) fileName, length);

	vector<int>* vec = serializeMatrix(m);
	int length2 = vec->size();
	sendMSG(serverId, (const void*) vec->data(), length2*sizeof(int));
	
	//vec->clear();
}

multMatrix_stub::~multMatrix_stub() {
	int typeOp = OP_END;
    sendMSG(serverId, (const void*) &typeOp, sizeof(int));
	closeConnection(serverId);
}

matrix_t* multMatrix_stub::createIdentity(int rows, int cols) {
	int typeOp = OP_IDENTIDAD;
	sendMSG(serverId, (const void*) &typeOp, sizeof(int));

	sendMSG(serverId, (const void*) &rows, sizeof(int));
	sendMSG(serverId, (const void*) &cols, sizeof(int));
	
	int* recvBuff = nullptr;
    int recvBuffSize = 0;
	
	recvMSG(serverId, (void**)&recvBuff, &recvBuffSize);
	std::vector<int>* vec = new std::vector<int>();
	vec->reserve(recvBuffSize);
	vec->resize(recvBuffSize);
	memcpy(vec->data(), recvBuff, recvBuffSize);
	matrix_t* idMat = deserializeMatrix(vec);
	
	delete[] recvBuff;
	//vec->clear();
	
	return idMat;
}

matrix_t* multMatrix_stub::createRandMatrix(int rows, int cols) {
	int typeOp = OP_RAND;
	sendMSG(serverId, (const void*) &typeOp, sizeof(int));

	sendMSG(serverId, (const void*) &rows, sizeof(int));
	sendMSG(serverId, (const void*) &cols, sizeof(int));

	int* recvBuff = nullptr;
    int recvBuffSize = 0;
	
    recvMSG(serverId, (void**)&recvBuff, &recvBuffSize);
	std::vector<int>* vec = new std::vector<int>();
	vec->reserve(recvBuffSize);
	vec->resize(recvBuffSize);
	memcpy(vec->data(), recvBuff, recvBuffSize);
	matrix_t* randMat = deserializeMatrix(vec);
	
	delete[] recvBuff;
	//vec->clear();
	
	return randMat;
}