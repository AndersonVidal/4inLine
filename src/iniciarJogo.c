#include <stdio.h>
#include "iniciarJogo.h"

/*BIBLIOTECAS DO PROJETO*/
#include "./tabuleiro/tabuleiro.h"
#include "./placar/placar.h"

void iniciarJogo(){
  /*
  esta função serve para:
  1. estocar os valores do placar.
  2. chamar o tabuleiro para cada partida.
  3. modificar o número de vitórias ou derrotas.
  4. chamar a janela de placar.

  */
  int vitorias = 0; /* número de vitórias */
  int derrotas = 0; /* número de derrotas */
  int empates = 0; /* número de empates */
  /*
  loop principal
  */
  for( ; ; ){
    /*
    a parte abaixo chama a função chamarTabuleiro, esta função retorna um inteiro de acordo com o padrão:
    - 1 caso o usuário tenha vencido.
    - 0 caso o usuário tenha perdido.
    mais desta função no arquivo tabuleiro.c
    */

    switch ( exibirTabuleiro() ) {
      case 0:
        derrotas++;
        break;
      case 1:
        vitorias++;
        break;
      case 2:
        empates++;
        break;
    }

    /*
    a parte abaixo chama uma função chamarPlacar, esta função retorna dois possíveis valores:
    - 0 caso o usuário queira jogar denovo para modificar o placar, neste caso o if abaixo executará seu código
    - 1 caso o usuário queira voltar para o menu principal, neste caso a própria função startGame encerrará e a execução voltaria para o arquivo principal
    mais da função chamarPlacar no arquivo placar.c
    */
    if ( exibirPlacar(vitorias, derrotas, empates) == 1 ){
      return;
    }

  }

}
