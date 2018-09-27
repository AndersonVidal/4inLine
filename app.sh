#!/bin/bash

gcc -o app ./src/Menu/menu.c ./src/interface.c ./src/main.c

./app

rm -Rf app