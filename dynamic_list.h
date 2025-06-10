
#ifndef UNTITLED9_DYNAMIC_LIST_H
#define UNTITLED9_DYNAMIC_LIST_H
#include "types.h"
#include <stdbool.h>


void createEmptyList(lista_clientes *);
bool isEmptyList(lista_clientes);
client_info get_client(lista_clientes *, SOCKET_CLIENT);
void drop_client(lista_clientes *, SOCKET_CLIENT);
char * get_client_address(client_info);
fd_set wait_on_clients(lista_clientes, SERVER);
void send_400(lista_clientes *, client_info);
void send_404(lista_clientes *, client_info);


//TODO: serve_source()


#endif //UNTITLED9_DYNAMIC_LIST_H
