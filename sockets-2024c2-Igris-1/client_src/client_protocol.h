// client_protocol.h

#ifndef CLIENT_PROTOCOL_H
#define CLIENT_PROTOCOL_H

#include <string>
#include <vector>

#include "../common_src/socket.h"

class ClientProtocol {
private:
    // ClientProtocol Socket
    Socket cli;

    // Was closed
    bool was_closed;

public:
    ClientProtocol(const char* hostname, const char* servname):
            cli(hostname, servname), was_closed(false) {}

    // welcome message del server
    std::string welcome_message();

    // getter de was_closed
    bool get_was_closed();

    // funcion que maneja el envio de mensajes del cliente
    void send(const std::string& input);

    // getter de weapon
    std::string get_weapon();

    // getter de ammo
    int get_ammo();

    // getter de knife
    std::string get_knife();
};

#endif
