histograma: main.o histograma-1-enum-switch.o histograma-2-goto.o histograma-3-rec.o histograma-4-argumento.o Graficador.o
	gcc -o histograma main.o histograma-1-enum-switch.o histograma-2-goto.o histograma-3-rec.o histograma-4-argumento.o Graficador.o -std=c99

Test: Test.o histograma-1-enum-switch.o histograma-2-goto.o histograma-3-rec.o histograma-4-argumento.o 
	gcc -o Test Test.o histograma-1-enum-switch.o histograma-2-goto.o histograma-3-rec.o histograma-4-argumento.o -std=c99

histograma-1-enum-switch.o: histograma-1-enum-switch.c
	gcc -c histograma-1-enum-switch.c

main.o: main.c Graficador.h
	gcc -c main.c

Test.o: Test.c
	gcc -c Test.c

histograma-2-goto.o: histograma-2-goto.c
	gcc -c histograma-2-goto.c

histograma-3-rec.o: histograma-3-rec.c
	gcc -c histograma-3-rec.c

histograma-4-argumento.o: histograma-4-argumento.c
	gcc -c histograma-4-argumento.c

Graficador.o: Graficador.c Graficador.h
	gcc -c Graficador.c
