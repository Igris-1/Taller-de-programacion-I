// server_protocol.cpp


#include "server_protocol.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <iostream>
#include <new>
#include <vector>

#include <string.h>

#include "../common_src/constants.h"
#include "arpa/inet.h"


std::string ServerProtocol::receive_message(Socket& peer, bool& was_closed) {
    std::string message;
    char buffer[MAX_BYTES_SRV];

    while (!was_closed && peer.recvall(buffer, MAX_BYTES_SRV, &was_closed)) {
        if (buffer[INIT_POS] == ' ' || buffer[INIT_POS] == BUY_COMMAND) {
            continue;
        }

        if (buffer[INIT_POS] == '\0') {
            break;
        }
        message.push_back(buffer[INIT_POS]);
    }
    return message;
}

void ServerProtocol::send_wm(Socket& peer, const std::string& str, bool& was_closed) {
    send_weapon(peer, str, was_closed);
}

void ServerProtocol::send_weapon(Socket& peer, const std::string& str, bool& was_closed) {
    uint16_t message = htons(str.size());
    peer.sendall(&message, sizeof(message), &was_closed);
    peer.sendall(str.data(), str.size(), &was_closed);
}

void ServerProtocol::send_ammo(Socket& peer, int num, bool& was_closed) {
    uint_fast8_t ammo = num;
    peer.sendall(&ammo, sizeof(ammo), &was_closed);
}

void ServerProtocol::send_knife(Socket& peer, bool knife, bool& was_closed) {
    send_ammo(peer, knife, was_closed);
}
