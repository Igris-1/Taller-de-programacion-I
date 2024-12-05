
#include "sender.h"

#include <string>

#include "../common_src/constants.h"
#include "../common_src/liberror.h"

#include "command.h"

void Sender::run() {
    while (_keep_running) {
        try {
            Command command = sender_queue.pop();
            int active_boxes = command.get_box_activated();

            if (active_boxes) {
                protocol.send_active_box(peer, active_boxes, was_closed);
            } else {
                std::string client_name = command.get_client_name();
                std::string reward_name = command.get_reward_name();
                protocol.send_open_box(peer, client_name, reward_name, was_closed);
            }

            if (was_closed || !_keep_running) {
                break;
            }

        } catch (const LibError& e) {
            std::cerr << "LibError in sender: " << e.what() << std::endl;
        } catch (const ClosedQueue& e) {
            if (_keep_running) {
                std::cerr << "ClosedQueue in sender: " << e.what() << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Sender Error: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Unknown error sender" << std::endl;
        }
    }
}

void Sender::stop() {
    _keep_running = false;
    sender_queue.close();

    // Cerramos el socket
    peer.shutdown(SHUT_RDWR);
    peer.close();
}

Queue<Command>& Sender::get_queue() { return sender_queue; }
