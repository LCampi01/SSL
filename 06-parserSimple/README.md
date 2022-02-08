Definicion Formal Automatas Finitos con Pila:
    Un Automata Finito con Pila(AFP) es un Automata Finito que además de tener estados y transiciones entre los
estados, como los Automatas Finitos, tiene una memoria en forma de PILA (stack). Estos Automatas ademas de reconocer a los Lenguajes regulares tienen la capacidad de reconocer expresiones aritmeticas y las sentencias de un Lenguaje de Programacion.

Un AFP está constituido por:
a) un flujo de entrada, infinito en una dirección, que contiene la secuencia de caracteres que debe
analizar, similar a un Automata Finito;
b) un control finito formado por estados y transiciones etiquetadas, similar a un Automata Finito; y
c) una pila abstracta, que establece la gran diferencia con los Automatas Finitos. Esta pila se representa como
una secuencia de símbolos o caracteres tomados de cierto alfabeto, diferente al alfabeto sobre el que
se construye un LIC reconocido por un AFP. En la pila, el primer carácter de la secuencia es el que
se encuentra en el tope de la pila (esto es solo una convención).

Formalmente un AFP se define como la 7-upla M = (E, A, A', T, e0, p0, F), donde:
– E es un conjunto finito de estados
– A es el alfabeto de entrada, cuyos caracteres se utilizan para formar la cadena a analizar
– A' es el alfabeto de la pila
– e0 es el estado inicial
– p0 es el símbolo inicial de la pila, el que indica que la pila no tiene símbolos
– F es el conjunto de estados finales
– T es la función T: E x (A  {ε}) x A' -> conjuntos finitos de E x A'*

Los estados se representan como nodos y las transiciones se representan como una funcion entre dos estados donde se especifica primero la entrada, y luego la operacion push o pop a realizar sobre la pila. En caso de ser una operacion de PUSH se especifica ENTRADA, λ, 1 y en caso de que la operacion sea POP se especifica ENTRADA, 1, λ.

La funcion pushString recibe un puntero a un arreglo de caracteres, de este se calcula la cantidad de caracteres para recorrer el arreglo de caracteres. En cada iteracion obtenemos un caracter que entra por parametro a la funcion push en cada iteracion y que como ya sabemos agrega a el caracter a la pila.