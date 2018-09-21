#include <stdio.h>

int numOfLines = 6;
int numOfColums = 7;

int addToLastFour(int *lastFour[4], int item){
	lastFour[0] = lastFour[1];
	lastFour[1] = lastFour[2];
	lastFour[2] = lastFour[3];
	lastFour[3] = item;
}

int fourInLine(int *lastFour[4]){
	if(lastFour[0] == lastFour[1] && lastFour[2] == lastFour[3] && lastFour[1] == lastFour[2] && lastFour[0] != 0){
		return lastFour[0];
	} else {
		return 0;
	}

}

int verticalLine(int *tabuleiro[numOfLines][numOfColums]){
	int lastFour[4];

	for(int j = 0; j < numOfColums; j++){
		for(int i = 0; i < numOfLines; i++){
			addToLastFour(&tabuleiro, tabuleiro[i][j]);
			if( fourInLine(&lastFour) > 0 ){
				return fourInLine(&lastFour);
			}
		}
	}

	return 0;

}

int horizontalLine(int *tabuleiro[numOfLines][numOfColums]){
	int lastFour[4];

	for(int i = 0; i < numOfColums; i++){
		for(int j = 0; j < numOfLines; j++){
			addToLastFour(&tabuleiro, tabuleiro[i][j]);
			if( fourInLine(&lastFour) > 0 ){
				return fourInLine(&lastFour);
			}
		}
	}

	return 0;

}

int mainDiagonalLine(int *tabuleiro[numOfLines][numOfColums]){
	
}

int avaliar(int *tabuleiro[numOfLines][numOfColums]){


}

/*
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
*/
