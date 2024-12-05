#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <string>

#include "../common_src/queue.h"
#include "../common_src/thread.h"

#include "command.h"
#include "model.h"
#include "monitor.h"

class GameLoop: public Thread {
private:
    Monitor& client_monitor;
    Queue<Command>& main_queue;
    // cppcheck-suppress unusedStructMember
    Model model;

public:
    GameLoop(Monitor& list, Queue<Command>& queue): client_monitor(list), main_queue(queue) {}

    // Corre el gameloop
    void run() override;

    // Actualiza el modelo
    void update_model(const Command& command);

    // Crea y envia un comando de caja abierta
    void make_command(const std::string& client_name, const std::string& reward);

    // Crea y envia un comando de caja activa
    void active_box(int active_boxes);

    // Imprime la caja abierta
    void print_open_box(const std::string& client_name, const std::string& reward);

    // Imprime la cantidad de cajas activas
    void print_active_boxes(int active_boxes);
};

#endif  // GAMELOOP_H
