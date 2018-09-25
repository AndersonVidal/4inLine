#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define EMPTY 0
#define PLAYER 1
#define IA 2

int numOfLines = 6;
int numOfColums = 7;

int addToLast(int sequenceSize, int sequence[sequenceSize], int item) {
    for (int i = 0; i < sequenceSize - 1; i++) {
        sequence[i] = sequence[i + 1];
    }
    sequence[sequenceSize - 1] = item;
}

int xInLine(int sequenceSize, int sequence[sequenceSize], int player) {
    int amountPlayer = 0;
    int amountEmpty = 0;
    int indexEmpty = -1;
    for (int i = 0; i < sequenceSize-1; i++) {
      printf("%d - ", sequence[i]);
    }
    printf("%d\n", sequence[sequenceSize-1]);
    for (int i = 0; i < sequenceSize; i++) {
        if (sequence[i] == 0) {
            amountEmpty++;
            indexEmpty = i;
        }
        if (sequence[i] == player) {
            amountPlayer++;
        }
    }

    if (amountPlayer == sequenceSize - 1 && amountEmpty == 1) {
      return indexEmpty;
    }

    return -1;
}

int verticalLine(int board[numOfLines][numOfColums], int player, int sequenceSize) {
    printf("--- vertical %d %d ---\n\n", player, sequenceSize);
    int currentSequence[sequenceSize];
    for (int j = 0; j < numOfColums; j++) {
        memset(currentSequence, 0, sizeof currentSequence);
        for (int i = numOfLines - 1; i >= 0; i--) {
            addToLast(sequenceSize, currentSequence, board[i][j]);
            printf("i: %d, %d: j\n", i, j);
            int isInline = xInLine(sequenceSize, currentSequence, player);
            if (isInline != -1) {
                return j;
            }
        }
    }
    return -1;
}

int horizontalLine(int board[numOfLines][numOfColums], int player, int sequenceSize) {
    printf("--- horizontal %d %d ---\n\n", player, sequenceSize);
    int currentSequence[sequenceSize];
    for (int i = numOfLines - 1; i >= 0; i--) {
        memset(currentSequence, 0, sizeof currentSequence);
        for (int j = 0; j < numOfColums; j++) {
            addToLast(sequenceSize, currentSequence, board[i][j]);
            int isInline = xInLine(sequenceSize, currentSequence, player);
            if (isInline != -1) {
                return j - (sequenceSize - 1) + isInline;
            }
        }
    }
    return -1;
}

int getPosicao(int board[numOfLines][numOfColums], int player, int sequenceSize) {
    int posHorizontal = horizontalLine(board, player, sequenceSize);
    int posVertical = verticalLine(board, player, sequenceSize);
  /*   int posDiagonaPrincipal = diagonalPrincipalLine(board, player, sequenceSize);
    int posDiagonaSecundaria = diagonalSecundariaLine(board, player, sequenceSize); */

    if (posHorizontal != -1) {
        printf("coluna hori: %d", posHorizontal);
        return posHorizontal;
    } else if (posVertical != -1) {
        printf("coluna vert: %d", posVertical);
        return posVertical;
    } /* else if (posDiagonaPrincipal != -1) {
        return posDiagonaPrincipal;
    } else if (posDiagonaSecundaria != -1) {
        return posDiagonaSecundaria;
    } */ else {
        return -1;
    }
}

int manage(int board[numOfLines][numOfColums]) {
    /* 1º caso
   - Estado: IA com 3 marcadores em sequência
   - Ação: IA completa a sequência formando 4 
  */
    if (getPosicao(board, IA, 4) != -1) {
      printf("ia 3\n");
        return getPosicao(board, IA, 4);
    }
    /* 2º caso
   - Estado: Jogador com 3 marcadores em sequência
   - Ação: IA interrompe a sequência do jogador 
  */
    else if (getPosicao(board, PLAYER, 4) != -1) {
        printf("pl 3\n");
        return getPosicao(board, PLAYER, 4);
        
    }
    /* 3º caso
   - Estado: Jogador com 2 marcadores em sequência
   - Ação: IA interrompe a sequência do jogador 
  */
    else if (getPosicao(board, PLAYER, 3) != -1) {
        printf("pl 2\n");
        return getPosicao(board, PLAYER, 3);
        
    }
    /* 4º caso
   - Estado: IA com 2 marcadores em sequência
   - Ação: IA adiciona mais um marcador seguindo a sequência 
  */
    else if (getPosicao(board, IA, 3) != -1) {
        printf("ia 2\n");
        return getPosicao(board, IA, 3);
        
    }
    /* 5º caso
   - Estado: IA com 1 marcador
   - Ação: IA adiciona mais um marcador vizinho a este 
  */
    else if (getPosicao(board, IA, 2) != -1) {
        printf("ia 1\n");
        getPosicao(board, IA, 2);
        
    }
    /* 6º caso
   - Estado: As condições acima não foram atendidas
   - Ação: IA adiciona marcardor em posição aleatória 
  */
    else {
        printf("random\n");
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