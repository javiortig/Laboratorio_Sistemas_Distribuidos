#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "utils.h"
#include "filemanager.h"
#include "fileManagerClient.h"

//Cambiar el path según la ubicación del archivo público.
#define PORT 30001
#define DIR_PATH "./dirprueba"

class FileManagerServer{
    private:
        FileManager* fm = nullptr;
        int clientId = -1;

    public:
        FileManagerServer(int clientId, string path);
        ~FileManagerServer();

        void recvOp(); 
        void opReadFile();
        void opWriteFile();
        void opListDir();
};