#include <iostream>
#include "fileManagerClient.h"

/*
    Main homólogo al entregado en el enunciado. Solo cambia la clase FileManager
    por FileManagerClient, para poder ejecutarlo en remoto.
*/

int main(int argc,char** argv)
{
    FileManagerClient *fm=new FileManagerClient();
    vector<string*>* vfiles=fm->listFiles();
    cout<<"Lista de ficheros en el directorio de prueba:\n";
    for(unsigned int i=0;i<vfiles->size();++i)
    {
        cout<<"Fichero: "<<vfiles->at(i)->c_str()<<endl;
    }
    cout<<"Leyendo el primer fichero del directorio de prueba\n";

    char* data=nullptr;
    unsigned long int fileLen=0;
    fm->readFile(&(*(vfiles->at(1)))[0],data,fileLen);
    cout<<"Escribiendo en el primer fichero del directorio de prueba el segundo\n";
    fm->writeFile(&(*(vfiles->at(0)))[0],data,fileLen);
    cout<<"Liberando lista de ficheros\n";
    fm->freeListedFiles(vfiles);
    cout<<"Liberando datos de fichero leído\n";

    delete[] data;
    return 0;
}
