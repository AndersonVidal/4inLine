
all: app
app: main.o interface.o menu.o
	gcc -o app main.o interface.o menu.o

main.o: main.c
	gcc -o main.o -c main.c -W -Wall -ansi -pendantic
interface.o: interface.c interface.h menu.h
	gcc -o interface.o -c interface.c -W -Wall -ansi -pedantic
menu.o: menu.c menu.h
	gcc -o menu.o -c menu.c -W -Wall -ansi -pendantic
clean:
	rm -rf *.o
mrproper: clean
	rem -rf app