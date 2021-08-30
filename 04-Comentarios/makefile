reemplazador: commentReplacer.o index.o stack.o
	gcc -o reemplazador index.o commentReplacer.o stack.o

index.o: index.c commentReplacer.h stack.h
	gcc -c index.c

commentReplacer.o: commentReplacer.c commentReplacer.h
	gcc -c commentReplacer.c

stack.o: stack.c stack.h
	gcc -c stack.c

# Comando en Windows equivalente a: reemplazador < prueba.c
# Get-Content .\prueba.c | .\reemplazador.exe