parser:  parser.o stack.o
	gcc -o parser parser.o stack.o

parser.o: parser.c stack.h
	gcc -c parser.c

stack.o: stack.c stack.h
	gcc -c stack.c