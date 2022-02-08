Automatico: lex.yy.o y.tab.o symbolTable.o stack.o
	gcc -g -o Automatico y.tab.o lex.yy.o symbolTable.o stack.o

lex.yy.o: lex.yy.c y.tab.h
	gcc -g -c lex.yy.c

y.tab.o: y.tab.c symbolTable.h stack.h
	gcc -g -c y.tab.c

stack.o: stack.c
	gcc -g -c stack.c

symbolTable.o: symbolTable.c symbolTable.h
	gcc -g -c symbolTable.c

