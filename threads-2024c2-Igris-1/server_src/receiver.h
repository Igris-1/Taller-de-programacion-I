#ifndef RECEIVER_H
#define RECEIVER_H

#include <string>
#include <tuple>

#include "../common_src/queue.h"
#include "../common_src/socket.h"
#include "../common_src/srv_protocol.h"
#include "../common_src/thread.h"

#include "command.h"

class Receiver: public Thread {
private:
    Socket& peer;
    ServerProtocol& protocol;
    Queue<Command>* game_q;
    bool was_closed;

public:
    Receiver(Socket& peer, ServerProtocol& protocol, Queue<Command>* queue):
            peer(peer), protocol(protocol), game_q(queue), was_closed(false) {}

    // Corre el receiver
    void run() override;
    void push_message(const std::tuple<std::string, int>& message);
};

#endif
