#include "acceptor.h"

#include <iostream>

#include "../common_src/liberror.h"
#include "../common_src/socket.h"

void Acceptor::run() {
    try {
        while (_keep_running) {
            Socket peer = socket.accept();
            client_list.add_client(peer, protocol, &game_q);
        }
    } catch (const LibError& e) {
        if (_keep_running) {
            std::cerr << "AcceptorError: " << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "AcceptorError: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error acceptor" << std::endl;
    }
}

void Acceptor::stop() {
    _keep_running = false;
    socket.shutdown(SHUT_RDWR);
    socket.close();
}

Acceptor::~Acceptor() { client_list.kill(); }
