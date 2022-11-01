#pragma once

#include "utils.h"
#include "serialize.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>

#define OP_READ_FILE 1
#define OP_WRITE_FILE 2
#define OP_LIST_DIR 3

//Cambiar estos dos parametros segun la configuracion de la máquina
// #define PORT 30001  
// #define SERVER_IP "52.6.23.84"
#define PORT 30001
#define SERVER_IP "127.0.0.1"

class FileManagerClient{
    private:
    int serverId = -1;

    public:
    FileManagerClient(char* ip = SERVER_IP, int port = PORT);
    //TODO: asegurar si debe escribir el a rchivo en el cliente o devolverlo en la funcion como un char*
    void readFile(std::string& fileName);

    void writeFile(std::string &fileName, std::string &data, unsigned long dataLength);
    void listDir();
};
