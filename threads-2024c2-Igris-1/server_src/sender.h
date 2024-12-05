#ifndef SENDER_H
#define SENDER_H

#include "../common_src/constants.h"
#include "../common_src/queue.h"
#include "../common_src/socket.h"
#include "../common_src/srv_protocol.h"
#include "../common_src/thread.h"

#include "command.h"

class Sender: public Thread {
private:
    Socket& peer;
    ServerProtocol& protocol;
    bool was_closed;
    Queue<Command> sender_queue;

public:
    Sender(Socket& socket, ServerProtocol& protocol):
            peer(socket), protocol(protocol), was_closed(false), sender_queue(QUEUE_LIMIT) {}

    // Corre el sender
    void run() override;

    // Para el sender
    void stop() override;

    // Devuelve la cola del sender
    Queue<Command>& get_queue();
};

#endif
