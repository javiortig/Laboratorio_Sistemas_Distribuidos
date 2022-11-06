#include "fileManagerServer.h"

// El core es la clase holamundo, los RPCs son las implementaciones en los
// sistemas distribuidos que llaman al core

void threadClient(int clientId){

    FileManagerServer* fms = new FileManagerServer(clientId, std::string(DIR_PATH));
    fms->recvOp();
    delete fms;
}

int main(int argc,char** argv)
{
    int serverId = initServer(PORT);

    std::cout << "Servidor iniciado\n";
    
    while(1){

        if(checkNewConnections()){
            int clientId = getNewConnection();
            std::cout << "Nueva conexion de: " << clientId << std::endl;

            std::thread* th= new std::thread(threadClient, clientId);
            //th->detach();
        }

        usleep(100);
    }

    close(serverId);
    return 0;
}
