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
	
	recvMSG(serverId, (void**) &recvBuff, &recvBuffSize);

	matrix_t* matrix = deserializeMatrix(recvBuff);
	delete[] recvBuff;
	return matrix;
	
	// Aqui hay que deserializar y obtener la matriz
	
}

matrix_t* multMatrix_stub::multMatrices(matrix_t* m1, matrix_t *m2) {
	int typeOp = OP_MULT;
	sendMSG(serverId, (const void*) &typeOp, sizeof(int));
	
	int* m1s = serializeMatrix(m1);
	int* m2s = serializeMatrix(m2);

	int length1 = m1->cols * m1->rows + 2;
	int length2 = m2->cols * m2->rows + 2;
	
	sendMSG(serverId, (const void*) &m1s, length1);
	sendMSG(serverId, (const void*) &m2s, length2);

	int* recvBuff = nullptr;
	int recvBuffSize = 0;
	
	recvMSG(serverId, (void**) &recvBuff, &recvBuffSize);
	// Recibo la matrix serializada y la deserializo y la devuelvo
	matrix_t* matrixSol = deserializeMatrix(recvBuff);
	delete[] recvBuff;
	return matrixSol;
}	
	


void multMatrix_stub::writeMatrix(matrix_t* m, const char *fileName) {
	int typeOp = OP_WRITE;
	sendMSG(serverId, (const void*) &typeOp, sizeof(int));
	
	int length = strlen(fileName);
	
	sendMSG(serverId, (const void*) fileName, length);

	// Ahora mandamos la matriz
	int* mSerialized = serializeMatrix(m);
	int length2  = m->cols * m->rows + 2;
	sendMSG(serverId, (const void*) &mSerialized, length2);
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
	
	matrix_t* identMat = deserializeMatrix(recvBuff);
	return identMat;
	// Mandamos rows y cols
	// Recibes la matriz serializada
	// Deserializa
	// return
	
}

matrix_t* multMatrix_stub::createRandMatrix(int rows, int cols) {
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