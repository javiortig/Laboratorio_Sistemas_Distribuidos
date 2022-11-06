#include "multmatrix_imp.h"
#include "multmatrix_stub.h"
#include "serialize.hpp"

multmatrix_imp::multmatrix_imp(int clientId) {
	this->clientId = clientId;
	mult = new multmatrix();
}

multmatrix_imp::~multmatrix_imp() {
	delete mult;
	closeConnection(clientId);
}

void multmatrix_imp::recvOp() {
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

void multmatrix_imp::recvIdentity() {
	// Crea matriz identidad
	// Recibe rows cols 
	// Llama a funcion main
	// Manda matriz serializada
}

void multmatrix_imp::recvRandMatrix() {
	// Crea matriz aleatoria
	// Recibe rows cols 
	// Llama a funcion main
	// Manda matriz serializada
}

void multmatrix_imp::recvReadMatrix() {
	// Lee matriz de un archivo
	char* recvBuffFileName = nullptr;
	int recvBuffSize = 0;
	
	recvMSG(clientId, (void**) &recvBuffFileName, &recvBuffSize);
	
	string* fileName = new string(recvBuffFileName);
	int* fileContent = mult->leerFichero(fileName);
	
	sendMSG(clientId, (const void*) fileContent->c_str(), fileContent->length());
	
	delete fileName;
	delete fileContent;
	delete[] recvBuffFileName;
}

void multmatrix_imp::recvMultMatrix() {
	// Multiplica dos matrices
	byte* recvBuff = nullptr;
    int recvBufSize = 0;

    recvMSG(clientId, (void**)&recvBuff, &recvBufSize);
	// Deserializar
    

    recvMSG(clientId, (void**)&recvBuff, &recvBufSize);
    // Deserializar

    int res = mult->multMatrices(v1, v2);
	// Serializar

    sendMSG(clientId, (const void*)&res, sizeof(int));
    delete v1;
    delete v2;
	
}

void multmatrix_imp::recvWriteMatrix() {
	// Escribe matriz a archivo


}
























