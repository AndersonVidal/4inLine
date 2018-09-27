#ifndef _H_RENDER
#define _H_RENDER
#define VAZIO 0
#define JOGADOR 1
#define IA 2
#define LINHAS 6
#define COLUNAS 7
#define AMARELO "\033[0;33m"
#define AZUL "\033[0;36m"
#define NORMAL "\033[0m"


void exibirTabuleiro(char **tabuleiro);

void exibirPlacar(int pontosJogador, int pontosIa);

#endif