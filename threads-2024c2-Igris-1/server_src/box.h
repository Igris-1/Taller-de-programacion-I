#ifndef RED_BOX_H
#define RED_BOX_H

#include <string>

#include "../common_src/constants.h"

class Box {
private:
    // tiempo de respawn
    int respawn_time;

    // contador
    int counter;

    // nombre de la recompensa
    std::string reward;

    // true/false
    bool is_active;

public:
    Box(): respawn_time(INI), counter(INI), reward(EMPTY), is_active(true) {}

    // Devuelve la recompensa
    const std::string& get_reward();

    // Actualiza el tiempo de respawn
    bool update_respawn_time();

    // Desactiva la caja
    void deactivate();

    // Devuelve si la caja esta activa
    bool get_active();

    // Setea la caja
    void set_box(int respawn_time, int counter, const std::string& reward, bool is_active);
};
#endif
