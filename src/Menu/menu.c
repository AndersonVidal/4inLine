#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "menu.h"

void showArchive(char type){
    char ch, t[1000];
    FILE *arq;

    if (type == 'B') arq = fopen("./src/TextArchives/About.txt","r");
    else if (type == 'R') arq = fopen("./src/TextArchives/Rules.txt","r");
    else if (type == 'A') arq = fopen("./src/TextArchives/Apresentation.txt","r");
    else if (type == 'E') arq = fopen("./src/TextArchives/Salute.txt","r");

    if(arq == NULL) printf("A unexpected error occurred!\n");
    else {
        while(fgets(t,sizeof(t),arq) != NULL) printf("%s",t);
        fclose(arq);
    }

    printf("\n");
}

void showMenu(){
    printf("\n\n");
    printf("[1]\tINICIAR JOGO\n");
    printf("[2]\tREGRAS E DICAS\n");
    printf("[3]\tSOBRE\n");
    printf("[4]\tSAIR\n\n");
    printf("> ");
}

int computeMenuLine(char *line){
    int res;

    if(*line == '1') res = 1;
    else if (*line == '2') res = 2;
    else if (*line == '3') res = 3;
    else if (*line == '4') res = 0;
    else res = -1;

    return res; 
}

void executeStatusOperation(int status){
    if (status == 1) return;//startGameRotine();
    else if (status == 2) showArchive('R');
    else if (status == 3) showArchive('B');
    else if (status == 0) showArchive('E'); 
    else if (status == -1) printf("Comando inválido! Por favor, digite um comando válido.\n");
}