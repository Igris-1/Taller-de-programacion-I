#ifndef SERVER_H
#define SERVER_H

#include "../common_src/queue.h"

#include "acceptor.h"
#include "client.h"
#include "gameloop.h"
#include "monitor.h"

class Server {
private:
    // Client list monitor
    Monitor client_list;

    // main game queue
    Queue<Command> main_queue;

    // acceptor
    Acceptor acceptor;

    // game loop
    GameLoop game_loop;


public:
    explicit Server(const char* srvname):
            client_list(),
            main_queue(QUEUE_LIMIT),
            acceptor(srvname, client_list, main_queue),
            game_loop(client_list, main_queue) {}

    // run server
    void run();
};

#endif
