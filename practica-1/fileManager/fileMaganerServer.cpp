#include "fileManagerServer.h"

FileManagerServer::FileManagerServer(int clientId, string path){
    this->clientId = clientId;
    this->fm = new FileManager(path);
}

FileManagerServer::~FileManagerServer(){
    delete fm;

    if (clientId >= 0) closeConnection(clientId);
}

void FileManagerServer::recvOp(){
    int* typeOp = nullptr;
    int typeOpSize = 0;

    do{
        if (!typeOp) delete[] typeOp;

        recvMSG(clientId, (void **)typeOp, &typeOpSize);
        
        switch (typeOp[0])
        {
        case OP_READ_FILE:
            opReadFile();
            break;

        case OP_WRITE_FILE:
            //TODO
            break;
        
        case OP_END:
            //TODO: no se si hay que hacer algo más aquí?
            std::cout << "Fin Comunicaciones\n";
            break;
        
        default:
            std::cout << "ERROR OPERACION" << typeOp[0] << " no valida.\n";
            break;
        }
    }while(typeOp[0]!=OP_END);

    if (!typeOp) delete[] typeOp;
}

void FileManagerServer::opReadFile(){
    char * fileName = nullptr;
    int fileNameSize = 0;

    char* fileContent = nullptr;
    unsigned long fileLen = 0;

    //recibe nombre del fichero.
    recvMSG(clientId, (void**)&fileName, &fileNameSize);

    // std::string* fileName = new std::string(fileNameBuff);

    //lee el fichero:
    fm->readFile(fileName, fileContent, fileLen);

    //lo envia de vuelta al cliente
    sendMSG(clientId, (const void *)fileContent, strlen(fileContent));

    delete fileName;
    delete fileContent;
}