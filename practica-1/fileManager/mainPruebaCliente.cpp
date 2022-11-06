#include "fileManagerClient.h"

/*
    Un Main para probar en mayor profundidad las funcionalidades de la 
    aplicación distribuida.
*/
int main(int argc,char** argv)
{
    FileManagerClient* fmc = new FileManagerClient();

    //Probamos a listar los directorios
    fmc->listFiles();
    usleep(1);

    //leer archivo del servidor
    char nombre_leer[] = "leer1.txt";
    char *buffer = nullptr;
    unsigned long bufferLen = -1;
    fmc->readFile(nombre_leer, buffer, bufferLen);
    std::cout << buffer << endl;

    //probamos a escribir datos en el directorio escribir.txt del server
    char* nombre_escribir = "escribir.txt";
    char *bufferB = "Escribo desde el cliente";
    fmc->writeFile(nombre_escribir, bufferB, strlen(buffer));


    return 0;
}
