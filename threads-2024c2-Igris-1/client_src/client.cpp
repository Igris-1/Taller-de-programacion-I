// client.cpp

#include "client.h"

#include <iostream>
#include <sstream>
#include <string>

#include "../common_src/constants.h"

void Client::start() {
    set_client_name();

    while (not protocol.get_was_closed()) {
        std::string input;
        std::getline(std::cin, input);

        std::istringstream ss(input);
        std::string command;
        int id;

        ss >> command >> id;

        if (command == QUIT_COMMAND) {
            break;
        } else if (command != PICK_COMMAND && command != READ_COMMAND) {
            std::cerr << "Invalid command.\n";
            continue;
        } else if (command == PICK_COMMAND) {
            protocol.send_pickup(client_name, id);

        } else if (command == READ_COMMAND) {
            read_response(protocol, id);
        }

        if (protocol.get_was_closed()) {
            std::cerr << "Connection closed by server.\n";
            break;
        }
    }
}

void Client::set_client_name() {
    std::cout << "What is your name?\n";
    std::string name;
    std::getline(std::cin, name);
    client_name = name;
}

void Client::read_response(ClientProtocol& protocol, int id) {
    for (int i = 0; i < id; i++) {
        std::string response = protocol.read();
        if (response != EMPTY) {
            std::cout << response << std::endl;
        }
    }
}
