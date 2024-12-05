# Threads

Todo el contenido de la carpeta [*common_src*](https://github.com/Taller-de-Programacion-TPs/threads-2024c2-Igris-1/tree/main/common_src) menos los siguientes archivos
- [*constants.h*](https://github.com/Taller-de-Programacion-TPs/threads-2024c2-Igris-1/blob/main/common_src/constants.h)
- [*protocol_base.h*](https://github.com/Taller-de-Programacion-TPs/threads-2024c2-Igris-1/blob/main/common_src/protocol_base.h)
- [*srv_protocol.h*](https://github.com/Taller-de-Programacion-TPs/threads-2024c2-Igris-1/blob/main/common_src/srv_protocol.h)
- [*srv_protocol.cpp*](https://github.com/Taller-de-Programacion-TPs/threads-2024c2-Igris-1/blob/main/common_src/srv_protocol.cpp)
- [*cli_protocol.h*](https://github.com/Taller-de-Programacion-TPs/threads-2024c2-Igris-1/blob/main/common_src/cli_protocol.h)
- [*cli_protocl.cpp*](https://github.com/Taller-de-Programacion-TPs/threads-2024c2-Igris-1/blob/main/common_src/cli_protocol.cpp)

pertenece a los siguientes repos, ambos bajo licencia **GPL v2**
- **[hands-on-sockets-in-cpp](https://github.com/eldipa/hands-on-sockets-in-cpp)**
- **[hands-on-threads](https://github.com/eldipa/hands-on-threads)**

## Datos
Todas las *Queue* implementadas son ***thread safe*** y la unica posible ***race condition*** es en la ***client list*** que es iterada y modificada por distintos threads creando una *critical section*, para solucionar este problema se implemento un ***monitor*** que lockea la iteración y la modificación de la misma asegurando una concurrencia adecuada

- El ```try_pop``` en la queue del *gameloop* no es bloqueante ya que el *gameloop* debe estar siempre corriendo
- El ```try_push``` de las actualizaciones en las queues *sender* de los clientes desde el *monitor* no es bloquente, ya que dicha queue puede estar llena y bloquearse al hacer un ```push```
- El ```push``` del comando de los clientes en el *receiver* debe ser bloqueante para dicho *receiver* ya que siempre queremos pushear el comando sin excepciones
