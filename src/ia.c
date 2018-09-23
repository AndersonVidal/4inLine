
int numOfLines = 6;
int numOfColums = 7;

int addToLastFour(int lastFour[4], int item){
	lastFour[0] = lastFour[1];
	lastFour[1] = lastFour[2];
	lastFour[2] = lastFour[3];
	lastFour[3] = item;
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

int verticalLine(int board[numOfLines][numOfColums]){
	int lastFour[4];
	for(int j = 0; j < numOfColums; j++){
		for(int i = numOfLines - 1; i >= 0; i--){
			addToLastFour(lastFour, board[i][j]);
      int sqThree = threeInLine(lastFour);
			if (sqThree > 0) {
				return sqThree;
			}
		}
	}
	return 0;
}

int horizontalLine(int board[numOfLines][numOfColums]){
	int lastFour[4];
	for(int i = numOfLines - 1; i >= 0; i--){
		for(int j = 0; j < numOfColums; j++){
			addToLastFour(lastFour, board[i][j]);
      int sqThree = threeInLine(lastFour);
			if (sqThree > 0) {
				return sqThree;
			}
		}
	}
	return 0;
}

void manage(int board[numOfLines][numOfColums]) {
  if (horizontalLine(board) == 2 || verticalLine(board) == 2) {
    /*addPiece();*/
  }
  else if (horizontalLine(board) == 1 || verticalLine(board == 1)) {
    /*blockSeq();*/
  } else {
    /*randomPlay();*/
  }
}
