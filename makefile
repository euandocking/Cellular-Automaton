#makefile
all: mainMenu.o automata.o
	gcc -o main mainMenu.o automata.o

mainMenu.o: mainMenu.c automata.h
	gcc -c mainMenu.c

automata.o: automata.c automata.h
	gcc -c automata.c