#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "utils.h"
#include "filemanager.h"
#include "fileManagerClient.h"

class FileManagerServer{
    private:
        FileManager* fm = nullptr;
        int clientId = -1;

    public:
        FileManagerServer(int clientId, string path);
        ~FileManagerServer();

        void recvOp(); //recibir operacion
        void opReadFile();
        void opWriteFile();
        void opListDir();
};