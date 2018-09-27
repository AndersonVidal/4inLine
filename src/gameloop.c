#include <stdio.h>
#include<stdbool.h>
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
    printf("PLACAR\n");
}

int lerColunaJogador(){
    int coluna;
    bool invalida;
    do{
        printf("Coluna > ");
        scanf("%i",&coluna);
        if(coluna < 1 || coluna >7){
            invalida = true;
        }else if(verificaColunaCompleta(coluna)){
            invalida = true;
        }else{
            invalida = false;
        }
    }while(invalida);
    return coluna;
}

void gameloop(){
    int ganhador = 0;
    int coluna,linha;
    inicializarTabuleiro();
    inicializaJogadores('X','O');
    while (true) {
        showPlacar();
        showTabuleiro(getTabuleiro());
        coluna = lerColunaJogador();
        linha = marcaJogada(1,coluna);
        if(verificaGanhador(linha,coluna)){
            ganhador = 1;
            break;
        }
        showPlacar();
        showTabuleiro(getTabuleiro());
        coluna = lerColunaJogador();
        linha = marcaJogada(2,coluna);
        if(verificaGanhador(linha,coluna)){
            ganhador = 2;
            break;
        }
        if(verificaCompleta()) break;
    }
    if(ganhador == 0) printf("-------> empate <-------");
    else if(ganhador == 1) printf("-------> jogador 01 <-------");
    else if(ganhador == 2) printf("-------> jogador 02 <-------");
}