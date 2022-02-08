preprocessBrackets: preprocessBrackets.o scanner.o parser.o symbolTable.o stack.o
	gcc -g -o preprocessBrackets preprocessBrackets.o scanner.o parser.o symbolTable.o stack.o

preprocessBrackets.o: preprocessBrackets.c parser.h
	gcc -g -c preprocessBrackets.c

scanner.o: scanner.c scanner.h
	gcc -g -c scanner.c

parser.o: parser.c symbolTable.h stack.h
	gcc -g -c parser.c

stack.o: stack.c
	gcc -g -c stack.c

symbolTable.o: symbolTable.c symbolTable.h
	gcc -g -c symbolTable.c
