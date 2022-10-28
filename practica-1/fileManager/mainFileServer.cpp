#include "fileManagerServer.h"

// El core es la clase holamundo, los RPCs son las implementaciones en los
// sistemas distribuidos que llaman al core
#define PORT 30001

void threadClient(int clientId){

    FileManagerServer* fms = new FileManagerServer(clientId, std::string("/home/ubuntu/practica_1/fileManager/dirprueba"));
    fms->recvOp();
    delete fms;
}

int main(int argc,char** argv)
{
    int serverId = initServer(PORT);
    
    while(1){

        if(checkNewConnections()){
            int clientId = getNewConnection();
            std::thread* th= new std::thread(threadClient, clientId);
            //th->detach();
        }

        usleep(100);
    }

    close(serverId);
    return 0;
}
