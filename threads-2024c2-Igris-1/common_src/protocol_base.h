#ifndef PROTOCOL_BASE_H
#define PROTOCOL_BASE_H

#include <string>
#include <vector>

#include "arpa/inet.h"

#include "socket.h"

class ProtocolBase {
protected:
    void send_string(Socket& socket, const std::string& str, bool& was_closed) {
        uint16_t message = htons(str.size());
        socket.sendall(&message, sizeof(message), &was_closed);
        socket.sendall(str.data(), str.size(), &was_closed);
    }

    void send_byte(Socket& socket, int num, bool& was_closed) {
        uint8_t byte = num;
        socket.sendall(&byte, sizeof(byte), &was_closed);
    }

    std::string receive_string(Socket& socket, bool& was_closed) {
        uint16_t buf2;
        socket.recvall(&buf2, sizeof(buf2), &was_closed);

        size_t message_size = ntohs(buf2);
        std::vector<char> buf(message_size);

        socket.recvall(buf.data(), message_size, &was_closed);
        return std::string(buf.begin(), buf.end());
    }

    int receive_byte(Socket& socket, bool& was_closed) {
        uint8_t id;
        socket.recvall(&id, sizeof(id), &was_closed);
        return int(id);
    }
};

#endif  // PROTOCOL_BASE_H
