#include <stdio.h>
#include "regras.h"

void exibirRegras() {
  printf("+---------------------------------------------------------------+\n");
  printf("| O objetivo do jogo é conectar quatro marcadores iguais em uma |\n");
  printf("| linha. Todas as direções (vertical, horizontal e diagonal)    |\n");
  printf("| são válidas. Os jogadores se revezam colocando um dos seus    |\n");
  printf("| marcadores em uma das sete colunas. O marcador percorre a     |\n");
  printf("| coluna de cima para baixo o máximo possível. O jogador humano |\n");
  printf("| começa. O jogo termina imediatamente quando o primeiro        |\n");
  printf("| jogador conectou quatro marcadores.                           |\n");
  printf("+---------------------------------------------------------------+\n");
}
