#include "dynamic_list.h"

/*
void createEmptyList(lista_clientes *);
bool isEmptyList(lista_clientes);
client_info get_client(lista_clientes, SOCKET_CLIENT s);
void drop_client(lista_clientes *, SOCKET_CLIENT s);
char * get_client_address(client_info);
fd_set wait_on_clients(SOCKET);
void send_400(lista_clientes *, client_info);
void send_404(lista_clientes *, client_info);
*/

void createEmptyList(lista_clientes *l){
    *l = LNULL;
}

bool isEmptyList(lista_clientes l){
    return l == LNULL;
}
client_info get_client(lista_clientes l, SOCKET_CLIENT s){

    client_info *temp;
    for(temp = l; temp -> socket != s && temp != LNULL; temp = temp -> next);


}