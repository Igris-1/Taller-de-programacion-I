#ifndef __WORDSCOUNTER_H__
#define __WORDSCOUNTER_H__

#include <fstream>
#include <string>

// Tipo wordscounter_t: procesa cantidad de palabras dentro de un archivo.
class Wordscounter {
    // cppcheck-suppress unusedStructMember
    size_t words;

public:
    Wordscounter();

    // Retorna la cantidad de palabras procesadas
    size_t get_words();

    // Procesa el contenido de text_file, contando sus palabras. Pos: si el archivo no se puede
    // abrir devuelve -1 si lo puede abrir devuelve 0
    void process(std::istream& text_file);

    // Compara el caracter leído c y define el nuevo estado.
    char next_state(char state, char c);
};
#endif
