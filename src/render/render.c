#include <stdio.h>

#define VAZIO 0
#define JOGADOR 1
#define IA 2
#define LINHAS 6
#define COLUNAS 7
#define AMARELO "\033[0;33m"
#define AZUL "\033[0;36m"
#define NORMAL "\033[0m"

void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    printf(NORMAL "O)===========================(O\n");
    printf("|| 1   2   3   4   5   6   7 ||\n");
    printf("O)===========================(O\n");
	  
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (j == 0) {
                printf("||");
            } else {
                printf("|");
            }

            if (tabuleiro[i][j] == VAZIO) {
                printf("   ");
            } else if (tabuleiro[i][j] == JOGADOR) {
                printf(AMARELO " ▣ " NORMAL);
            } else {
                printf(AZUL " ▣ " NORMAL);
            }

            if (j == COLUNAS - 1) {
                printf("||\n");
            }
        }
        if (i != LINHAS - 1) {
            printf("||---+---+---+---+---+---+---||\n");
        } else {
            printf("O)===========================(O\n");
        }
    }
}

void exibirPlacar(int pontosJogador, int pontosIa) {
    printf("   +-------/=======\\-------+\n");
    printf("   | Você    %d x %d    PC   |\n", pontosJogador, pontosIa);
    printf("   +-------\\=======/-------+\n\n\n");
}
