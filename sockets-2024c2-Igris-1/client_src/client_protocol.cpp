#include "client_protocol.h"

#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include <string.h>

#include "../common_src/constants.h"
#include "arpa/inet.h"

std::string ClientProtocol::welcome_message() { return get_weapon(); }

bool ClientProtocol::get_was_closed() { return was_closed; }

void ClientProtocol::send(const std::string& input) {
    cli.sendall(input.c_str(), input.length() + 1, &was_closed);
}

std::string ClientProtocol::get_weapon() {
    uint16_t buf2;
    cli.recvall(&buf2, MAX_BYTES, &was_closed);

    size_t message_size = ntohs(buf2);
    std::vector<char> buf(message_size);

    cli.recvall(buf.data(), message_size, &was_closed);
    std::string result(buf.begin(), buf.end());

    return result;
}

int ClientProtocol::get_ammo() {
    uint8_t ammo;
    cli.recvall(&ammo, sizeof(ammo), &was_closed);
    return int(ammo);
}

std::string ClientProtocol::get_knife() {
    uint8_t knife;
    cli.recvall(&knife, sizeof(knife), &was_closed);
    return (knife == EQUIPPED ? "Yes" : "No");
}
