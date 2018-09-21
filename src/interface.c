#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "interface.h"
#include "./Menu/menu.h"

char *cli_response(void){
    char *line = NULL;
    ssize_t bufsize = 0;

    getline(&line, &bufsize, stdin);
    return line;
}

void cli_loop(void){
    char *line;
    int status;

    do {
        showMenu();

        line = cli_response();
        status = computeMenuLine(line);

        executeStatusOperation(status);

        free(line);
    } while (status);
}