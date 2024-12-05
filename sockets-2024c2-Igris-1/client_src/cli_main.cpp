// main.cpp

#include <iostream>
#include <string>

#include "../common_src/constants.h"

#include "client.h"


int main(int argc, const char* argv[]) {
    int ret = ERROR;

    const char* hostname = nullptr;
    const char* servname = nullptr;

    if (argc == CLI_ARGUMENTS) {
        hostname = argv[HOSTNAME];  // IP
        servname = argv[SERVNAME];  // Puerto
    } else {
        std::cerr << "Bad program call. Expected " << argv[INIT_POS] << " <IP> <PORT>\n";
    }

    // Levantamos el client
    Client client(hostname, servname);

    // Corremos el client
    ret = client.start();

    return ret;
}
