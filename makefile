all: main.o csvFun.o
	gcc -o a.out main.o csvFun.o

main.o: main.c data.h csvFun.h
	gcc -c main.c

csvFun.o: csvFun.c data.h csvFun.h
	gcc -c csvFun.c
