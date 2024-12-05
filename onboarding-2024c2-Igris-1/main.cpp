#include <fstream>
#include <iostream>
#include <string>

#include "wordscounter.h"

#define SUCCESS 0
#define ERROR 1

int main(int argc, const char* argv[]) {
    Wordscounter* counter = new Wordscounter;
    std::ifstream* input = new std::ifstream;
    if (argc > 1) {
        input->open(argv[1]);
        if (!input->is_open()) {
            delete input;
            delete counter;
            return ERROR;
        }
        counter->process(*input);
    } else {
        counter->process(std::cin);
    }
    size_t words = counter->get_words();
    std::cout << words << std::endl;
    delete input;
    delete counter;
    return SUCCESS;
}
