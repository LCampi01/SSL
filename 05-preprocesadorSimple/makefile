preprocessor: main.o preprocess.o symbolTable.o
	gcc -g -o preprocessor preprocess.o main.o symbolTable.o

main.o: main.c preprocess.h
	gcc -g -c main.c 

preprocess.o: preprocess.c preprocess.h symbolTable.h
	gcc -g -c preprocess.c 

symbolTable.o: symbolTable.c symbolTable.h
	gcc -g -c symbolTable.c