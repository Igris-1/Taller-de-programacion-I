// client.h

#ifndef CLIENT_H
#define CLIENT_H

#include "client_protocol.h"

class Client {
private:
    // Client Protocol
    ClientProtocol cp;

public:
    Client(const char* hostname, const char* srvname): cp(hostname, srvname) {}

    // run client
    int start();

    // Recieve model status from server
    void recieve_model_status(ClientProtocol& cp);
};

#endif
