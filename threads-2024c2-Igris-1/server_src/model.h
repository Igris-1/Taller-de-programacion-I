#ifndef LOGIC_H
#define LOGIC_H

#include <map>
#include <string>

#include "box.h"

class Model {
private:
    std::map<int, Box> boxes;

public:
    Model(): boxes({{0x01, Box()}, {0x02, Box()}, {0x03, Box()}, {0x04, Box()}}) {}

    // Devuelve la recompensa de la caja
    std::string get_box(int box);

    // actualiza el estado de las cajas y devuelve la cantidad de cajas activadas
    int update_boxes();

    // setea las cajas
    // (respawn_time, counter, reward, id, is_active)
    void set_boxes();
};

#endif
