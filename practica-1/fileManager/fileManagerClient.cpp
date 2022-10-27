#include "fileManagerClient.h"

FileManagerClient::FileManagerClient(char* ip = SERVER_IP, int port = PORT){
    this->serverId = initClient(ip, port);

    if (serverId <0 ) std::cout << "ERROR EN EL ARCHIVO" << __FILE__ << ":" << __LINE__ << "\n";
}

void FileManagerClient::readFile(char* fileName){
    int typeOp = OP_READ_FILE;
    sendMSG(serverId, (const void *)&typeOp, sizeof(int));

    sendMSG(serverId, (const void*) fileName, strlen(fileName));
    char* buffContent = nullptr;
    int buffContentSize = 0;

    recvMSG(serverId, (void**)&buffContent, &buffContentSize);

    std::string* fileContent = new std::string(buffContent);
    delete[]buffContent;

    //TODO: escribir en un archivo local
    std::cout << *fileContent;
}