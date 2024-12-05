#include "model.h"

#include <string>

#include "../common_src/constants.h"

#include "box.h"

std::string Model::get_box(int box_id) {
    if (boxes[box_id].get_active()) {
        Box& box = boxes[box_id];
        std::string reward = box.get_reward();

        boxes[box_id].deactivate();
        return reward;
    }
    return EMPTY;
}

int Model::update_boxes() {
    int activated = INI;
    for (auto& box: boxes) {
        if (box.second.update_respawn_time()) {
            activated++;
        }
    }
    return activated;
}

void Model::set_boxes() {
    // (respawn_time, counter, reward name, is_active)
    boxes[0x01].set_box(15, 0, "Bazooka", true);
    boxes[0x02].set_box(5, 0, "Chainsaw", true);
    boxes[0x03].set_box(20, 0, "Death ray", true);
    boxes[0x04].set_box(10, 0, "Shotgun", true);
}
