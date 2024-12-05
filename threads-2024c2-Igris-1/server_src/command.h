#ifndef COMMAND_H
#define COMMAND_H

#include <string>

#include "../common_src/constants.h"

// Object data transfer class
class Command {
private:
    std::string client_name;

    // 0x03 0x06
    int command_id;

    // 0x01 0x02 0x03 0x04
    int box_id;

    // name of the reward
    std::string reward_name;

    // cantidad de cajas activadas
    int box_activated;

public:
    Command():
            client_name(EMPTY),
            command_id(INI),
            box_id(INI),
            reward_name(EMPTY),
            box_activated(INI) {}

    // Devuelve el nombre del cliente
    const std::string& get_client_name() const;

    // Devuelve si es 0x03 o 0x06
    int get_command_id() const;

    // Devuelve el id de la caja 0x01 0x02 0x03 0x04
    int get_box_id() const;

    // Devuelve el nombre del reward
    const std::string& get_reward_name() const;

    // Devuelve la cantidad de cajas activadas 0x05
    int get_box_activated() const;

    // Setea el nombre del cliente
    void set_client_name(const std::string& client_name);

    // Setea el id del comando 0x03 0x06
    void set_command_id(int command_id);

    // Setea el id de la caja 0x01 0x02 0x03 0x04
    void set_box_id(int box_id);

    // Setea el nombre del reward
    void set_reward_name(const std::string& reward_name);

    // Setea si la caja fue activada 0x05
    void set_box_activated(int box_activated);

    // Clona el comando
    Command clone();

    // Quiero que se copie
    Command(const Command&) = default;
    Command& operator=(const Command&) = default;

    // Quiero que se mueva
    Command(Command&&) = default;
    Command& operator=(Command&&) = default;
};

#endif  // COMMAND_H
