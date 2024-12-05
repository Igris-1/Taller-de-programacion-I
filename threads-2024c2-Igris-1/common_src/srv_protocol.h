#ifndef SERVER_PROTOCOL_H
#define SERVER_PROTOCOL_H

#include <map>
#include <string>
#include <tuple>

#include "constants.h"
#include "protocol_base.h"
#include "socket.h"

class ServerProtocol: public ProtocolBase {
private:
    std::map<std::string, int> rewards;

public:
    ServerProtocol():
            rewards({{"Bazooka", 0x10},
                     {"Chainsaw", 0x11},
                     {"Death ray", 0x12},
                     {"Shotgun", 0x13}}) {}

    // Devuelve una tupla con el client_name y box_id
    std::tuple<std::string, int> receive_message(Socket& peer, bool& was_closed);

    // Envia actualizacion de caja abierta
    void send_open_box(Socket& peer, const std::string& name, const std::string& reward,
                       bool& was_closed);

    // Envia la actualizacion de cajas activas
    void send_active_box(Socket& peer, int active_boxes, bool& was_closed);
};

#endif  // SERVER_PROTOCOL_H
