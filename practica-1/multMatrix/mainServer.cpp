#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "utils.h"
#include "multmatrix_imp.h"

#define PORT 60001

void threadClient(int clientId) {
    multMatrix_imp* calc = multMatrix_imp(clientId);
    calc->recvOp();
    delete calc;
}

using namespace std;

int main(int argc, char** argv) {
    int serverId = initServer(PORT);

    while(1) {
        if(checkNewConnections()) {
            int clientId = getNewConnection();
            thread* th = new thread(threadClient, clientId);
            th->detach();
        }
        usleep(100);
    }
    close(serverId);
    return 0;
}