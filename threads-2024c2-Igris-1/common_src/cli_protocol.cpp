#include "cli_protocol.h"

#include <string>

#include "constants.h"

bool ClientProtocol::get_was_closed() { return was_closed; }

void ClientProtocol::send_pickup(const std::string& client_name, int id) {
    send_byte(socket, USER_COMMAND, was_closed);
    send_string(socket, client_name, was_closed);
    send_byte(socket, id, was_closed);
}

std::string ClientProtocol::read() {
    int first_byte = receive_byte(socket, was_closed);

    if (first_byte == SERVER_COMMAND) {
        int second_byte = receive_byte(socket, was_closed);

        if (second_byte == OPEN_BOX) {
            std::string name = receive_string(socket, was_closed);
            std::string reward = rewards[receive_byte(socket, was_closed)];
            return name + " picked up a " + reward;
        } else if (second_byte == RESPAWN_BOX) {
            return "A new box has appeared";
        }
    }
    return EMPTY;
}
