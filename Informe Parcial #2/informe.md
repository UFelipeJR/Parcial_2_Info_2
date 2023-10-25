# Parcial 2 Informática II

## Breve Conceptualización del Problema:

Se debe implementar el juego otello con POO en el lenguaje de programación C++, tomando todas las pautas descritas en el enunciado, durante conceptualización se jugaron unas cuantas partidas del juego, para comprender en su totalidad el funcionamiento del mismo. Otello se resume en un tablero de 8 filas y 8 columnas, en el que estas están nombradas con letras del abecedario y números respetivamente; se inicia el juego con dos fichas en el centro por cada jugador puestas diagonalmente y básicamente la mecánica principal es encerrar la mayor cantidad de piezas del contrincante haciendo encierros horizontales, verticales y diagonales, se deben realizar validaciones para evitar colocar fichas en posiciones indebidas.

El problema pide implementar una versión de Otello con nuestra propia lógica, haciendo uso eficiente de memoria y tratando de que los algoritmos propuestos puedan ser reutilizados posteriormente para tableros de dimensiones distintas.


## Consideraciones Solución del Problema

La propuesta de la solución considera el uso de tres clases.

* Jugador
En esta clase se definirían cosas como el nombre del jugador, su caracter o color representativo, probablemente esta incluya la cantidad de fichas, y las posiciones en las que estas están colocadas, por otra parte se planea que esta clase contenga métodos para calcular posiciones, el comportamiento de las fichas propias de cada jugador incluyendo el encierro tipo sanduche.

* Tablero
En esta clase se hace la inicialización del tablero, aplicación de movimientos, validar la legalidad de los mismos y generar los deplazamientos necesarios, por otra parte contendrá métodos que permitan la visualización amigable del tablero.

* Juego
Clongomerado de las clases principales, jugador y tablero, pero acá se hacen los inputs, y ese tipo de cosas para hacer del juego amigable, en pocas palabras se incluye todo lo que se relaciona con el funcionamiento en consola del juego.

* Por otra parte, hay cosas que no están directamente relacionadas con los objetos, por lo que tendríamos un archivo de funcionalidad dedicados a la lectura y escritura de archivos.
