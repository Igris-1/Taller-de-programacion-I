#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

// Constante de cantidad de argumentos
#define CLI_ARGUMENTS 3

// Constante de cantidad de argumentos del servidor
#define SRV_ARGUMENTS 2

// Host name
#define HOSTNAME 1

// Server name
#define SERVNAME 2

// Constante de error
#define ERROR -1

// Constante de posicion inicial
#define INIT_POS 0

// Constante de inicializacion
#define INI 0

// Constante de inicializacion de buffer
#define BUF_SIZE 256

// Constante de limite de bites del recvall del client
#define MAX_BYTES 2

// constante de limite de bites del recvall del server
#define MAX_BYTES_SRV 1

// Constante de comando inicial
#define BUY_COMMAND 'B'

// Constante de comando de cierre
#define QUIT_COMMAND 'q'

// Constante de inicio rango de arma secundaria
#define SECONDARY_START 1

// Constante de fin rango de arma secundaria
#define SECONDARY_END 3

// Constante de inicio rango de arma primaria
#define PRIMARY_START 4

// Constante de fin rango de arma primaria
#define PRIMARY_END 6

// Constante de seleccion de carga de arma secundaria
#define SECONDARY_LOAD 7

// Constante de seleccion de carga de arma primaria
#define PRIMARY_LOAD 8

// Constante de carga de arma primaria
#define LOAD_PRIMARY 10

// Constante de carga de arma secundaria
#define LOAD_SECONDARY 7

// Constante de cuchillo
#define KNIFE 9

// Constante equipado
#define EQUIPPED 1

// Constante no equipado
#define NOT_EQUIPPED 0

#endif
