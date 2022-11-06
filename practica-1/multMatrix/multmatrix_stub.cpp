#include "multmatrix_stub.h"
#include "serialize.hpp"

#define PORT        55555
#define SERVER_IP   "52.73.125.19"

multmatrix_stub::multmatrix_stub() {
	serverId = initClient((char*)SERVER_IP, PORT);
	if(serverId < 0) cout << "ERROR " << __FILE__ << ": " << __LINE__ << endl;
}

matrix_t* multmatrix_stub::readMatrix(const char* fileName) {
	int typeOp = OP_READ;
	sendMSG(serverId, (const void*) &typeOp, sizeof(int));
	
	sendMSG(serverId, (const void*) fileName->c_str(), fileName->length());
	int* recvBuff = nullptr;
	int recvBuffSize = 0;
	
	recvMSG(serverId, (void**) &recvBuff, &recvBuffSize);
	
	// Aqui hay que deserializar y obtener la matriz
	delete[] recvBuff;
	return fileContent;
}

matrix_t* multmatrix_stub::multMatrices(matrix_t* m1, matrix_t *m2) {
	int typeOp = OP_MULT;
	sendMSG(serverId, (const void*) &typeOp, sizeof(int));
	
	matrix_t* v1s = serializeMatrix(v1, t_int);
	matrix_t* v2s = serializeMatrix(v2, t_int);
	
	sendMSG(serverId, (const void*) v1s->data(), v1s->size());
	sendMSG(serverId, (const void*) v2s->data(), v2s->size());

	int* recvBuff = nullptr;
	int recvBuffSize = 0;
	
	recvMSG(serverId, (void**) &recvBuff, &recvBuffSize);
	// Deserialize
	return sol;
}	
	


void multmatrix_stub::writeMatrix(matrix_t* m, const char *fileName) {
	
}

multmatrix_stub::~multMatrix_stub() {
	int typeOp = OP_END;
    sendMSG(serverId, (const void*)&typeOp, sizeof(int));
	closeConnection(serverId);
}

multmatrix_stub::matrix_t *createIdentity(int rows, int cols) {
	int typeOp = OP_IDENTIDAD;
	sendMSG(serverId, (const void*) &typeOp, sizeof(int));
	// Mandamos rows y cols
	// Recibes la matriz serializada
	// Deserializa
	// return
	
}

multmatrix_stub::matrix_t *createRandMatrix(int rows, int cols) {
	int typeOp = OP_RAND;
	sendMSG(serverId, (const void*) &typeOp, sizeof(int));
	// Mandamos rows y cols
	
	// Recibes la matriz serializada
	// Deserializa
	// return
}