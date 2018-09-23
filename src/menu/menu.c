#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "menu.h"
#include "../showMessage/showMessage.h"
#include "../jogo/iniciarJogo.h"


void showMenu(){
    printf("\n\n");
    printf("[1]\tINICIAR JOGO\n");
    printf("[2]\tREGRAS E DICAS\n");
    printf("[3]\tSOBRE\n");
    printf("[4]\tSAIR\n\n");
    printf("> ");
}

char *cli_response(void){
    char *line = NULL;
    ssize_t bufsize = 0;

    getline(&line, &bufsize, stdin);
    return line;
}

int computeMenuLine(char *line){
    int res;

    if(*line == '1') res = 1;
    else if (*line == '2') res = 2;
    else if (*line == '3') res = 3;
    else if (*line == '4') res = 4;
    else res = -1;

    return res;
}

int exibirMenu() {
	showMenu();

	char *line;
	int status;

	while(1){
		line = cli_response();
		status = computeMenuLine(line);
		if(status != -1) return status;
		else printf("Comando inválido! Por favor, digite um comando válido.\n");
		}
}

void chamarMenu() {
	int option;
	showMessage('A');

	/*O laço que é executado até o usuário pedir para sair.*/
  while (1){
    /* Esta parte do programa chama uma função que mostra um menu para o usuário
    com quatro opções.
    1. Iniciar Jogo.
    2. Regras e dicas.
    3. Sobre.
    4. Sair.

    e retorna um inteiro correspondente à opção.*/
    option = exibirMenu();

    /* A próxima parte do programa é um switch que faz uma determinada ação dependendo da opção escolhida */
    switch (option) {
      case 1:
        /* A primeira opção inicia o jogo */
        iniciarJogo();
        break;
      case 2:
        /* A segunda opção mostra as regras */
        showMessage('R');
        break;
      case 3:
        /* A terceira opção mostra nossas informações */
        showMessage('A');
        break;
      case 4:
        /* A quarta opção é o return da função main, portanto encerra o programa */
				showMessage('E')
				return;
      default:
        printf("Que diabos você fez?\n");
				/*Depois do merge com a experimentalFeature1, caso alguem consiga ativar a linha acima, vá ao cartório e mude seu nome para Chuck Norris.*/
    }
  }
}

int main(){
	chamarMenu();
}
