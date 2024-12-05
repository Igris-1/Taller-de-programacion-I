#ifndef ACCEPTOR_H
#define ACCEPTOR_H

#include <utility>

#include "../common_src/queue.h"
#include "../common_src/socket.h"
#include "../common_src/srv_protocol.h"
#include "../common_src/thread.h"

#include "command.h"
#include "monitor.h"

class Acceptor: public Thread {
private:
    Socket socket;
    ServerProtocol protocol;
    Monitor& client_list;
    Queue<Command>& game_q;

public:
    Acceptor(const char* srvname, Monitor& list, Queue<Command>& queue):
            socket(srvname), protocol(), client_list(list), game_q(queue) {}

    // Corre el acceptor
    void run() override;

    // Detiene el acceptor
    void stop() override;

    // Destructor
    ~Acceptor() override;
};

#endif
