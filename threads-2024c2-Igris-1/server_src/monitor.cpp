
#include "monitor.h"

#include <utility>

#include "client.h"

void Monitor::reap_dead() {
    client_list.remove_if([](Client& client) {
        if (!client.is_alive()) {
            client.stop();
            client.join();
            return true;
        }
        return false;
    });
}

void Monitor::add_client(Socket& socket, ServerProtocol& protocol, Queue<Command>* queue) {
    std::lock_guard<std::mutex> lock(mutex);
    client_list.emplace_back(socket, protocol, queue);
    client_list.back().run();
    reap_dead();
}

void Monitor::push_message(Command command) {
    std::lock_guard<std::mutex> lock(mutex);
    for (Client& client: client_list) {
        client.get_queue().try_push(std::move(command.clone()));
    }
}

void Monitor::kill() {
    std::lock_guard<std::mutex> lock(mutex);
    for (Client& client: client_list) {
        client.stop();
        client.join();
    }
    client_list.clear();
}
