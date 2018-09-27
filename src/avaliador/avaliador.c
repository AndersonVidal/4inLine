#include <stdio.h>
#include "avaliador.h"

int numOfLines = 6;
int numOfColums = 7;

void addToLastFour(int lastFour[4], int item){
	lastFour[0] = lastFour[1];
	lastFour[1] = lastFour[2];
	lastFour[2] = lastFour[3];
	lastFour[3] = item;
}

void resetLastFour(int lastFour[4]){
	lastFour[0] = 0;
	lastFour[1] = 0;
	lastFour[2] = 0;
	lastFour[3] = 0;
}

int fourInLine(int lastFour[4]){
	if(lastFour[0] == lastFour[1] && lastFour[2] == lastFour[3] && lastFour[1] == lastFour[2] && lastFour[0] != 0){
		return lastFour[0];
	} else {
		return 0;
	}

}

int verticalLine(int tabuleiro[numOfLines][numOfColums]){
	int lastFour[4];

	for(int j = 0; j < numOfColums; j++){
		for(int i = 0; i < numOfLines; i++){
			addToLastFour(lastFour, tabuleiro[i][j]);
			if( fourInLine(lastFour) > 0 ){
				return fourInLine(lastFour);
			}
		}
	}

	return 0;

}

int horizontalLine(int tabuleiro[numOfLines][numOfColums]){
	int lastFour[4];

	for(int i = 0; i < numOfColums; i++){
		for(int j = 0; j < numOfLines; j++){
			addToLastFour(lastFour, tabuleiro[i][j]);
			if( fourInLine(lastFour) > 0 ){
				return fourInLine(lastFour);
			}
		}
	}

	return 0;

}

int mainDiagonalLine(int tabuleiro[numOfLines][numOfColums]){
	int lastFour[4];

	int outsidex;
	int outsidey;
	int insidex;
	int insidey;

	while(!((numOfColums - outsidey) < 4)){
		outsidex = 0;

		insidex = outsidex;
		insidey = outsidey;
		while(!(insidex > 5 || insidey > 6)){

			addToLastFour(lastFour, tabuleiro[insidex][insidey]);
			if(fourInLine(lastFour)) return fourInLine(lastFour);
			insidex++;
			insidey++;
		}

		resetLastFour(lastFour);
		outsidey++;
	}

	outsidex = 1;
	outsidey = 0;

	while(!((6 - outsidex) < 4)){
		outsidey = 0;

		insidex = outsidex;
		insidey = outsidey;
		while(!(insidex > 5 || insidey > 6)){

			addToLastFour(lastFour, tabuleiro[insidex][insidey]);
			if(fourInLine(lastFour)) return fourInLine(lastFour);
			insidex++;
			insidey++;
		}

		resetLastFour(lastFour);
		outsidex++;
	}

	return 0;
}

int secondDiagonalLine(int tabuleiro[numOfLines][numOfColums]){
	int lastFour[4];

	int outsidex;
	int outsidey = 6;
	int insidex;
	int insidey;

	while(!(outsidey < 3)){
		outsidex = 0;

		insidex = outsidex;
		insidey = outsidey;
		while(!(insidex > 5 || insidey < 0)){

			addToLastFour(lastFour, tabuleiro[insidex][insidey]);
			if(fourInLine(lastFour)) return fourInLine(lastFour);
			insidex++;
			insidey--;
		}

		resetLastFour(lastFour);
		outsidey--;
	}

	outsidex = 1;
	outsidey = 6;

	while(!((6 - outsidex) < 4)){
		outsidey = 6;

		insidex = outsidex;
		insidey = outsidey;
		while(!(insidex > 5)){

			addToLastFour(lastFour, tabuleiro[insidex][insidey]);
			if(fourInLine(lastFour)) return fourInLine(lastFour);
			insidex++;
			insidey--;
		}

		resetLastFour(lastFour);
		outsidex++;
	}

	return 0;
}

int empate(int tabuleiro[numOfLines][numOfColums]){
	for(int i; i < numOfLines; i++){
		for(int j; j < numOfColums; j++){
			if(tabuleiro[i][j] < 1) return 0;
		}
	}
	return 3;
}

int avaliar(int tabuleiro[numOfLines][numOfColums]){
	int possibilidades[5];
	possibilidades[0] = verticalLine(tabuleiro);
	possibilidades[1] = horizontalLine(tabuleiro);
	possibilidades[2] = mainDiagonalLine(tabuleiro);
	possibilidades[3] = secondDiagonalLine(tabuleiro);
	possibilidades[4] = empate(tabuleiro);

	if(possibilidades[0]) return possibilidades[0];
	else if(possibilidades[1]) return possibilidades[1];
	else if(possibilidades[2]) return possibilidades[2];
	else if(possibilidades[3]) return possibilidades[3];
	else if(possibilidades[4]) return possibilidades[4];
	return 0;


}


int main(){
	int tabuleiro1[6][7] = {
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0}
	};

	int tabuleiro2[6][7] = {
		{1, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0}
	};

	int tabuleiro3[6][7] = {
		{1, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0}
	};

	int tabuleiro4[6][7] = {
		{0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0}
	};

	int tabuleiro5[6][7] = {
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 1, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0}
	};


	printf("quem ganhou no tabuleiro1: %d\n", avaliar(tabuleiro1));
	printf("quem ganhou no tabuleiro2: %d\n", avaliar(tabuleiro2));
	printf("quem ganhou no tabuleiro3: %d\n", avaliar(tabuleiro3));
	printf("quem ganhou no tabuleiro4: %d\n", avaliar(tabuleiro4));
	printf("quem ganhou no tabuleiro5: %d\n", avaliar(tabuleiro5));
	printf("tabuleiro 4 esta: %d\n", mainDiagonalLine(tabuleiro4));
	printf("tabuleiro 5 esta: %d\n", secondDiagonalLine(tabuleiro5));
}
/*
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
*/
