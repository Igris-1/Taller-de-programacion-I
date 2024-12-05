#include "receiver.h"

#include <string>
#include <tuple>
#include <utility>

#include "../common_src/liberror.h"

#include "command.h"

void Receiver::run() {
    while (_keep_running) {
        try {
            std::tuple<std::string, int> message = protocol.receive_message(peer, was_closed);

            if (was_closed || !_keep_running) {
                break;
            }

            push_message(message);
        } catch (const LibError& e) {
            std::cout << "LibError in receiver: " << e.what() << std::endl;
        } catch (const ClosedQueue& e) {
            std::cout << "ClosedQueue in receiver: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Receiver Error: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Unknown error receiver" << std::endl;
        }
    }
}

void Receiver::push_message(const std::tuple<std::string, int>& message) {
    Command command;
    command.set_client_name(std::get<0>(message));
    command.set_box_id(std::get<1>(message));
    game_q->push(std::move(command));
}
