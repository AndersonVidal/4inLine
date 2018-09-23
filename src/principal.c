/*BIBLIOTECAS PADRÕES DE C*/
#include <stdio.h>
#include <ctype.h>

/*BIBLIOTECAS DO PROJETO*/
#include "./menu/menu.h"
#include "iniciarJogo.h"
#include "./showMessage/showMessage.h"

int main() {
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
				return 0;
      default:
        printf("Que diabos você fez?\n");
				/*Depois do merge com a experimentalFeature1, caso alguem consiga ativar a linha acima, vá ao cartório e mude seu nome para Chuck Norris.*/
    }
  }
}
