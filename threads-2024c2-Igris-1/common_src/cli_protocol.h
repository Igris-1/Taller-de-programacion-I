#ifndef CLIENT_PROTOCOL_H
#define CLIENT_PROTOCOL_H

#include <map>
#include <string>

#include "constants.h"
#include "protocol_base.h"
#include "socket.h"

class ClientProtocol: public ProtocolBase {
private:
    Socket socket;
    bool was_closed;

    // Reward map
    std::map<int, std::string> rewards;

public:
    ClientProtocol(const char* hostname, const char* servname):
            socket(hostname, servname),
            was_closed(false),
            rewards({{0x10, "Bazooka"},
                     {0x11, "Chainsaw"},
                     {0x12, "Death ray"},
                     {0x13, "Shotgun"}}) {}

    // Devuelve si el servidor cerro la conexion
    bool get_was_closed();

    // Envia el comando de pickup
    void send_pickup(const std::string& client_name, int id);

    // Lee la respuesta del servidor
    std::string read();
};

#endif  // CLIENT_PROTOCOL_H
