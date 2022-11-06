#include "clientConsole.h"

ClientConsole::ClientConsole(const char *ip, int port, std::string path)
{
    this->fm = new FileManager(path);
    this->fmc = new FileManagerClient();
}

ClientConsole::~ClientConsole()
{
    if (this->fmc)
    {
        delete this->fmc;
    }
}

void ClientConsole::listFiles()
{
    vector<string *> *vfiles = fmc->listFiles();
    cout << "Lista de ficheros del directorio remoto:\n";
    for (unsigned int i = 0; i < vfiles->size(); ++i)
    {
        cout << vfiles->at(i)->c_str() << endl;
    }

    fmc->freeListedFiles(vfiles);
}

void ClientConsole::upload(char *fileName)
{
    char *fileContent = nullptr;
    unsigned long fileLen = 0;

    // lee el fichero local para enviarlo. Si no existe el archivo lanza una excepción

    fm->readFile(fileName, fileContent, fileLen);

    fmc->writeFile(fileName, fileContent, fileLen);
}

void ClientConsole::download(char *fileName)
{
    char *fileContent = nullptr;
    unsigned long fileLen = 0;
    fmc->readFile(fileName, fileContent, fileLen);

    fm->writeFile(fileName, fileContent, fileLen);
}

void ClientConsole::executeCommand(int argc, char* argv[])
{
    //Comprueba que se hayan pasado un número válido de argumentos
    if (argc < 2 || argc > 3){
        std::cout << "`" << argc << "` no es un número válido de argumentos.\nUtilize --help para recibir ayuda.\n";

        return;
    }

    // ejecuta el comando que pida el usuario
    if((strcmp(argv[1], "-h")  == 0) || (strcmp(argv[1], "--help")  == 0)){
        std::cout << "Bienvenida a la consola para procesar archivos en remoto.\n";
        std::cout << "El Listado de comandos es:\n";
        std::cout << "`-h --help` para obtener la lista de comandos.\n";
        std::cout << "`-d --download filename` para descargar en el directorio local el archivo del servidor remoto.\n";
        std::cout << "`-u --upload filename` para subir un archivo local al directorio remoto.\n";
        std::cout << "`-l --list` para listar todos los archivos del directorio remoto.\n";
    }
    else if((strcmp(argv[1], "-d")  == 0) || (strcmp(argv[1], "--download")  == 0)){
        if(argc < 3){
            std::cout << "Por favor, ingrese un nombre de archivo para --download.\n";
            return;
        }

        download(argv[2]);
    }
    else if((strcmp(argv[1], "-u")  == 0) || (strcmp(argv[1], "--upload")  == 0)){
        if(argc < 3){
            std::cout << "Por favor, ingrese un nombre de archivo para --upload.\n";
            return;
        }

        upload(argv[2]);
    }
    else if((strcmp(argv[1], "-l")  == 0) || (strcmp(argv[1], "--list")  == 0)){
        listFiles();
    }
    else{
        std::cout << "`" << argv[1] << "` no es un comando válido.\nUtilize --help para recibir ayuda.\n";
    }
}