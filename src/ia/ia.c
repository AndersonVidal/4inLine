#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int xInLine(int sequenceSize, int sequence[sequenceSize], int player)
{
    int amountPlayer = 0;
    int amountEmpty = 0;
    int indexEmpty = -1;

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
    int currentSequence[sequenceSize];
    for (int j = 0; j < numOfColums; j++) {
        memset(currentSequence, 0, sizeof currentSequence);
        for (int i = numOfLines - 1; i >= 0; i--) {
            addToLast(sequenceSize, currentSequence, board[i][j]);
            int isInline = xInLine(sequenceSize, currentSequence, player);
            if (isInline != -1) {
                return j;
            }
        }
    }
    return -1;
}

int horizontalLine(int board[numOfLines][numOfColums], int player, int sequenceSize) {
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

int diagonalPrincipalLine(int board[numOfLines][numOfColums], int player, int sequenceSize) {
    int currentSequence[sequenceSize];
    for (int l_top = 2; l_top >= 0; l_top--) {
        for (int c_top = 0; c_top < numOfColums; c_top++) {
            int c = c_top, l = l_top;
            memset(currentSequence, 0, sizeof currentSequence);
            while (c < numOfColums & l < numOfLines) {
                addToLast(sequenceSize, currentSequence, board[l][c]);
                c++;
                l++;
            }
            int isInline = xInLine(sequenceSize, currentSequence, player);
            if (isInline != -1) {
                return c_top + isInline;
            }
        }
    }
    return -1;
}

int diagonalSecundariaLine(int board[numOfLines][numOfColums], int player, int sequenceSize) {
    int currentSequence[sequenceSize];
    for (int l_top = 2; l_top >= 0; l_top--) {
        for (int c_top = numOfColums - 1; c_top >= 0; c_top--) {
            int c = c_top, l = l_top;
            memset(currentSequence, 0, sizeof currentSequence);
            while (c >= 0 & l < numOfLines) {
                addToLast(sequenceSize, currentSequence, board[l][c]);
                c--;
                l++;
            }
            int isInline = xInLine(sequenceSize, currentSequence, player);
            if (isInline != -1) {
                return c_top - isInline;
            }
        }
    }
    return -1;
}

int getPosicao(int board[numOfLines][numOfColums], int player, int sequenceSize) {
    int posHorizontal = horizontalLine(board, player, sequenceSize);
    int posVertical = verticalLine(board, player, sequenceSize);
    int posDiagonaPrincipal = diagonalPrincipalLine(board, player, sequenceSize);
    int posDiagonaSecundaria = diagonalSecundariaLine(board, player, sequenceSize);

    int possibilidades[4];
    int counter = 0;

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
    if (counter == 0) {
        return -1;
    }

    return possibilidades[rand() % counter];
}

int manage(int board[numOfLines][numOfColums]) {
    srand((unsigned)time(NULL));

    if (getPosicao(board, IA, 4) != -1) {
        return getPosicao(board, IA, 4);
    } else if (getPosicao(board, PLAYER, 4) != -1) {
        return getPosicao(board, PLAYER, 4);
    } else if (getPosicao(board, PLAYER, 3) != -1) {
        return getPosicao(board, PLAYER, 3);
    } else if (getPosicao(board, IA, 3) != -1) {
        return getPosicao(board, IA, 3);
    } else if (getPosicao(board, IA, 2) != -1) {
        getPosicao(board, IA, 2);
    } else {
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