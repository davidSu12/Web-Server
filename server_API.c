#include "server_API.h"


SOCKET create_socket(const char *host, const char *port){

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    struct addrinfo *tar;

    if(getaddrinfo(host, port, &hints, &tar)){
        fprintf(stderr, "An error has ocurred while resolving address (%d)", WSAGetLastError());
        exit(EXIT_FAILURE);
    }

    SOCKET socket_listen;
    socket_listen = socket(tar -> ai_family,
                           tar -> ai_socktype,
                           tar -> ai_protocol);
    if(socket_listen == INVALID_SOCKET){
        fprintf(stderr, "An error has ocurred while creating socket (%d)", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    if(bind(socket_listen, tar -> ai_addr, (int)tar -> ai_addrlen) < 0){
        fprintf(stderr, "An error has ocurred while binding address to socket (%d)", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    freeaddrinfo(tar);

    if(listen(socket_listen, 10)){
        fprintf(stderr, "An error has ocurred while doing listen on socket (%d)", WSAGetLastError());
        exit(EXIT_FAILURE);
    }

    return socket_listen
}