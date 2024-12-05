#include "srv_protocol.h"

#include <string>
#include <tuple>

#include "constants.h"
#include "socket.h"


std::tuple<std::string, int> ServerProtocol::receive_message(Socket& peer, bool& was_closed) {
    int first_byte = receive_byte(peer, was_closed);

    if (first_byte == USER_COMMAND) {
        std::tuple<std::string, int> response;

        std::get<INIT_POS>(response) = receive_string(peer, was_closed);
        std::get<SECOND_POS>(response) = receive_byte(peer, was_closed);
        return response;
    } else {
        return {EMPTY, INI};
    }
}

void ServerProtocol::send_open_box(Socket& peer, const std::string& name, const std::string& reward,
                                   bool& was_closed) {
    send_byte(peer, SERVER_COMMAND, was_closed);
    send_byte(peer, OPEN_BOX, was_closed);
    send_string(peer, name, was_closed);
    send_byte(peer, rewards[reward], was_closed);
}

void ServerProtocol::send_active_box(Socket& peer, int active_boxes, bool& was_closed) {
    for (int i = 0; i < active_boxes; i++) {
        send_byte(peer, SERVER_COMMAND, was_closed);
        send_byte(peer, RESPAWN_BOX, was_closed);
    }
}
// SERVER_PROTOCOL_H
