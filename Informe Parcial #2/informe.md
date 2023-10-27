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


## Diseño de Solución (Propenso a muchos cambios)

<div align="center">
  <img src="https://i.imgur.com/bqWsBLu.png1" width="400" height="300">
</div>

### Explicación de Solución

Realizando bien el análisis, nos percatamos de que en realidad son solamente necesarias dos clases, jugador y tablero, tablero contendrá todo lo correspondiente a su inicialización y gestión del juego, como colocar fichas en el mismo, entre otras cosas, jugador estará mezclado con los atributos de una ficha, esta decisión se tomó debido a que consideramos que las fichas están más ligadas a un jugador y sería más adecuado que tener una clase propia, por lo tanto, jugador tendría un nombre, cantidad de fichas en juego, entre otros métodos que verifiquen la validez de los movimientos propios del usuario. Por otra parte, en lugar de agregar métodos que no estén relacionados a una clase espécifica se decidió tener una libreria con funciones que no tienen que ver con las clases y de esta manera mantener las clases "limpias".

Todavía está la consideración de una tercera clase, para la validación todos los elementos de la ejecución del juego, sin embargo por ahora las clases tablero y jugador son las más importantes. 

### Clase Jugador:

#### Acceso Privado:

Inicialmente la clase jugador tendrá los siguientes atributos, con un acceso privado, de esta forma nos aseguramos que los únicos métodos que puedan acceder a estos atributos sean los de la clase:

    * Nombre: Cada jugador debe tener un nombre que lo identifique, ya que con un solo caracter no basta.

    * Representador: Para ser amigable con los jugadores, cada uno tiene un caracter que lo identifica en el tablero, esto es obligatorio para evitar la ambigüedad.

    * Posiciones en el arreglo: Más allá de que tenga una profunda relación con el tablero, el jugador es quién debe conocer qué posiciones ha ocupado en el tablero con sus fichas.

    * Es posible que exista algún atributo pendiente.

#### Acceso Público:

    * Constructores: En sinónimo porque estará definido el por defecto y mínimo uno sobrecargado.
    * Destructor: No fue mencionado pero al usar memoria dinámica es necesario el constructor para liberar la misma, ya que el por defecto no lo hace automático.
    * Métodos getter y setter.
    * Métodos de la clase por definir.

    El día sábado a más tardar el domingo se colocará una descripción de todos los métodos y las respetivas lógicas usadas.

### Clase Tablero:

Inicialmente la clase tablero tendrá los siguientes atributos, con un acceso privado, de esta forma nos aseguramos que los únicos métodos que puedan acceder a estos atributos sean los de la clase:

    Consideramos que es importante poder definir el tamaño del tablero apesar de que este siempre será 8x8 y para esto son las filas y columnas.
    * Filas: 
    * Columnas:
    * Tablero: Tablero de juego, posiblemente estático debido a que siempre es de un tamaño fijo, resulta mejor que usar memoria dinámica cuando no es necesario.

    * Direcciones Válidas: El tablero debe reconocer qué direcciones son válidas para el encierro de tipo sadunche.
    El juego es para dos jugadores por lo tanto tendrá dos instancias de la clase jugador.
    * Instancia Jugador 1: 
    * Instancia Jugador 2:

    El día sábado a más tardar el domingo se colocará una descripción de todos los métodos y las respetivas lógicas usadas.

#### Acceso Público:

    * Constructores: En sinónimo porque estará definido el por defecto y mínimo uno sobrecargado.
    * Destructor: No fue mencionado pero al usar memoria dinámica es necesario el constructor para liberar la misma, ya que el por defecto no lo hace automático.
    * Métodos getter y setter.
    * Métodos de la clase por definir, pero uno fijo es de impresión de la matriz de forma amigable.

    El día sábado a más tardar el domingo se colocará una descripción de todos los métodos y las respetivas lógicas usadas.

### Funcionalidades Externas:

Como se dijo anteriormente, hay funcionalidades que no tienen mucho que ver con los objetos, por lo tanto, se decidió agregar las funciones en un archivo aparte, ya que no tiene sentido desde nuestro punto de vista, crear una clase que no tenga atributos, pues no hay objetos no objetos que no tengan sus respectivas caracteristicas y en parte esto se debe tener en cuenta en el modelamiento.