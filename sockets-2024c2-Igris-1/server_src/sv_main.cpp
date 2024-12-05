// main.cpp

#include <iostream>

#include "../common_src/constants.h"

#include "server.h"


int main(int argc, const char* argv[]) {
    int ret = ERROR;

    // Port
    const char* port = nullptr;

    if (argc == SRV_ARGUMENTS) {
        port = argv[HOSTNAME];
    } else {
        std::cerr << "Bad program call. Expected " << argv[INIT_POS] << " <port>\n";
        return ret;
    }

    // Levantamos el server
    Server srv(port);

    // Corremos el server
    ret = srv.start();

    return ret;
}
