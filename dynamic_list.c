#include "dynamic_list.h"



client_info * make_client(SOCKET_CLIENT sock){

    client_info * temp = calloc(1, sizeof(struct client_info));
    if(!temp){
        return LNULL;
    }
    temp -> socket = sock;
    temp -> address_length = sizeof(struct client_info);
    temp -> next = LNULL;
    return temp;

}

void createEmptyList(lista_clientes *l){
    *l = LNULL;
}

bool isEmptyList(lista_clientes l){
    return l == LNULL;
}
client_info * get_client(lista_clientes *l, SOCKET_CLIENT s){

    client_info *temp;

    if(isEmptyList(*l)){

        temp = make_client(s);

        if(!temp){
            fprintf(stderr,"No more memory for the socket %llu",s);
            return LNULL;
        }
        *l = temp;
        return temp;


    }else{
        for(temp = *l; temp != LNULL && temp -> socket != s; temp = temp -> next);

        if(!temp){

            temp = make_client(s);
            if(!temp){
                fprintf(stderr, "No more memory for the socket %llu", s);
                return LNULL;
            }
            temp -> next = *l;
            *l = temp;
            return temp;
        }else{
            return temp;
        }
    };

}

void drop_client(lista_clientes *l, SOCKET_CLIENT s){

    client_info *curr, *prev;

    for(prev = LNULL, curr = *l;
        curr != LNULL && curr -> socket != s; prev = curr, curr = curr -> next);
    if(!prev) {
        *l = (*l)->next;
    }else if(!curr){
        return;
    }else{
        prev -> next = curr -> next;
    }

    closesocket(curr -> socket);
    free(curr);
}

char * get_client_address(client_info client){
    char *name = calloc(256, sizeof(char));

    if(!name){
        return NULL;
    }else{
        getnameinfo((struct sockaddr *) &(client.address),
                client.address_length,
                name,
                256,
                0,
                0,
                NI_NUMERICHOST);
        return name;
    }

}

fd_set wait_on_clients(lista_clientes l, SERVER s){

    fd_set READS;
    FD_ZERO(&READS);
    SOCKET max_socket = s;

    for(;!l; l = l -> next){
        FD_SET(l -> socket, &READS);
        if(l-> socket > max_socket){
            max_socket = l -> socket;
        }
    }
    if(select(max_socket + 1, &READS, 0,0,0)< 0){
        fprintf(stderr, "There was an error in select()");
        exit(EXIT_FAILURE);
    }

    return READS;
}

void send_400(lista_clientes *l, client_info s){
    const char * cad = "HTTP/1.1 400 Bad Request\r\n"
                       "Connection: close\r\n"
                       "Content-Lenght: 11\r\n\r\nBad Request";
    send(s.socket, cad, strlen(cad),0);
    drop_client(l, s.socket);
}
void send_404(lista_clientes *l, client_info s){
    const char * cad = "HTTP/1.1 404 Not Found\r\n"
                       "Connection: close\r\n"
                       "Content-Length: 9\r\n\r\nNot Found";
    send(s.socket, cad, strlen(cad), 0);
    drop_client(l, s.socket);
}