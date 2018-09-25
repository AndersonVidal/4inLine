#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED

#define LINHAS 6
#define COLUNAS 7
#define VAZIO 0
#define JOGADOR 1
#define IA 2

/* Método que gerencia a busca por sequências válidas de peças da IA ou do oponente para  
bloquear e retorna qual a posição onde a IA colocará sua próxima peça */
int getPosicaoDaJogadaIA(int tabuleiro[LINHAS][COLUNAS]);

#endif