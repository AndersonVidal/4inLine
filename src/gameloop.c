#include <stdio.h>
#include "./jogo/jogo.h"

void showTabuleiro(char **tabuleiro) {
    int i,j;
    for(i = 0; i < LINES; i++) {
        for(j = 0; j < COLUMNS; j++) {
            printf("%c",tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void showPlacar(){
    //printf("PLACAR");
}

void gameloop(){
    int status = 1;
    int ganhador = -1;
    inicializarTabuleiro();
    inicializaJogadores('A','B');
    while (status) {
        showPlacar();
        showTabuleiro(getTabuleiro());
        int linha = marcaJogada(1, 3);
        if(verificaGanhador(linha,3)){
            status = 0;
            ganhador = 0;
            break;
        }
        showTabuleiro(getTabuleiro());
        linha = marcaJogada(2, 4);
        if(verificaGanhador(linha,4)){
            status = 0;
            ganhador = 1;
            break;
        }
        if(verificaCompleta()){
            status = 0;
        }
        printf("\n------------------------------------------------\n");
    }
    if(ganhador == -1) printf("empate");
    else if(ganhador == 0) printf("jogador 01");
    else printf("jogador 02");
}