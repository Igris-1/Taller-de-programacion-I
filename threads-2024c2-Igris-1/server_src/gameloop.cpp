#include "gameloop.h"

#include <string>

#include <unistd.h>

#include "../common_src/constants.h"

#include "command.h"

void GameLoop::run() {
    model.set_boxes();

    while (_keep_running) {
        try {
            Command command;
            while (main_queue.try_pop(command)) {
                update_model(command);
            }

            int active_boxes = model.update_boxes();
            if (active_boxes) {
                print_active_boxes(active_boxes);
                active_box(active_boxes);
            }
            usleep(SLEEP_TIME);
        } catch (const std::exception& e) {
            std::cerr << "Error al actualizar el modelo: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Error desconocido al actualizar el modelo." << std::endl;
        }
    }
}

void GameLoop::update_model(const Command& command) {
    std::string reward = model.get_box(command.get_box_id());

    if (reward != EMPTY) {
        std::string client_name = command.get_client_name();
        print_open_box(client_name, reward);
        make_command(client_name, reward);
    }
}

void GameLoop::make_command(const std::string& client_name, const std::string& reward) {
    Command command;
    command.set_client_name(client_name);
    command.set_command_id(SERVER_COMMAND);
    command.set_reward_name(reward);
    client_monitor.push_message(command);
}

void GameLoop::active_box(int active_boxes) {
    Command command;
    command.set_command_id(INI);
    command.set_box_activated(active_boxes);
    client_monitor.push_message(command);
}

void GameLoop::print_open_box(const std::string& client_name, const std::string& reward) {
    std::cout << client_name << " picked up a " << reward << std::endl;
}

void GameLoop::print_active_boxes(int active_boxes) {
    for (int i = 0; i < active_boxes; i++) {
        std::cout << "A new box has appeared" << std::endl;
    }
}
