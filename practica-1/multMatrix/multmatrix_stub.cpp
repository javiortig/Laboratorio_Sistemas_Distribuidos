#include "multmatrix_stub.h"
#include "serialize.h"
#include "utils.h"

#define PORT        55555
#define SERVER_IP   "52.73.125.19"

multMatrix_stub::multMatrix_stub() {
	serverId = initClient((char*)SERVER_IP, PORT);
	if(serverId < 0) cout << "ERROR " << __FILE__ << ": " << __LINE__ << endl;
}

matrix_t* multMatrix_stub::readMatrix(const char* fileName) {
	int typeOp = OP_READ;
	sendMSG(serverId, (const void*) &typeOp, sizeof(int));
	
	sendMSG(serverId, (const void*) fileName->c_str(), fileName->length());

	int* recvBuff = nullptr;
	int recvBuffSize = 0;
	
	recvMSG(serverId, (void**) &recvBuff, &recvBuffSize);

	matrix_t* matrix = deserializeMatrix(recvBuff);
	delete[] recvBuff;
	return matrix;
	
	// Aqui hay que deserializar y obtener la matriz
	
}

matrix_t* multmatrix_stub::multMatrices(matrix_t* m1, matrix_t *m2) {
	int typeOp = OP_MULT;
	sendMSG(serverId, (const void*) &typeOp, sizeof(int));
	
	matrix_t* v1s = serializeMatrix(v1);
	matrix_t* v2s = serializeMatrix(v2);

	int length1 = v1s->cols * v1s->rows + 2;
	int length2 = v2s->cols * v2s->rows + 2;
	
	sendMSG(serverId, (const void*) &v1, length1);
	sendMSG(serverId, (const void*) &v2, length2);

	int* recvBuff = nullptr;
	int recvBuffSize = 0;
	
	recvMSG(serverId, (void**) &recvBuff, &recvBuffSize);
	// Deserialize
	return sol;
}	
	


void multmatrix_stub::writeMatrix(matrix_t* m, const char *fileName) {
	int typeOp = OP_WRITE;
	sendMSG(serverId, (const void*) &typeOp, sizeof(int));
	
	sendMSG(serverId, (const void*) fileName->c_str(), fileName->length());

	// Ahora mandamos la matriz
	int* mSerialized = serializeMatrix(m);
	int length  = m->cols * m->rows + 2;
	sendMSG(serverId, (const void*) &mSerialized, &length);
}

multmatrix_stub::~multMatrix_stub() {
	int typeOp = OP_END;
    sendMSG(serverId, (const void*)&typeOp, sizeof(int));
	closeConnection(serverId);
}

multmatrix_stub::matrix_t *createIdentity(int rows, int cols) {
	int typeOp = OP_IDENTIDAD;
	sendMSG(serverId, (const void*) &typeOp, sizeof(int));

	sendMSG(serverId, (const void*) &rows, sizeof(int));
	sendMSG(serverId, (const void*) &cols, sizeof(int));

	int* recvBuff = nullptr;
    int recvBuffSize = 0;

    recvMSG(serverId, (void**)&recvBuff, &recvBuffSize);
	
	matrix_t* identMat = deserializeMatrix(recvBuff);
	return identMat;
	// Mandamos rows y cols
	// Recibes la matriz serializada
	// Deserializa
	// return
	
}

multmatrix_stub::matrix_t *createRandMatrix(int rows, int cols) {
	int typeOp = OP_RAND;
	sendMSG(serverId, (const void*) &typeOp, sizeof(int));

	sendMSG(serverId, (const void*) &rows, sizeof(int));
	sendMSG(serverId, (const void*) &cols, sizeof(int));

	int* recvBuff = nullptr;
    int recvBuffSize = 0;

    recvMSG(serverId, (void**)&recvBuff, &recvBuffSize);
	
	matrix_t* randMat = deserializeMatrix(recvBuff);
	return randMat;
	// Mandamos rows y cols
	// Recibes la matriz serializada
	// Deserializa
	// return
}