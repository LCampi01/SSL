reemplazador: commentReplacer.o index.o
	gcc -o reemplazador index.o commentReplacer.o

index.o: index.c commentReplacer.h
	gcc -c index.c

commentReplacer.o: commentReplacer.c
	gcc -c commentReplacer.c