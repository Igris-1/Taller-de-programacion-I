#include "command.h"

#include <string>

#include "../common_src/constants.h"


const std::string& Command::get_client_name() const { return client_name; }

int Command::get_command_id() const { return command_id; }

int Command::get_box_id() const { return box_id; }

const std::string& Command::get_reward_name() const { return reward_name; }

int Command::get_box_activated() const { return box_activated; }

void Command::set_client_name(const std::string& client_name) { this->client_name = client_name; }

void Command::set_command_id(int command_id) { this->command_id = command_id; }

void Command::set_box_id(int box_id) { this->box_id = box_id; }

void Command::set_reward_name(const std::string& reward_name) { this->reward_name = reward_name; }

void Command::set_box_activated(int box_activated) { this->box_activated = box_activated; }

Command Command::clone() {
    Command command;
    command.set_client_name(client_name);
    command.set_command_id(command_id);
    command.set_box_id(box_id);
    command.set_reward_name(reward_name);
    command.set_box_activated(box_activated);
    return command;
}
