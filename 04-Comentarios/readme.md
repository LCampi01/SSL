## 04-Máquinas de Estado — Sin comentarios

------------


### Objetivos
- El objetivo es diseñar una máquina de estado que remueva comentarios,
implementar dos versiones, e informar cual es la más eficiente mediante un
benchmark.

### Restricciones
-  Primero diseñar y especificar la máquina de estado y luego derivar dos
implementaciones.
- Utilizar el lenguaje dot para dibujar los digrafos.
-  Incluir comentarios de una sola línea (//).
- Considerar las variantes no comunes de literales carácter y de literales
cadenas que son parte del estándar de C.
- Diseñar el programa para que pueda invocarse de la siguiente manera:
RemoveComments < Test.c > NoComments.c.
- Ninguna de las implementaciones debe ser la Implementación #1: estado
como variable y transiciones con selección estructurada.
- Indicar para la implementación cómo se representan los estados y cómo las
transiciones.
- Respetar la máquina de estado especificada, en cada implementación utilizar
los mismos nombres de estado y cantidad de transiciones.
- En el caso que sea necesario, utilizar enum, y no define
- Diseñar el archivo Makefile para que construya una, otra o ambas
implementaciones, y para que ejecute las pruebas.

------------

La implementación desarrollada fue realizada con recursividad, la cual representa los estados pasándolos como argumento de una función y las trancisiones son representadas mediante la validación del estado recibido como argumento. Podemos ver los estados en el call stack, ya que visualizamos allí cada invocación a la función.
