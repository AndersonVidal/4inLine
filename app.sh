#!/bin/bash

gcc -o app ./src/jogo/interfaceGame.c ./src/render/render.c ./src/Menu/menu.c ./src/jogo/jogo.c ./src/jogo/gameloop.c ./src/interface.c ./src/main.c ./src/ia/ia.c

./app

rm -Rf app
