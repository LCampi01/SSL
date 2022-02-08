## 03-Máquinas de Estado — Histograma de longitud de palabras

------------


### Objetivos
- Aplicar los conceptos de modularización
- Utilizar las herramientas de compilación y construcción de ejecutables estudiadas
- Aplicar máquinas de estado para el procesamiento de texto.
- Implementar máquinas de estado con diferentes métodos.

### Temas
- Árboles de expresión.
- Representación de máquinas de estado.
- Implementación de máquinas de estado.
- Arreglos
- Flujos
- Modularización


### Tareas
1. Árboles de Expresión
a. Estudiar el programa del ejemplo las sección 1.5.4 Conteo de Palabras de [KR1988].
b. Dibujar el árbol de expresión para la inicialización de los contadores: 
nl = nw = nc = 0.
c. Dibujar el árbol de expresión para la expresión de control del segundo if:
c == ' ' || c == '\n' || c == '\t'.
2. Máquina de Estado:
a. Describir en lenguaje dot ??? y dentro del archivo histograma.gv la máquina de estado que resuelve el problema planteado.
b. Formalizar la máquina de estados como una n-upla, basarse en el Capítulo #1 del Volumen #3 de [MUCH2012].
3. Implementaciones de Máquinas de Estado:
Las implementaciones varían en los conceptos que utilizan para representaar los estados y las transiciones.
a. Implementación #1: Una variable para el estado actual.
i. Escribir el programa histograma-1-enum-switch.c que siga la
Implementación #1, variante enum y switch.
Esta implementación es la regularización de la implementación de la sección 1.5.4 de [KR1988]. Los estados son valores de una variable y las transiciones son la selección estructurada y la actualización de esa variable. Esta versión es menos eficiente que la versión de [KR1988], pero su regularidad permite la automatización de la construcción del programa que implementa la máquina de estados. Además de la regularidad, esta versión debe:
• Utilizar typedef y enum en vez de define, de tal modo que la
variable estado se pueda declarar de la siguiente manera: State s = Out;
• Utilizar switch en vez de if.
ii. Responder en readme.md: Indicar ventajas y desventajas de la versión de [KR1988] y de esta implementción.
b. Implementación #2: Sentencias goto (sí, el infame goto)
i. Leer la sección 3.8 Goto and labels de [KR1988]
ii. Leer Go To Statement Considered Harmful de [DIJ1968].
iii. Leer "GOTO Considered Harmful" Considered Harmful de [RUB1987].
iv. Responder en readme.md: ¿Tiene alguna aplicación go to hoy en día? ¿Algún lenguaje moderno lo utiliza?
v. Escribir el programa histograma-2-goto.c que siga la
Implementación #2. En esta implementación los estados son etiquetas y las transiciones son la selección estructurada y el salto incondicional con la sentencia goto.
c. Implementación #3: Funciones Recursivas
i. Leer la sección 4.10 Recursividad de [KR1988].
ii. Responder en readme.md: ¿Es necesario que las funciones accedan a contadores? Si es así, ¿cómo hacerlo?.
Leer la sección 1.10 Variables Externas y Alcance y 4.3 Variables Externas de [KR1988].
iii. Escribir el programa, histograma-3-rec.c que siga la implementación #3.
En esta implementación los estados son funciones recursivas y las transiciones son la selección estructurada y la invocación recursiva.
d. Implementación #X:
Es posible diseñar más implementaciones. Por ejemplo, una basada en una tabla que defina las transiciones de la máquina. En ese caso, el programa usaría la tabla para lograr el comportamiento deseado. El objetivo de este punto es diseñar una implementación diferente a las implementaciones #1, #2, y #3.
i. Diseñar una nueva implementación e indicar en Readme.md cómo esa
implementación representa los estados y cómo las transiciones.
ii. Escribir el programa, histograma-x.c que siga la nueva
implementación.
4. Escribir un único programa de prueba para las cuatro implementaciones.
Construir una tabla comparativa a modo de benchmark que muestre el tiempo de procesamiento para cada una de las cuatro implementaciones, para tres archivos diferentes de tamaños diferentes, el primero en el orden de los kilobytes, el
segundo en el orden de los megabytes, y el tercero en el orden de los gigabytes.


### Restricciones
- La implementación de la máquina de estado debe ser "seleccionable".
Algunas formas posibles de implementar la selección son:
◦ En tiempo de traducción desde el makefile.
◦ En de tiempo de ejecución mediante reemplazlo de dynamic link library.
◦ En de tiempo de ejecución mediante argumentos de la línea de comandos.
- La solución debe estar modularizada: las máquinas de estado no deben
conocer del graficador y viceversa.
- Desde main.c se coordina todo.


~~--------------------------------------------------------------------------------~~


### Resolución
 - 1.b:
------------
![1-b](https://user-images.githubusercontent.com/63361800/127400787-27fc9617-11b3-4e1e-840c-a13771b2185d.jpeg)
 - 1.c:
------------
 ![1-c](https://user-images.githubusercontent.com/63465251/125211957-7ade1c80-e280-11eb-8438-6e033f6a7fac.jpeg)
 
~~--------------------------------------------------------------------------------~~
 - 2.b:

5-upla del autómata definido M = (Q, E, T, q0, F):

Q = {OUT, IN} -> Conjunto de estados

E = Todos los caracteres -> Alfabeto reconocido por el autómnata

q0 = OUT -> Estado inicial

F = {OUT, IN} -> Conjunto de estados finales

T -> Función trancisión

Para facilitar la definición de la función trancisión, definimos:
Caracter de escape = {'\t', '\n', ' '}
Caracter de palabra = Caracteres - {'\t', '\n', ' '}

T = {OUT => Caracter de escape => OUT, OUT => Caracter de palabra => IN,  IN => Caracter de escape => OUT, IN => Caracter de palabra => IN}

![2-b](https://user-images.githubusercontent.com/63361800/127403756-29f1977b-54f0-468c-8cd3-437e6d2375c9.jpeg)

~~--------------------------------------------------------------------------------~~  
 - 3.a:
En la versión de K&R, se utiliza una versión con while:
```c
		#include <stdio.h>
		main( )
		{
		int c, nl, nw, nc, state;
		state = OUT;
		nl = nw = nc = 0;
		while ((c=getchar( ))!=EOF) {
			++nc;
			if (c=='\n')
				++nl;
			if (c==' ' || c=='\n' || c=='\r')
				state = OUT;
			else if (state==OUT) {
				state = IN;
				++nw;
			}
		}
		printf ("%d %d %d\n", nl, nw, nc);
		}
```
Una ventaja de esta implementación es que el código es más ordenado ya que ejecutamos el conjunto de sentencias, en este caso, según al estado en el que se encuentra la máquina y el tipo de caracter que recibe. Pero una principal desventaja, es que se pierde eficiencia debido a que se tienen que evaluar cada condición hasta que se pueda obtener el valor de verdad de la expresión y esto podría tomar más tiempo según la expresión contenida en cada if-else.
Por otro lado, está la implementación realizada con la instrucción Switch. La ventaja que tiene esta instrucción es la de poder decidir a qué parte del código se quiere "saltar" (Switch realiza esto mediante etiquetas) y esto, a comparación del if, gana tiempo en eficiencia ya que no tiene que evaluar una condición sino que evalua un valor para decidir a qué etiqueta ir. Pero una desventaja que tiene, es que no se puede evaluar cualquier valor, sino que solo puede evaluar caracteres y valores enteros (A diferencia de If que puede evaluar enteros, caracteres, punteros, etc.).

~~--------------------------------------------------------------------------------~~

 - 3.b:
 En lenguajes no tan modernos el GO TO tiene cierta utilidad como la de poder salir definitivamente de ciclos dentro de ciclos en lugar de poner una verificación y un break en cada una ellos.
 Los lenguajes modernos no lo utilizan ya que las pocas aplicaciones que el GO TO ofrece en lenguajes modernos como java, por ejemplo, se pueden reemplazar por otras sentencias. En este caso por ejemplo con la sentencia "break n" siendo n el numero de ciclos de los cuales se quiere salir.
 
~~--------------------------------------------------------------------------------~~
 
 - 3.c:
No es necesario que las funciones accedan todo el tiempo al contador. En nuestro caso, estamos pasando un puntero al contador y de esta manera nos estamos ahorrando el tener que pasar el contador completo. Esto nos permite ganar eficiencia al no tener que estar trasladando la estructura completa por todo el programa.

~~--------------------------------------------------------------------------------~~

 - 3.d:
La implementación desarrollada fue realizada con recursividad, la cual representa los estados pasándolos como argumento de una función y las trancisiones son representadas mediante la validación del estado recibido como argumento. Podemos ver los estados en el call stack, ya que visualizamos allí cada invocación a la función.
 
~~--------------------------------------------------------------------------------~~
