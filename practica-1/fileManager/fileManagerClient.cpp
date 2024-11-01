#include "fileManagerClient.h"

FileManagerClient::FileManagerClient(const char * ip, int port)
{
    this->ip = (char*)malloc(strlen(ip) * sizeof(char));
    strcpy(this->ip, ip);
    this->port = port;
}

void FileManagerClient::readFile(char* fileName, char* &data, unsigned long int & dataLength)
{
    //Iniciamos operacion
    this->serverId = initClient(ip, port);

    int typeOp = OP_READ_FILE;

    // Enviamos el tipo de operacion
    sendMSG(serverId, (const void *)&typeOp, sizeof(int));

    // Enviamos el nombre del archivo a leer
    sendMSG(serverId, (const void *)fileName, strlen(fileName));

    // Recibimos el contenido del archivo a leer
    recvMSG(serverId, (void **)&data, (int *)&dataLength);

    //Cerramos operacion
    closeConnection(this->serverId);
}

void FileManagerClient::writeFile(char *fileName, char *data, unsigned long dataLength)
{
    int typeOp = OP_WRITE_FILE;
    int buffContentSize = 0;

    //Iniciamos operacion
    this->serverId = initClient(ip, port);

    // Enviamos el tipo de operacion
    sendMSG(serverId, (const void *)&typeOp, sizeof(int));

    // El nombre del archivo
    sendMSG(serverId, (const void *)fileName, strlen(fileName));

    // Por ultimo el contenido del archivo para que el servidor lo escriba
    sendMSG(serverId, (const void *)data, (int)dataLength);

    //Cerramos operacion
    closeConnection(this->serverId);
}

void FileManagerClient::readFile(std::string &fileName, std::string* &fileContent)
{
    int typeOp = OP_READ_FILE;
    char *buffContent = nullptr;
    int buffContentSize = 0;

    //Iniciamos operacion
    this->serverId = initClient(ip, port);

    // Enviamos el tipo de operacion
    sendMSG(serverId, (const void *)&typeOp, sizeof(int));

    // Enviamos el nombre del archivo a leer
    sendMSG(serverId, (const void *)fileName.c_str(), fileName.length());

    // Recibimos el contenido del archivo a leer
    recvMSG(serverId, (void **)&buffContent, &buffContentSize);
    fileContent = new std::string(buffContent);

    delete[] buffContent;

    //Cerramos operacion
    closeConnection(this->serverId);
}

void FileManagerClient::writeFile(std::string &fileName, std::string &data, int dataLength)
{
    int typeOp = OP_WRITE_FILE;
    int buffContentSize = 0;

    // Enviamos el tipo de operacion
    sendMSG(serverId, (const void *)&typeOp, sizeof(int));

    // El nombre del archivo
    sendMSG(serverId, (const void *)fileName.c_str(), fileName.length());

    // Por ultimo el contenido del archivo para que el servidor lo escriba
    sendMSG(serverId, (const void *)data.c_str(), data.length());
}

vector<string *> *FileManagerClient::listFiles()
{
    int typeOp = OP_LIST_DIR;
    char *buffContent = nullptr;
    int buffContentSize = 0;
    std::vector<std::string *> *flist = nullptr;

    //Iniciamos operacion
    this->serverId = initClient(ip, port);

    // Enviamos el tipo de operacion
    sendMSG(serverId, (const void *)&typeOp, sizeof(int));

    // recibimos el listado de archivos
    recvMSG(serverId, (void **)&buffContent, &buffContentSize);

    // deserializamos para convertirlo a un vector de strings, donde cada string es un archivo del directorio
    std::string *buffContentStr = new std::string(buffContent);
    flist = deserializeStringVector(buffContentStr);

    delete buffContentStr;

    //Cerramos operacion
    closeConnection(this->serverId);

    return flist;
}

void FileManagerClient::freeListedFiles(vector<string*>* fileList)
{
    FileManager::freeListedFiles(fileList);
}