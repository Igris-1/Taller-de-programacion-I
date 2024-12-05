#ifndef MONITOR_H
#define MONITOR_H

#include <list>

#include "client.h"

class Monitor {
private:
    // client list
    std::list<Client> client_list;

    // client list mutex
    std::mutex mutex;

    // Remove dead clients from list
    void reap_dead();

public:
    Monitor(): client_list(), mutex() {}

    // build a client and add it to the list
    void add_client(Socket& socket, ServerProtocol& protocol, Queue<Command>* queue);

    // push a message to all clients
    void push_message(Command command);

    // shutdown all clients
    void kill();
};

#endif  // MONITOR_H
