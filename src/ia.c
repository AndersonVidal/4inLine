#define EMPTY 0
#define PLAYER 1
#define IA 2

int numOfLines = 6;
int numOfColums = 7;

int addToLast(int *sequence[4], int item, int sequenceSize){
	for (int i = 0; i < sequenceSize - 1; i++) {
    sequence[i] = sequence[i+1];
  }
  sequence[sequenceSize - 1] = item;
}

int threeInLine(int lastFour[4]) {
  int amountPlayer = 0;
  int amountEmpty = 0;
  int amountCPU = 0;
  for (int i = 0; i < 4; i++) {
      if (lastFour[i] == 0) {
        amountEmpty++;
      } 
      if (lastFour[i] == 1) {
        amountPlayer++;
      }
      if (lastFour[i] == 2) {
        amountCPU++;
      }
  }

  if (amountPlayer == 3 && amountEmpty == 1) {
    return 1;
  }
  else if (amountCPU == 3 && amountEmpty == 1) {
    return 2;
  }
  else {
		return 0;
	}
}

bool isVerticalLine((int *board[numOfLines][numOfColums], int sequenceSize, int player){
	int currentSequence[sequenceSize];
	for(int j = 0; j < numOfColums; j++){
		for(int i = numOfLines - 1; i >= 0; i--){
			addToLast(currentSequence, board[i][j], sequenceSize);
      bool sqThree = xInLine(currentSequence, sequenceSize, player);
			if (sqThree) {
				return true;
			}
		}
	}
	return false;
}

bool isHorizontalLine(int *board[numOfLines][numOfColums], int sequenceSize, int player){
	int currentSequence[sequenceSize];
	for(int i = numOfLines - 1; i >= 0; i--){
		for(int j = 0; j < numOfColums; j++){
			addToLast(currentSequence, board[i][j], sequenceSize);
      bool sqThree = xInLine(currentSequence, sequenceSize, player);
			if (sqThree) {
				return true;
			}
		}
  }
  return false
}

bool isInSequence(int *board[numOfLines][numOfColums], int player, int sequenceSize) {
  return horoizontalLine(bard, player) == sequenceSize || verticalLine(board, player) == sequenceSize;
}

void manage(int *board[numOfLines][numOfColums]) {
  /* 1º caso
   - Estado: IA com 3 marcadores em sequência
   - Ação: IA completa a sequência formando 4 
  */
  if (isInSequence(board, IA, 3)) {
    /* addPiece(int coord[2], int player); */
  }
  /* 2º caso
   - Estado: Jogador com 3 marcadores em sequência
   - Ação: IA interrompe a sequência do jogador 
  */
  else if (isInSequence(board, PLAYER, 3)) {
    /*addPiece();*/
  }
  /* 3º caso
   - Estado: Jogador com 2 marcadores em sequência
   - Ação: IA interrompe a sequência do jogador 
  */
  else if (isInSequence(board, PLAYER, 2)) {
    /*addPiece();*/
  }
  /* 4º caso
   - Estado: IA com 2 marcadores em sequência
   - Ação: IA adiciona mais um marcador seguindo a sequência 
  */
  else if (isInSequence(board, IA, 2)) {
    /*addPiece();*/
  }
  /* 4º caso
   - Estado: IA com 1 marcador
   - Ação: IA adiciona mais um marcador vizinho a este 
  */
  else if (isInSequence(board, IA, 1)) {
    /*addPiece();*/
  }
  /* 6º caso
   - Estado: As condições acima não foram atendidas
   - Ação: IA adiciona marcardor em posição aleatória 
  */
  else {
    /*addPieceRandom();*/
  }
}
