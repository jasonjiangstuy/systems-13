all: main.o csvFun.o
	gcc -o a.out main.o csvFun.o

main.o: main.c data.h csvFun.h
	gcc -c main.c

csvFun.o: csvFun.c data.h csvFun.h
	gcc -c csvFun.c

test: a.out
	./a.out -read_csv
	./a.out -read_data
	./a.out -add_data
	./a.out -read_data
	./a.out -update_data
	./a.out -read_data
