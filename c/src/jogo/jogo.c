#include <string.h>
#include <stdlib.h>
#include<stdbool.h>

#include "jogo.h"

char **tabuleiro;
int colunas[COLUMNS];
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

bool verificaColunaCompleta(int coluna){
    if(colunas[coluna-1] == COLUMNS - 1) {
        return true;
    }
    return false;
}

bool verificaCompleta() {
    int i,j;
    for(i = 0; i < LINES; i++) {
        for(j = 0; j < COLUMNS; j++) {
            if(tabuleiro[i][j] == '*') {
                return false;
            }
        }
    }
    return true;
}

int marcaJogada(int jogador, int coluna) {
    int line = LINES - colunas[coluna-1] - 1;
    colunas[coluna-1]++;
    tabuleiro[line][coluna-1] = jogadores[jogador - 1];
    return line;
}

bool checkHorizontal(int linha,int coluna) {
    int cont = 1;
    int idx = coluna-2;
    while(idx >= 0 && tabuleiro[linha][idx]==tabuleiro[linha][coluna-1]) {
        idx--;
        cont++;
    }
    idx = coluna+1;
    while(idx < COLUMNS && tabuleiro[linha][idx]==tabuleiro[linha][coluna-1]) {
        idx++;
        cont++;
    }
    if(cont >= 4) return true;
    else return false;
}

bool checkVertical(int linha,int coluna) {
    int cont = 1;
    int idx = linha-1;
    while(idx >= 0 && tabuleiro[idx][coluna-1]==tabuleiro[linha][coluna-1]) {
        idx--;
        cont++;
    }
    idx = linha+1;
    while(idx < LINES && tabuleiro[idx][coluna-1]==tabuleiro[linha][coluna-1]) {
        idx++;
        cont++;
    }
    if(cont >= 4) return true;
    else return false;
}

bool checkDiagonalPrincipal(int linha, int coluna) {
    int cont = 1;
    int idxLinha = linha-1;
    int idxColuna = coluna-2;
    while(idxLinha >= 0 && idxColuna >= 0 && tabuleiro[idxLinha][idxColuna]==tabuleiro[linha][coluna-1]) {
        idxLinha--;
        idxColuna--;
        cont++;
    }
    idxLinha = linha+1;
    idxColuna = coluna;
    while(idxLinha < LINES && idxColuna < COLUMNS && tabuleiro[idxLinha][idxColuna]==tabuleiro[linha][coluna-1]) {
        idxLinha++;
        idxColuna++;
        cont++;
    }
    if(cont >= 4) return true;
    else return false;
}

bool checkDiagonalSecundaria(int linha, int coluna) {
    int cont = 1;
    int idxLinha = linha-1;
    int idxColuna = coluna;
    while(idxLinha >= 0 && idxColuna < COLUMNS && tabuleiro[idxLinha][idxColuna]==tabuleiro[linha][coluna-1]) {
        idxLinha--;
        idxColuna++;
        cont++;
    }
    idxLinha = linha+1;
    idxColuna = coluna-2;
    while(idxLinha < LINES && idxColuna > 0 && tabuleiro[idxLinha][idxColuna]==tabuleiro[linha][coluna-1]) {
        idxLinha++;
        idxColuna--;
        cont++;
    }
    if(cont >= 4) return true;
    else return false;
}

bool verificaGanhador(int linha, int coluna) {
    return checkHorizontal(linha,coluna) || 
		   checkVertical(linha,coluna) || 
		   checkDiagonalPrincipal(linha,coluna) || 
		   checkDiagonalSecundaria(linha,coluna);
}