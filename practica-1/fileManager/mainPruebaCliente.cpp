#include "fileManagerClient.h"

/*
    Un Main para probar en mayor profundidad las funcionalidades de la 
    aplicación distribuida.
*/
int main(int argc,char** argv)
{
    std::cout << "Traza0\n";
    FileManagerClient* fmc = new FileManagerClient();

    std::cout << "Traza1\n";
    //Probamos a obtener los directorios
    vector<string*>* vfiles = fmc->listFiles();
    

    std::cout << "Traza2\n";
    //leer archivo del servidor
    char nombre_leer[] = "prueba1.txt";
    char *buffer = nullptr;
    unsigned long bufferLen = -1;
    fmc->readFile(nombre_leer, buffer, bufferLen);
    std::cout << buffer << endl;

    std::cout << "Traza3\n";
    //probamos a escribir datos en el directorio escribir.txt del server
    char* nombre_escribir = "escribir.txt";
    char *bufferB = "Escribo desde el cliente";
    fmc->writeFile(nombre_escribir, bufferB, strlen(buffer));

    std::cout << "TrazaExit\n";
    return 0;
}
