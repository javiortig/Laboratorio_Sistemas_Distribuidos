#include "fileManagerClient.h"

//probando serialize: TODO borrar
void probarSerialize(){
    
    std::string hola("Hola que tal\n amigo\n");
    std::string hola2("Otro saludo pa ti\n");
    std::vector<string*> *v = new std::vector<string*>();
    std::string* serialized_string = nullptr;
    v->push_back(&hola);
    v->push_back(&hola2);

    serialized_string = serializeStringVector(v);
    std::cout << "Serialized:\n" << *serialized_string << "\n\n";


    std::vector<string*> *v_result = nullptr;
    std::cout << "Deserialize:\n";
    v_result = deserializeStringVector(serialized_string);
    for(auto it=v_result->begin();it!= v_result->end();++it)
    {
        std::cout << **it << "///";
    }
    std::cout << "\n";

    delete serialized_string;
    delete v_result;
}

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
