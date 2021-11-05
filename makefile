all: main.o
	gcc -o a.out main.o

main.o: main.c
	gcc -c main.c
