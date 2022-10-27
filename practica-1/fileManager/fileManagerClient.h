#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>

#include "utils.h"

#define OP_END 0
#define OP_READ_FILE 1
#define OP_WRITE_FILE 2

//Cambiar estos dos parametros segun la configuracion de la máquina
#define PORT 30001  
#define SERVER_IP "52.6.23.84"

class FileManagerClient{
    private:
    int serverId = -1;

    public:
    FileManagerClient(char* ip = SERVER_IP, int port = PORT);
    //TODO: asegurar si debe escribir el a rchivo en el cliente o devolverlo en la funcion como un char*
    void readFile(char* fileName);
};
