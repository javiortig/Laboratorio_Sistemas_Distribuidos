#include "fileManagerClient.h"

FileManagerClient::FileManagerClient(char *ip, int port)
{
    this->serverId = initClient(ip, port);

    if (serverId < 0)
        std::cout << "ERROR EN EL ARCHIVO" << __FILE__ << ":" << __LINE__ << "\n";
}

void FileManagerClient::readFile(std::string &fileName)
{
    int typeOp = OP_READ_FILE;
    char *buffContent = nullptr;
    int buffContentSize = 0;
    //Enviamos el tipo de operacion
    sendMSG(serverId, (const void *)&typeOp, sizeof(int));

    //Enviamos el nombre del archivo a leer
    sendMSG(serverId, (const void *)fileName.c_str(), fileName.length());

    //Recibimos el contenido del archivo a leer
    recvMSG(serverId, (void **)&buffContent, &buffContentSize);
    std::string fileContent(buffContent);

    // TODO: escribir en un archivo local?? o imprimir por pantalla
    std::cout << fileContent;

    delete[] buffContent;

    //std::cout << "Traza: readFile6. Salgo.\n";
}

void FileManagerClient::writeFile(std::string &fileName, std::string &data, unsigned long dataLength)
{
    int typeOp = OP_WRITE_FILE;
    char *buffContent = nullptr;
    int buffContentSize = 0;

    // Enviamos el tipo de operacion
    sendMSG(serverId, (const void *)&typeOp, sizeof(int));

    // El nombre del archivo
    sendMSG(serverId, (const void *)fileName.c_str(), fileName.length());

    // Por ultimo el contenido del archivo para que el servidor lo escriba
    sendMSG(serverId, (const void *)data.c_str(), data.length());
}

void FileManagerClient::listDir(){
    int typeOp = OP_LIST_DIR;
    char *buffContent = nullptr;
    int buffContentSize = 0;
    std::vector<std::string*>* flist=nullptr;

    // Enviamos el tipo de operacion
    sendMSG(serverId, (const void *)&typeOp, sizeof(int));

    //recibimos el listado de archivos
    recvMSG(serverId, (void **)&buffContent, &buffContentSize);

    //deserializamos para convertirlo a un vector de strings, donde cada string es un archivo del directorio
    std::string *buffContentStr = new std::string(buffContent);
    flist = deserializeStringVector(buffContentStr);

    //TODO: por ahora lo imprimimos:
    std::cout << "Total number of directories: " << flist->size() << "\n";
    for(auto it=flist->begin();it!= flist->end();++it)
    {
        std::cout << **it << "\n";
    }

    delete buffContentStr;
    delete flist;
}