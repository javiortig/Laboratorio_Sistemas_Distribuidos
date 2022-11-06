#pragma once

#include "fileManagerClient.h"
#define DIR_PATH "./dirprueba"

class ClientConsole{
    private:
    FileManagerClient* fmc = nullptr;
    FileManager* fm = nullptr;

    public:
    // Lista los archivos del directorio remoto
    void listFiles();

    //sube un archivo del directorio local al remoto
    void upload(char* fileName);

    //Descarga un archivo en remoto al directorio local
    void download(char* fileName);

    //muestra una ayuda en la consola de los comandos disponibles
    void help();

    // funcion principal de la clase. Ejecuta alguna de las funciones anteriores según
    // los parámetros dados por el usuario
    void executeCommand(int argc, char* argv[]);

    ClientConsole(const char* ip = SERVER_IP, int port = PORT, std::string path = DIR_PATH);
    ~ClientConsole();
};