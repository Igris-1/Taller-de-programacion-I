// client.h

#ifndef CLIENT_H
#define CLIENT_H

#include <string>

#include "../common_src/cli_protocol.h"

class Client {
private:
    // Client Protocol
    ClientProtocol protocol;

    // client name
    std::string client_name;

public:
    Client(const char* hostname, const char* srvname):
            protocol(hostname, srvname), client_name("") {}

    // Start client
    void start();

    // Set client name
    void set_client_name();

    // Read server response
    void read_response(ClientProtocol& cp, int id);
};

#endif
