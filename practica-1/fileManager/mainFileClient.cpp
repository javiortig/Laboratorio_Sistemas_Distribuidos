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
    FileManagerClient* fmc = nullptr;

    //Probamos a listar los directorios
    fmc = new FileManagerClient();
    fmc->listDir();
    usleep(1);
    delete fmc;

    //Probamos a listar los directorios
    fmc = new FileManagerClient();
    fmc->listDir();
    usleep(1);
    delete fmc;

    //Probamos a listar los directorios
    fmc = new FileManagerClient();
    fmc->listDir();
    usleep(1);
    delete fmc;

    //leer archivo del servidor
    fmc = new FileManagerClient();
    std::string nombre_leer("leer1.txt");
    fmc->readFile(nombre_leer);
    delete fmc; 

    fmc = new FileManagerClient();
    //probamos a escribir datos en el directorio escribir.txt del server
    std::string nombre_escribir("escribir.txt");
    std::string datos("esto deberia de escribirse.\nEsperemos que sea así.");
    fmc->writeFile(nombre_escribir, datos, datos.length());
    delete fmc;


    return 0;
}
