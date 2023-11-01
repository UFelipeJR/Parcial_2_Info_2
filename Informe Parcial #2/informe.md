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

Realizando bien el análisis, nos percatamos de que en realidad son solamente necesarias tres clases, jugador, tablero y juego, tablero contendrá todo lo correspondiente a su inicialización y gestión del juego, como colocar fichas en el mismo, entre otras cosas, jugador estará mezclado con los atributos de una ficha, esta decisión se tomó debido a que consideramos que las fichas están más ligadas a un jugador y sería más adecuado que tener una clase propia, por lo tanto, jugador tendría un nombre, cantidad de fichas en juego, entre otros métodos que verifiquen la validez de los movimientos propios del usuario. En el caso de juego será el conglomerado de las anteriores clases.

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


### Clase juego

Acá se conglomeran las clasea anteriores.

## Lógica de la Solución

### Comprobación de la Validez de una Jugada

Se utiliza un método que recibe como argumento el número del jugador, la fila y la columna que se desea evaluar, se hacen varias deficiones, para guardar los caracteres representativos de cada jugador y se inician las coordenadas X y Y en un tipo de variable short, ya que no se necesita representar valores más grandes; después se procede con una validación en la que se comprueba si la posición es diferente de ' ', es decir un caracter vacio, puesto que esto ahorraría  muchas iteraciones si resulta ser falsa la condición.Después se fija el jugadorP o principal, y el jugadorS o secundario, haciendo uso de punteros para evitar la creación de variables y tener una sola definición funcional en todo el código por así decirlo.

La clase tablero tiene un arreglo que almacena las posibles direcciones en las que se puede hacer un encierro tipo sanduche, por lo tanto se inicia un for que comprobará cada una de las direcciones, después se hace una comprobación para comprobar que que las coordenadas X y Y siguen estando en un rango válido y que en estas casillas esté el caracter del jugador secundario, después si esto resulta verdadero se avanza en la misma dirección para comprobar si hay una ficha del jugadorP, si no se cumple nada se retorna false.


//Complementar explicación ya que posiblemente tendrá errores o no es tan clara
