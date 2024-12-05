// server_protocol.h

#ifndef SERVER_PROTOCOL_H
#define SERVER_PROTOCOL_H

#include <string>

#include "../common_src/socket.h"

#include "model.h"

class ServerProtocol {
public:
    bool was_closed;

    ServerProtocol(): was_closed(false) {}

    // Devuelve el mensaje del cliente o un string vacio si no hay mensaje
    std::string receive_message(Socket& peer, bool& was_closed);

    // Send Welcome Message
    void send_wm(Socket& peer, const std::string& str, bool& was_closed);

    // Send weapon name
    void send_weapon(Socket& peer, const std::string& str, bool& was_closed);

    // Send weapon ammo
    void send_ammo(Socket& peer, int num, bool& was_closed);

    // Send knife equipped
    void send_knife(Socket& peer, bool knife, bool& was_closed);
};
#endif
