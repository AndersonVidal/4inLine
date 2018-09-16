// C STANDARD LIBRARIES
#include <stdio.h>
#include <ctype.h>

// PROJECT LIBRARIES
/* não alterei esta parte, mas subentenda a importação de tudo que for necessário */
#include "menu.h"
#include "createGame.h"
#include "rules.h"
#include "about.h"


int main() {

  /*O programa em si é um laço que é executado até o usuário pedir para sair, li que este for é a forma mais adequada de laço infinito no c .*/
  for( ; ; ){
    /*
    esta parte do programa chama uma função que mostraria um menu para o usuário com quatro opções.
    1. Iniciar Jogo.
    2. Regras e dicas.
    3. Sobre.
    4. Sair.

    e retornaria um inteiro correspondente à opção.

    */
    int option = showMenu();

    /* A próxima parte do programa é um switch que faz uma determinada ação dependendo da opção escolhida */
    switch( option ){
      case 1:
      /* a primeira opção é a mais complexa, ela deve fazer essencialmente três coisas: o cadastro, o gameplay e o placar, discorrerei sobre ela em outro arquivo */
        startGame();
        break
      case 2:
      /* A segunda opção mostra as regras */
        showRules();
        break;
      case 3:
      /* terceira opção mostra nossas informações */
        about();
        break;
      case 4:
      /* a quarta opção é o return da função main, portanto encerra o programa */
        return 0;

    }
  }
}
