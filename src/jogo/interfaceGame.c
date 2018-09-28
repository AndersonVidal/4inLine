#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "jogo.h"
#include "gameloop.h"
#include "../render/render.h"


void interface_game_loop(void) {
    int jogador = 0;
    int ia = 0;
    int status;
    do {
        int ganhador = gameloop();

        if (ganhador == 1) {
            jogador ++;
            printf("\n\tVOCÊ VENCEU !!!!\n");
        } else if (ganhador == 2) {
            ia ++;
            printf("\n\tVOCÊ PERDEU :( .....\n");
        } else {
            printf("\n\tVOCÊ NÃO GANHOU, MAS TAMBEM NAO PERDEU e.e\n");
        }

        exibirPlacar(jogador, ia);

        status = lerRepeatRespostaJogador();

    } while(status);

}