#include <string.h>
#include <stdlib.h>
#include<stdbool.h>
#include "jogo.h"

char **tabuleiro;
int colunas[LINES];
char jogadores[2];

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

void inicializaJogadores(char jogador01, char jogador02) {
    jogadores[0] = jogador01;
    jogadores[1] = jogador02;
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

void marcaJogada(int jogador, int coluna) {
    if(colunas[coluna-1] == COLUMNS) {
        return -1;
    }
    int line = LINES - colunas[coluna-1] - 1;
    colunas[coluna-1]++;
    tabuleiro[line][coluna-1] = jogadores[jogador - 1];
    return line;
}