// server.cpp

#include "server.h"

#include <cstdint>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include "../common_src/constants.h"
#include "../common_src/socket.h"
#include "arpa/inet.h"

#include "model.h"
#include "server_protocol.h"

int Server::start() {
    try {
        int ret = ERROR;

        // Aceptamos una conexion
        Socket peer = srv.accept();

        // send welcome message
        sp.send_wm(peer, wm, was_closed);

        while (!was_closed) {
            // Recibimos los comandos del cliente
            std::string commands = sp.receive_message(peer, was_closed);

            if (commands == "") {
                continue;
            }

            // Ejecutamos los comandos
            model.command(commands);

            // Enviamos el estado del modelo
            send_model_status(sp, peer, model, was_closed);
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

void Server::send_model_status(ServerProtocol sp, Socket& peer, Model& model, bool& was_closed) {
    sp.send_weapon(peer, model.getNamePrimaryWeapon(), was_closed);
    sp.send_ammo(peer, model.getAmmoPrimaryWeapon(), was_closed);
    sp.send_weapon(peer, model.getNameSecondaryWeapon(), was_closed);
    sp.send_ammo(peer, model.getAmmoSecondaryWeapon(), was_closed);
    sp.send_knife(peer, model.getKnifeEquipped(), was_closed);
}
