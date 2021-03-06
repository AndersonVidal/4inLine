#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "jogo.h"
#include "../render/render.h"
#include "../ia/ia.h"


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
            printf("\nColuna '%i' não existe no tabuleiro :(\ndigite uma coluna de 1 e 7.\n\n", coluna);
        }

        else if(verificaColunaCompleta(coluna)) invalida = true;
        else invalida = false;
    } while(invalida);

    return coluna;
}

int lerRepeatRespostaJogador() {
    int status;
    char *line = NULL;
    
    ssize_t bufsize = 0;
    printf("Deseja continuar jogando? (y or n)\n> ");
    getline(&line, &bufsize, stdin);

    if (*line == 'y') status = 1;
    else status = 0;

    return status;
}

int gameloop(){
    int ganhador = 0;
    int coluna,linha;
    int status = -1;

    inicializarTabuleiro();
    inicializaJogadores('X','O');

    while (status) {
        exibirTabuleiro(getTabuleiro());
        coluna = lerColunaJogador();
        linha = marcaJogada(1,coluna);
        
        if(verificaGanhador(linha,coluna)){
            ganhador = 1;
            status = 0;
            
        } else if(verificaCompleta()) status = 0;
        else {
            coluna = getPosicaoDaJogadaIA(getTabuleiro());
            linha = marcaJogada(2,coluna);
            printf("\nO PC jogou na posição %d\n", coluna);
            
            if(verificaGanhador(linha,coluna)){
                ganhador = 2;
                status = 0;
            }
        }
    }

    return ganhador;
}