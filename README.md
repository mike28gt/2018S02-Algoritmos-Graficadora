# 2018S02-Algoritmos-Graficadora

# Graficador de Funciones Matemáticas

Se desea construir un programa en C++ que permita visualizar de forma gráfica ciertas
funciones matemáticas, las cuales serán ingresadas por el usuario.

El programa debe permitir graficar siete tipos de funciones, las cuales son:
1. Funciones de grado 1
2. Funciones de grado 2
3. Funciones de grado 3
4. Funciones de grado 4
5. Función trigonométrica seno
6. Función trigonométrica coseno
7. Función trigonométrica tangente

Como se sabe cada uno de este tipo de funciones hace uso de coeficientes numéricos, por lo
que el programa debe permitir el ingreso de estos coeficientes. Se debe tener en cuenta que
los coeficientes numéricos pueden ser cualquier número real.
El formato básico con el cual el usuario podrá ingresar la función a graficar para cada uno de
los tipos de funciones listados anteriormente es el siguiente:

1. Funciones de grado 1
Formato: ax + b
Valores por defecto: a tendrá el valor de 1 y b tendrá el valor de 0.

2. Funciones de grado 2
Formato: ax 2 + bx + c
Valores por defecto: a tendrá el valor de 1, b tendrá el valor de 1 y c tendrá el
valor de 0.

3. Funciones de grado 3
Formato: ax 3 + bx 2 + cx + d
Valores por defecto: a tendrá el valor de 1, b tendrá el valor de 1, c tendrá el
valor de 1 y d tendrá el valor de 0.

4. Funciones de grado 4
Formato: ax 4 + bx 3 + cx 2 + dx + e
Valores por defecto: a tendrá el valor de 1, b tendrá el valor de 1, c tendrá el
valor de 1, d tendrá el valor de 1 y e tendrá el valor de 0.
Segundo Proyecto - Algoritmos

5. Funcione trigonométrica seno
Formato: a * sen(bx + c) + d
Valores por defecto: a tendrá el valor de 1, b tendrá el valor de 1, c tendrá el
valor de 0 y d tendrá el valor de 0.

6. Funcione trigonométrica coseno
Formato: a * cos(bx + c) + d
Valores por defecto: a tendrá el valor de 1, b tendrá el valor de 1, c tendrá el
valor de 0 y d tendrá el valor de 0.

7. Funcione trigonométrica tangente
Formato: a * tan(bx + c) + d
Valores por defecto: a tendrá el valor de 1, b tendrá el valor de 1, c tendrá el
valor de 0 y d tendrá el valor de 0.

# Restricciones para el plano cartesiano

La gráfica se debe dibujar sobre un plano cartesiano. Este plano cartesiano debe cumplir con
los siguientes requerimientos:
• Se deben dibujar los ejes en color blanco. Estos ejes deben ser visibles cuando se grafique
la función.
• Los dos ejes deben intersectarse por la mitad de forma perpendicular para dibujar cuatro
cuadrantes.
• En donde se intercepten los ejes será el punto (0,0) de dicho plano.
• La longitud de cada eje debe ser de 400 pixeles en total.

# Restricciones para la presentación de la gráfica

La gráfica a dibujar debe cumplir con los siguientes requerimientos:
• Las líneas/pixeles que determinen la gráfica deben dibujarse en color verde.
• Se debe solicitar al usuario el limite inferior y superior del dominio (inicio y fin) que se desee
utilizar para la generación de la gráfica. Estos deben ser números enteros positivos. En
dado caso se ingrese un número negativo o real se debe mostrar un error indicando lo
anterior y se debe solicitar nuevamente que se ingrese el rango de la gráfica generar.
• Se debe dibujar únicamente la sección de la gráfica a la que pertenezca el dominio
ingresado.
• Si el dominio ingresado por el usuario excede la capacidad del eje x se debe utilizar el valor
máximo posible del dominio dada la longitud del eje x.
Segundo Proyecto - Algoritmos
• El rango de la función no debe exceder el limite establecido por el eje y. Si este se
excediera se debe graficar únicamente la sección que pueda ser visualizada dentro del
límite de la longitud del eje indicado.
• El usuario debe poder ingresar el tamaño del paso mediante el cual se incrementará el
valor del dominio para graficar la función. El tamaño de paso debe ser un número real
positivo; si se ingresa un valor diferente se debe mostrar un error y solicitar nuevamente el
tamaño del paso. Cuando se utilicen pasos pequeños la gráfica quedará mejor definida que
cuando se utilicen pasos grandes.
