main.o: main.c server.h
	gcc -Wall -Wstrict-prototypes -ansi -pedantic -c main.c
server.o: server.c server.h
	gcc -Wall -Wstrict-prototypes -ansi -pedantic -c server.c
main: main.o server.o
	gcc main.o server.o -o main