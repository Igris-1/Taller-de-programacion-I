// server.h

#ifndef SERVER_H
#define SERVER_H

#include <string>

#include "../common_src/socket.h"

#include "model.h"
#include "server_protocol.h"

class Server {
private:
    // Server Protocol
    ServerProtocol sp;

    // Server Socket
    Socket srv;

    // Was closed
    bool was_closed;

    // Game Model
    Model model;

    // Welcome message
    std::string wm;

public:
    explicit Server(const char* srvname):
            sp(), srv(srvname), was_closed(false), model(), wm("What arya buying?") {}

    // run server
    int start();

    // Send model status
    void send_model_status(ServerProtocol sp, Socket& peer, Model& model, bool& was_closed);
};

#endif
