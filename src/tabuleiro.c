#include <stdio.h>

/*
  a função abaixo serve para:
  1. criar e armazenar um tabuleiro do Jogo
  2. pedir jogadas do jogador e da IA
  3. avaliar o resultado de cada jogada vendo se alguém ganhou
*/
int chamarTabuleiro(){
    /*
    tabuleiro do jogo:
    0 - espaço vazio
    1 - jogador
    2 - IA
    */
    int tabuleiro[7][6];

    /*
     uma variável para armazenar o estado atual do tabuleiro:
     -1 caso ninguém tenha ganhado
      0 caso o usuário tenha perdido
      1 caso o usuário tenha ganhado
      2 caso tenha dado empate
    */
    int resultadoAtual = -1;

    for( ; ; ){
      /*
      o bloco abaixo chama a função pedirJogada recebe a jogada do usuário e modifica o tabuleiro de acordo com a jogada,
      depois o tabuleiro é avaliado e o resultado é armazenado na variável resultadoAtual
      se o resultado for diferente de -1(jogo acabou) retorna o resultado.
      */
      pedirJogada(tabuleiro);
      resultadoAtual = avaliar(tabuleiro);
      if(resultadoAtual != -1){
        return resultadoAtual;
      }

      /*
      o bloco abaixo chama a função pedirJogada recebe a jogada do IA e modifica o tabuleiro de acordo com a jogada,
      depois o tabuleiro é avaliado e o resultado é armazenado na variável resultadoAtual
      se o resultado for diferente de -1(jogo acabou) retorna o resultado.
      */
      aiJogar(tabuleiro);
      resultadoAtual = avaliar(tabuleiro);
      if(resultadoAtual != -1){
        return resultadoAtual;
      }

      /*
      caso o resultado de resultadoAtual seja -1 o laço principal roda novamente
      */

    }



}
