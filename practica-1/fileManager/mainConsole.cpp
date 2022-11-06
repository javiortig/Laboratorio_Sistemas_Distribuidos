#include "clientConsole.h"


int main(int argc, char* argv[]){

    ClientConsole console;

    console.executeCommand(argc, argv);

    return 0;
}