#ifndef SRV_CLIENT_H
#define SRV_CLIENT_H

#include <utility>

#include "../common_src/queue.h"
#include "../common_src/socket.h"

#include "command.h"
#include "receiver.h"
#include "sender.h"

class Client {
private:
    Socket peer;
    Receiver receiver;
    Sender sender;

public:
    Client(Socket& socket, ServerProtocol& protocol, Queue<Command>* game_queue):
            peer(std::move(socket)), receiver(peer, protocol, game_queue), sender(peer, protocol) {}

    // Corre el cliente
    void run();

    // Detiene el cliente
    void stop();

    // Espera a que el cliente termine
    void join();

    // Devuelve la queue del cliente
    Queue<Command>& get_queue();

    // Devuelve si el cliente esta vivos
    bool is_alive() const;

    // No quiero que se copie
    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;

    // No quiero que se mueva
    Client(Client&&) = delete;
    Client& operator=(Client&&) = delete;
};

#endif
