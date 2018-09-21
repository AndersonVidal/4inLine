#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "menu.h";

void showRules(){
    FILE *rules;
    rules = fopen("../TextArchives/Rules.txt", "w");
    
    char readRules;
     
    do {
        readRules = getc(rules);
        printf("%c", readRules);
    } while (readRules != EOF);
}

void showAbout(){
    FILE *about;
    about = fopen("../TextArchives/About.txt", "w");
    
    char readAbout;

    do {
        readAbout = getc(about);
        printf("%c", readAbout);
    } while (readAbout != EOF);
}

void showMenu(){
    printf("--------- 4 IN LINE ---------\n\n");
    printf("[1]\tINICIAR JOGO\n");
    printf("[2]\tREGRAS E DICAS\n");
    printf("[3]\tSOBRE\n");
    printf("[4]\tSAIR\n\n");
    printf("> ");
}

int computeMenuLine(char *line){
    int res;

    if(line == '1') res = 1;
    else if (line == '2') res = 2;
    else if (line == '3') res = 3;
    else if (line == '4') res = 0;
    else res = -1;

    return res; 
}

void executeStatusOperation(int status){
    if (status == 1) startGameRotine();
    else if (status == 2) showRules();
    else if (status == 3) showAbout();
    else if (status == 0) printf("Obrigado por jogar 4inLine! <3 \n");
    else if (status == -1) printf("Comando inválido! Por favor, digite um comando válido.\n");
}