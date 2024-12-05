#include "server.h"

#include <string>

void Server::run() {
    acceptor.start();
    game_loop.start();

    std::string shutdown;
    std::getline(std::cin, shutdown);

    while (shutdown != SHUTDOWN_COMMAND) {
        std::getline(std::cin, shutdown);
    }

    acceptor.stop();
    game_loop.stop();
    acceptor.join();
    game_loop.join();
}
