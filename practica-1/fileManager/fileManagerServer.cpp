#include "fileManagerServer.h"

FileManagerServer::FileManagerServer(int clientId, string path)
{
    this->clientId = clientId;
    this->fm = new FileManager(path);
}

FileManagerServer::~FileManagerServer()
{
    delete fm;

    if (clientId >= 0)
        closeConnection(clientId);
}

void FileManagerServer::opReadFile()
{
    char *fileName = nullptr;
    int fileNameSize = 0;

    char *fileContent = nullptr;
    unsigned long fileLen = 0;

    // recibe nombre del fichero.
    recvMSG(clientId, (void **)&fileName, &fileNameSize);
    fileName[fileNameSize] = '\0';

    //std::cout << "Traza: opReadFile1 "
    //          << "quiero leer: " << fileName << " con fileNameSize: " << fileNameSize << endl;

    // lee el fichero:
    fm->readFile(fileName, fileContent, fileLen);

    // std::cout << "Traza: opReadFile2. Leo archivo y contiene:\n"
    //           << fileContent << endl
    //           << "con len: " << strlen(fileContent) << endl;

    // lo envia de vuelta al cliente
    sendMSG(clientId, (const void *)fileContent, strlen(fileContent));

    // std::cout << "Traza: opReadFile3. Salgo\n";

    delete fileName;
    delete fileContent;
}

void FileManagerServer::opWriteFile()
{
    char *fileName = nullptr;
    int fileNameSize = 0;

    char *fileContent = nullptr;
    unsigned long fileLen = 0;

    // recibe nombre del fichero.
    recvMSG(clientId, (void **)&fileName, &fileNameSize);
    fileName[fileNameSize] = '\0';

    //recibe el contenido del fichero
    recvMSG(clientId, (void **)&fileContent, (int *) &fileLen);
    //TODO: HACE FALTA? fileContent[fileLen] = '\0';

    fm->writeFile(fileName, fileContent, fileLen);

}

void FileManagerServer::opListDir()
{
    //obtenemos el directorio
    std::vector<std::string*>* flist = fm->listFiles();

    //lo serializamos
    string* serialized_flist = serializeStringVector(flist);

    //lo enviamos
    sendMSG(clientId, (const void *)serialized_flist->c_str(), serialized_flist->length());

    delete flist;
    delete serialized_flist;
}

void FileManagerServer::recvOp()
{
    int *typeOp = nullptr;
    int typeOpSize = 0;

    if (!typeOp)
        delete[] typeOp;

    //std::cout << "Traza: recvOp1\n";
    recvMSG(clientId, (void **)&typeOp, &typeOpSize);
    //std::cout << "Traza: recvOp2\n";
    switch (typeOp[0])
    {
    case OP_READ_FILE:
        opReadFile();
        break;

    case OP_WRITE_FILE:
        opWriteFile();
        break;

    case OP_LIST_DIR:
        opListDir();
        break;

    default:
        std::cout << "ERROR OPERACION <" << typeOp[0] << "> no valida.\n";
        break;
    }

    if (!typeOp)
        delete[] typeOp;
}
