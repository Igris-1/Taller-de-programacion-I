// client.cpp

#include "client.h"

#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include "../common_src/constants.h"
#include "../common_src/socket.h"

#include "client_protocol.h"

int Client::start() {
    try {
        int ret = ERROR;

        // Recieve welcome message
        std::cout << cp.welcome_message() << std::endl;

        // handle client messages
        char input[BUF_SIZE];
        while (not cp.get_was_closed()) {
            std::cin.getline(input, BUF_SIZE);

            if (input[INIT_POS] == QUIT_COMMAND) {
                break;
            } else if (input[INIT_POS] != BUY_COMMAND) {
                std::cerr << "Invalid command.\n";
                continue;
            }

            // Send message to server
            cp.send(input);

            if (cp.get_was_closed()) {
                std::cerr << "Connection closed by server.\n";
                break;
            }

            // Recibimos la respuesta del servidor
            recieve_model_status(cp);
        }


        ret = 0;
        return ret;
    } catch (const std::exception& err) {
        std::cerr << "Something went wrong and an exception was caught: " << err.what() << "\n";
        return ERROR;
    } catch (...) {
        std::cerr << "Something went wrong and an unknown exception was caught.\n";
        return ERROR;
    }
}


void Client::recieve_model_status(ClientProtocol& cp) {
    std::cout << "Primary Weapon: " << cp.get_weapon() << " | Ammo: " << cp.get_ammo() << std::endl;

    std::cout << "Secondary Weapon: " << cp.get_weapon() << " | Ammo: " << cp.get_ammo()
              << std::endl;

    std::cout << "Knife Equipped: " << cp.get_knife() << std::endl;

    std::cout << std::endl;
}
