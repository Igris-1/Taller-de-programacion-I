// main.cpp

#include <iostream>
#include <string>

#include "../common_src/constants.h"

#include "client.h"


int main(int argc, const char* argv[]) {
    int ret = INI;

    const char* hostname = nullptr;
    const char* servname = nullptr;

    if (argc == CLI_ARGUMENTS) {
        hostname = argv[HOSTNAME];  // IP
        servname = argv[SERVNAME];  // Puerto
    } else {
        std::cerr << "Bad program call. Expected " << argv[INIT_POS] << " <IP> <PORT>\n";
    }

    Client client(hostname, servname);

    try {
        client.start();
    } catch (const std::exception& err) {
        std::cerr << "Main client error: " << err.what() << "\n";
        return ERROR;
    } catch (...) {
        std::cerr << "Main client error: unknown exception.\n";
        return ERROR;
    }
    return ret;
}
