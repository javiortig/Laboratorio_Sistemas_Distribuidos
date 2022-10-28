#include "fileManagerClient.h"

// El core es la clase holamundo, los RPCs son las implementaciones en los
// sistemas distribuidos que llaman al core

int main(int argc,char** argv)
{

    FileManagerClient* fmc = new FileManagerClient();
    
    fmc->readFile("prueba1.txt");   

    delete fmc;
    
    return 0;
}
