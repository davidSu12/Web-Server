#include "auxfunc.h"


const char *get_content_type(const char * path){

    const char *last_dot = strchr(path, '.');
    if(last_dot){
        if(strcmp(last_dot, ".css") == 0) return "text/css";
        if(strcmp(last_dot, ".csv") == 0) return "text/csv";
        if(strcmp(last_dot, ".gif") == 0) return "image/gif";
        if(strcmp(last_dot, ".htm") == 0) return "text/html";
        if(strcmp(last_dot, ".html") == 0) return "text/html";
        if(strcmp(last_dot, ".ico") == 0) return "image/x-icon";
        if(strcmp(last_dot, ".jpeg") == 0) return "image/jpeg";
        if(strcmp(last_dot, ".jpg") == 0) return "image/jpeg";
        if(strcmp(last_dot, ".js") == 0) return "application/javascript";
        if(strcmp(last_dot, ".json") == 0) return "application/json";
        if(strcmp(last_dot, ".png") == 0) return "image/png";
        if(strcmp(last_dot, ".pdf") == 0) return "application/pdf";
    }
    return "application/octet-stream";
}

