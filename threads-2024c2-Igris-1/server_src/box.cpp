
#include "box.h"

#include <string>

#include "../common_src/constants.h"


const std::string& Box::get_reward() { return reward; }

bool Box::update_respawn_time() {
    if (!is_active) {
        counter++;
        if (counter == respawn_time) {
            is_active = true;
            counter = INI;
            return true;
        }
    }
    return false;
}

void Box::deactivate() { is_active = false; }

bool Box::get_active() { return is_active; }

void Box::set_box(int respawn_time, int counter, const std::string& reward, bool is_active) {
    this->respawn_time = respawn_time;
    this->counter = counter;
    this->reward = reward;
    this->is_active = is_active;
}
