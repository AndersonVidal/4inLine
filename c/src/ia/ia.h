#ifndef _H_IA
#define _H_IA

#define LINHAS 6
#define COLUNAS 7
#define VAZIO '*'
#define JOGADOR 'X'
#define IA 'O'

/* Método que gerencia a busca por sequências válidas de peças da IA ou do oponente para  
bloquear e retorna qual a posição onde a IA colocará sua próxima peça */
int getPosicaoDaJogadaIA(char **tabuleiro);

#endif