#!/bin/bash

gcc -o app ./src/Menu/menu.c ./src/jogo/jogo.c ./src/jogo/gameloop.c ./src/interface.c ./src/main.c

./app

rm -Rf app
