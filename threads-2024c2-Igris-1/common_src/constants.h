#ifndef CONSTANTS_H
#define CONSTANTS_H

// <-----------------SERVER-------------------->
// Constante de comando de cierre total
#define SHUTDOWN_COMMAND "q"

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


// <-----------------PROTOCOL-------------------->
// Constante de limite de bites del recvall
#define MAX_BYTES 2

// constante de limite de bites del recvall del server
#define MAX_BYTES_SRV 1


// <-----------------CLIENT-------------------->
// Constante de comando inicial
#define PICK_COMMAND "Pickup"

// Constante de comando de READ
#define READ_COMMAND "Read"

// Constante de comando de cierre
#define QUIT_COMMAND "Exit"


// <-----------------GAMELOOP-------------------->
// Constante de tiempo de sleep del gameloop
#define SLEEP_TIME 200000


// <-----------------GENERAL-------------------->
// Constante de posicion inicial
#define INIT_POS 0

// Constante de posicion final
#define SECOND_POS 1

// Constante de elemento vacio
#define EMPTY ""

// Constante de inicializacion
#define INI 0

// Command de limite de queues
#define QUEUE_LIMIT 50

// Constante de id de comando
#define USER_COMMAND 0x03

// Constante de comando de caja abierta
#define OPEN_BOX 0x04

// Constante de comando de respawn
#define RESPAWN_BOX 0x05

// Constante de id de server
#define SERVER_COMMAND 0x06

#endif
