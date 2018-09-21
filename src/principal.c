/*BIBLIOTECAS PADRÕES DE C*/
#include <stdio.h>
#include <ctype.h>

/*BIBLIOTECAS DO PROJETO*/
#include "./menu/menu.h"
#include "iniciarJogo.h"
#include "./regras/regras.h"
#include "./sobre/sobre.h"

int main() {

  /*O laço que é executado até o usuário pedir para sair.*/
  for( ; ; ){
    /* Esta parte do programa chama uma função que mostra um menu para o usuário
    com quatro opções.
    1. Iniciar Jogo.
    2. Regras e dicas.
    3. Sobre.
    4. Sair.

    e retorna um inteiro correspondente à opção.*/
    int opcao = exibirMenu();

    /* A próxima parte do programa é um switch que faz uma determinada ação dependendo da opção escolhida */
    switch (opcao) {
      case 1:
        /* A primeira opção inicia o jogo */
        iniciarJogo();
        break;
      case 2:
        /* A segunda opção mostra as regras */
        exibirRegras();
        break;
      case 3:
        /* A terceira opção mostra nossas informações */
        exibirSobre();
        break;
      case 4:
        /* A quarta opção é o return da função main, portanto encerra o programa */
        return 0;
      default:
        printf("OPÇÃO INVÁLIDA\n");
    }
  }
}
