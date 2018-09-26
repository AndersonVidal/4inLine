#include<stdbool.h>

#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#define LINES 6
#define COLUMNS 7

/* Metodo que inicializa o tabuleiro como vazio */
void inicializarTabuleiro();

/* Metodo que inicializa os jogadores com suas determinadas peças */
void inicializaJogadores(char jogador01, char jogador02); 

/* Metodo que retorna o tabuleiro */
char **getTabuleiro();

/* Metodo que verifica se o tabuleiro foi completamente preenchido */
bool verificaCompleta();

/* Metodo que marca no tabuleiro a jogada de um jogador */
int marcaJogada(int jogador, int coluna);

bool verificaGanhador(int linha, int coluna);

#endif