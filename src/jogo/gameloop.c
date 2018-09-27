#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "jogo.h"
#include "../render/render.h"

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
    printf("\nPLACAR\n\n");
}

int lerColunaJogador(){
    int coluna;
    char *line = NULL;
    bool invalida;
    ssize_t bufsize = 0;

    do {
        printf("Coluna > ");
        getline(&line, &bufsize, stdin);

        coluna = atoi(line);
        
        if(coluna < 1 || coluna > 7) {
            invalida = true;
            printf("Coluna '%i' não existe no tabuleiro :(\ndigite uma coluna de 1 e 7.\n\n", coluna);
        }

        else if(verificaColunaCompleta(coluna)) invalida = true;
        else invalida = false;
    } while(invalida);

    return coluna;
}

int gameloop(){
    int jogador = 0;
    int ia = 0;
    int ganhador = 0;
    int coluna,linha;
    int status = -1;

    inicializarTabuleiro();
    inicializaJogadores('X','O');

    while (status) {
        //showPlacar();
        exibirPlacar(jogador, ia);
        //showTabuleiro(getTabuleiro());
        exibirTabuleiro(getTabuleiro());
        coluna = lerColunaJogador();
        linha = marcaJogada(1,coluna);
        
        if(verificaGanhador(linha,coluna)){
            ganhador = 1;
            jogador ++;
            status = 0;
            
        } else if(verificaCompleta()) status = 0;
        else {

            //showPlacar();
            exibirPlacar(jogador, ia);
            //showTabuleiro(getTabuleiro());
            exibirTabuleiro(getTabuleiro());
            coluna = lerColunaJogador();
            linha = marcaJogada(2,coluna);
            
            if(verificaGanhador(linha,coluna)){
                ganhador = 2;
                ia ++;
                status = 0;
            }
        }
        //showPlacar();
        exibirPlacar(jogador, ia);
        //showTabuleiro(getTabuleiro());
        exibirTabuleiro(getTabuleiro());
    }

    return ganhador;
}