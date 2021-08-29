reemplazador: commentReplacer.o preprocess.o
	gcc -o reemplazador preprocess.o commentReplacer.o

preprocess.o: preprocess.c commentReplacer.h
	gcc -c preprocess.c

commentReplacer.o: commentReplacer.c commentReplacer.h
	gcc -c commentReplacer.c