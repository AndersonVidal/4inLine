#include <string.h>
#include <stdlib.h>
#include<stdbool.h>
#include "jogo.h"

char **tabuleiro;
int colunas[LINES];

void inicializarTabuleiro() {
    tabuleiro = (char**)malloc(LINES * sizeof(char*));
    int i,j;
    for(i = 0; i < LINES; i++) {
        tabuleiro[i] = (char*)malloc(COLUMNS * sizeof(char));
    }
    for(i = 0; i < LINES; i++) {
        for(j = 0; j < COLUMNS; j++) {
            tabuleiro[i][j] = '*';
        }
    }
    memset(colunas,0,sizeof(colunas));
}

char **getTabuleiro() {
    return tabuleiro;
}

bool verificaCompleta() {
    int i,j;
    for(i = 0; i < LINES; i++) {
        for(j = 0; j < COLUMNS; j++) {
            if(tabuleiro[i][j] != '*') {
                return true;
            }
        }
    }
    return false;
}