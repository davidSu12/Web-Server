#ifndef UNTITLED9_TYPES_H
#define UNTITLED9_TYPES_H
#include "header.h"


#define MAX_REQUEST_SIZE 2048
#define LNULL NULL


typedef struct client_info{
    socklen_t address_length;
    struct sockaddr_storage address;
    SOCKET socket;
    char request[MAX_REQUEST_SIZE];
    int received;
    struct client_info *next;
}client_info;


typedef struct client_info *lista_clientes;
typedef SOCKET SERVER;
typedef SOCKET SOCKET_CLIENT;

#endif //UNTITLED9_TYPES_H
