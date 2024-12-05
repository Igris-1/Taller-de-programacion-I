// main.cpp

#include <iostream>

#include "../common_src/constants.h"

#include "server.h"

int main(int argc, const char* argv[]) {
    int ret = INI;

    const char* port = nullptr;

    if (argc == SRV_ARGUMENTS) {
        port = argv[HOSTNAME];
    } else {
        std::cerr << "Bad program call. Expected " << argv[INIT_POS] << " <port>\n";
        return ret;
    }

    Server server(port);

    try {
        server.run();

        return ret;
    } catch (const std::exception& e) {
        std::cerr << "Server Main Error: " << e.what() << std::endl;
        return ERROR;
    } catch (...) {
        std::cerr << "Unknown error server" << std::endl;
        return ERROR;
    }
}
