
#include "client.h"

#include "../common_src/queue.h"

#include "command.h"
#include "receiver.h"
#include "sender.h"

void Client::run() {
    receiver.start();
    sender.start();
}

void Client::stop() {
    sender.stop();
    receiver.stop();
}

void Client::join() {
    receiver.join();
    sender.join();
}

Queue<Command>& Client::get_queue() { return sender.get_queue(); }

bool Client::is_alive() const { return receiver.is_alive() || sender.is_alive(); }
