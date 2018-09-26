#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ia.h"

/* Esse método adiciona itens do tabuleiro em uma fila de tamanho pré definido. */
void enfileirar(int tamanho, int fila[tamanho], int item) {
    for (int i = 0; i < tamanho - 1; i++) {
        fila[i] = fila[i + 1];
    }
    fila[tamanho - 1] = item;
}

/* Esse método percorre a fila e retorna a posição do array que contém uma casa vazia 
se ela for válida, caso contrário, retorna -1.  Uma sequência é válida se conter 
exatamente uma casa vazia em qualquer posição da sequência e N - 1 peças do dado jogador. */
int getPosicaoVazia(int tamanho, int fila[tamanho], int jogador) {
    int qtdJogador = 0;
    int qtdVazio = 0;
    int posicaoVazia = -1;

    for (int i = 0; i < tamanho; i++) {
        if (fila[i] == VAZIO) {
            qtdVazio++;
            posicaoVazia = i;
        }
        if (fila[i] == jogador) {
            qtdJogador++;
        }
    }
    if (qtdJogador == tamanho - 1 && qtdVazio == 1) {
        return posicaoVazia;
    }
    return -1;
}

/* Esse método percorre o tabuleiro na direção vertical, buscando uma sequência de N - 1 
peças do jogador Y. Se for encontrada uma sequência, retorna a posição da casa vazia; 
caso contrário, retorna -1. */
int procuraNaVertical(int tabuleiro[LINHAS][COLUNAS], int jogador, int tamanho) {
    int filaAtual[tamanho];
    for (int col = 0; col < COLUNAS; col++) {
        /* A função 'memset' adiciona '0' em todas as posições do array 'filaAtual' */
        memset(filaAtual, 0, sizeof filaAtual);
        for (int lin = LINHAS - 1; lin >= 0; lin--) {
            enfileirar(tamanho, filaAtual, tabuleiro[lin][col]);
            int posicao = getPosicaoVazia(tamanho, filaAtual, jogador);
            if (posicao!= -1) {
                return col;
            }
        }
    }
    return -1;
}

/* Esse método percorre o tabuleiro na direção horizontal, buscando uma sequência de N - 1 
peças do jogador Y. Se for encontrada uma sequência, retorna a posição da casa vazia; 
caso contrário, retorna -1. */
int procurarNaHorizontal(int tabuleiro[LINHAS][COLUNAS], int jogador, int tamanho) {
    int filaAtual[tamanho];
    for (int lin = LINHAS - 1; lin >= 0; lin--) {
        memset(filaAtual, 0, sizeof filaAtual);
        for (int col = 0; col < COLUNAS; col++) {
            enfileirar(tamanho, filaAtual, tabuleiro[lin][col]);
            int posicao = getPosicaoVazia(tamanho, filaAtual, jogador);
            if (posicao != -1) {
                return col - (tamanho - 1) + posicao;
            }
        }
    }
    return -1;
}

/* Esse método percorre o tabuleiro na direção da diagonal principal, buscando uma sequência 
de N - 1 peças do jogador Y. Se for encontrada uma sequência, retorna a posição da casa vazia; 
caso contrário, retorna -1. */
int procurarNaDiagonalPrimaria(int tabuleiro[LINHAS][COLUNAS], int jogador, int tamanho) {
    int filaAtual[tamanho];
    for (int topo_linha = 2; topo_linha >= 0; topo_linha--) {
        for (int topo_coluna = 0; topo_coluna < COLUNAS; topo_coluna++) {
            int col = topo_coluna, lin = topo_linha;
            memset(filaAtual, 0, sizeof filaAtual);
            while (col < COLUNAS & lin < LINHAS) {
                enfileirar(tamanho, filaAtual, tabuleiro[lin][col]);
                col++;
                lin++;
            }
            int posicao = getPosicaoVazia(tamanho, filaAtual, jogador);
            if (posicao != -1) {
                return topo_coluna + posicao;
            }
        }
    }
    return -1;
}

/* Esse método percorre o tabuleiro na direção da diagonal secundária, buscando uma sequência 
de N - 1 peças do jogador Y. Se for encontrada uma sequência, retorna a posição da casa vazia; 
caso contrário, retorna -1. */
int procurarNaDiagonalSecundaria(int tabuleiro[LINHAS][COLUNAS], int jogador, int tamanho) {
    int filaAtual[tamanho];
    for (int topo_linha = 2; topo_linha >= 0; topo_linha--) {
        for (int topo_coluna = COLUNAS - 1; topo_coluna >= 0; topo_coluna--) {
            int col = topo_coluna, lin = topo_linha;
            memset(filaAtual, 0, sizeof filaAtual);
            while (col >= 0 & lin < LINHAS) {
                enfileirar(tamanho, filaAtual, tabuleiro[lin][col]);
                col--;
                lin++;
            }
            int posicao = getPosicaoVazia(tamanho, filaAtual, jogador);
            if (posicao != -1) {
                return topo_coluna - posicao;
            }
        }
    }
    return -1;
}

int getPosicao(int tabuleiro[LINHAS][COLUNAS], int jogador, int tamanho) {
    int posHorizontal = procurarNaHorizontal(tabuleiro, jogador, tamanho);
    int posVertical = procuraNaVertical(tabuleiro, jogador, tamanho);
    int posDiagonaPrincipal = procurarNaDiagonalPrimaria(tabuleiro, jogador, tamanho);
    int posDiagonaSecundaria = procurarNaDiagonalSecundaria(tabuleiro, jogador, tamanho);

    int possibilidades[4];
    int counter = -1;

    if (posHorizontal != -1) {
        possibilidades[counter++] = posHorizontal;
    }
    if (posVertical != -1) {
        possibilidades[counter++] = posVertical;
    }
    if (posDiagonaPrincipal != -1) {
        possibilidades[counter++] = posDiagonaPrincipal;
    }
    if (posDiagonaSecundaria != -1) {
        possibilidades[counter++] = posDiagonaSecundaria;
    }
    if (counter == -1) {
        return -1;
    }

    return possibilidades[rand() % ++counter];
}

int getPosicaoDaJogadaIA(int tabuleiro[LINHAS][COLUNAS]) {
    srand((unsigned)time(NULL));
    /* 1º caso
        - Estado: IA com 3 marcadores em sequência
        - Ação: IA completa a sequência formando 4 
    */
    if (getPosicao(tabuleiro, IA, 4) != -1) {
        return getPosicao(tabuleiro, IA, 4);
    }
    /* 2º caso
        - Estado: Jogador com 3 marcadores em sequência
        - Ação: IA interrompe a sequência do jogador 
    */
    else if (getPosicao(tabuleiro, JOGADOR, 4) != -1) {
        return getPosicao(tabuleiro, JOGADOR, 4);
    }
    /* 3º caso
        - Estado: Jogador com 2 marcadores em sequência
        - Ação: IA interrompe a sequência do jogador 
    */
    else if (getPosicao(tabuleiro, JOGADOR, 3) != -1) {
        return getPosicao(tabuleiro, JOGADOR, 3);
    }
    /* 4º caso
        - Estado: IA com 2 marcadores em sequência
        - Ação: IA adiciona mais um marcador seguindo a sequência 
    */
    else if (getPosicao(tabuleiro, IA, 3) != -1) {
        return getPosicao(tabuleiro, IA, 3);
    }
    /* 5º caso
        - Estado: IA com 1 marcador
        - Ação: IA adiciona mais um marcador vizinho a este 
    */
    else if (getPosicao(tabuleiro, IA, 2) != -1) {
        getPosicao(tabuleiro, IA, 2);
    }
    /* 6º caso
        - Estado: As condições acima não foram atendidas
        - Ação: IA adiciona marcador em posição aleatória 
    */
    else {
        return rand() % 7;
    }
}

/* int main() {
  int tabuleiro[6][7] = 
  {{0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,1,2,1,1,1,2}};

  printf("pos %d", manage(tabuleiro));

  return 0;
}
 */

/* 
erro
  {{0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,2,0,0,0,0,0},
  {0,1,0,0,0,0,0},
  {1,1,0,0,0,2,0}}; */

