#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "menu.h"


void showMenu(){
    printf("\n\n");
    printf("[1]\tINICIAR JOGO\n");
    printf("[2]\tREGRAS E DICAS\n");
    printf("[3]\tSOBRE\n");
    printf("[4]\tSAIR\n\n");
    printf("> ");
}

char *cli_response(void){
    char *line = NULL;
    ssize_t bufsize = 0;

    getline(&line, &bufsize, stdin);
    return line;
}

int computeMenuLine(char *line){
    int res;

    if(*line == '1') res = 1;
    else if (*line == '2') res = 2;
    else if (*line == '3') res = 3;
    else if (*line == '4') res = 4;
    else res = -1;

    return res;
}

int exibirMenu() {
	showMenu();

	char *line;
	int status;

	while(1){
		line = cli_response();
		status = computeMenuLine(line);
		if(status != -1) return status;
		else printf("Comando inválido! Por favor, digite um comando válido.\n");
		}



}
