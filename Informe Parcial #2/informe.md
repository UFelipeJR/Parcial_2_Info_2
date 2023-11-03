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
  //NUEVA IMAGE FALTA
</div>

### Explicación de Solución

Realizando bien el análisis, nos percatamos de que en realidad son solamente necesarias tres clases, jugador, tablero y juego, tablero contendrá todo lo correspondiente a su inicialización y gestión del juego, como colocar fichas en el mismo, entre otras cosas, jugador estará mezclado con los atributos de una ficha, esta decisión se tomó debido a que consideramos que las fichas están más ligadas a un jugador y sería más adecuado que tener una clase propia, por lo tanto, jugador tendría un nombre, cantidad de fichas en juego, entre otros métodos que verifiquen la validez de los movimientos propios del usuario. En el caso de juego será el conglomerado de las anteriores clases.

### Clase Juego:

#### Acceso Privado:

La clase juego tendrá los atributos siguientes, con acceso privado, para asegurarnos que estos solo sean accedidos por lo mismo metodos de la misma clase.

    * Caracteres Iniciales para nuestro juego, tal y como serán * y -
    * Dimensión de tablero: Primordial pues este determina la dimension del tablero para jugar
    * Ganador: como el nombre lo dice, sera un atributo esencial para guardar en el historial el que gané una partida
    * Historial: Llevado desde un archivo, sera todo el registro de las partidas previas.

#### Acceso Publico:

    * Constructores de la clase: Uno por defecto, otro que recibe la dimensión del tablero (sobrecargado)
    * Cargar Historial: Encargado de leer el archivo con el registro de las partidas previas
    * Menu y Menu Juego: Encargados de dar una entrada amigable al juego y el otro para dar un heads-up diagram para el juego
    * La plantilla para tener control de lo que entra en el programa, muy util para el debug y para evitar entradas erroneas y repetir el proceso
    * Generar fecha: Encargada de tomar el dia, mes, año, hora y toda esta metadata para escribirla en el archivo de texto
    * Entrada Array: Recibe la jugada
    * Guardar cambios: guarda lo previamente definido para el archivo lo escribe y se cierra.
    * Metodos getter y setter
    
### Clase Jugador:

#### Acceso Privado:

Inicialmente la clase jugador tendrá los siguientes atributos, con un acceso privado, de esta forma nos aseguramos que los únicos métodos que puedan acceder a estos atributos sean los de la clase:

    * Nombre: Cada jugador debe tener un nombre que lo identifique, ya que con un solo caracter no basta.
    * Representador: Para ser amigable con los jugadores, cada uno tiene un caracter que lo identifica en el tablero, esto es obligatorio para evitar la ambigüedad.
    * Cantidad de Fichas: Para llevar cuenta de cuantas tiene cada jugador en el tablero

#### Acceso Público:

    * Constructores: Uno por defecto y uno sobrecargado que lleva el nombre del jugador y su respectivo carácter
    * Métodos getter y setter.

### Clase Tablero:

Inicialmente la clase tablero tendrá los siguientes atributos, con un acceso privado, de esta forma nos aseguramos que los únicos métodos que puedan acceder a estos atributos sean los de la clase:

    Consideramos que es importante poder definir el tamaño del tablero apesar de que este siempre será 8x8 y para esto son las filas y columnas.
    * Filas
    * Columnas
    * Tablero: Tablero de juego dinámico pues termina siendo dimensiones distintas en tiempo de ejecución
    * Direcciones Válidas: El tablero debe reconocer qué direcciones son válidas para el encierro de tipo sadunche.
    El juego es para dos jugadores por lo tanto tendrá dos instancias de la clase jugador.
    * Instancia Jugador 1: 
    * Instancia Jugador 2:
    
#### Acceso Público:

    * Constructores: En sinónimo porque estará definido el por defecto y uno sobrecargado que lleva el numero de filas, columnas, nombre del jugador1, nombre del jugador2.
    * Destructor: No fue mencionado pero al usar memoria dinámica es necesario el constructor para liberar la misma, ya que el por defecto no lo hace automático.
    * Métodos getter y setter.
    * Métodos para Imprimir mátriz: tales como fila amigable, numeracion fila, imprimir tablero e inicializar tablero.
    * Validez de Jugada y realizar Jugada: Funciones primordiales para la logica y funcionamiento de nuestro juego pues una esta encargada de verificar si el movimiento es legal y el otro de realizarlo tal cual como
      se presencio en el juego
    * Actualizar cant de fichas: basicamente lo que menciona el nombre de este metodo, actualiza la cantidad de fichas en tiempo de ejecución
    * contador de Jugadas: Da en pantalla la cantidad de jugadas disponibles en juego.
    * Métodos getter y setter
    
## Lógica de la Solución

En el estado preliminar de realizar nuestra solución tomamos ean consideración diferentes clases para implementar, al final de nuestro proyecto llegamos a la conclusión de que sería apropiado tener tres clases, una para jugador otra para tablero y juego que abarca las previamente mencionadas, cada una con su respectiva ventaja con respecto a nuestra manera de trabajar y de gestionar la información durante ejecución, tuvimos diferentes consideraciones respecto a la clase juego pues en un momento la vimos innecesaria, más sin embargo fue implementada para lo mencionado antes, gestionar y controlar la información que se recolecta.

### Comprobación de la Validez de una Jugada

Se utiliza un método que recibe como argumento el número del jugador, la fila y la columna que se desea evaluar, se hacen varias definiciones, para guardar los caracteres representativos de cada jugador y se inician las coordenadas X y Y en un tipo de variable short, ya que no se necesita representar valores más grandes; después se procede con una validación en la que se comprueba si la posición es diferente de ' ', es decir un caracter vacio, puesto que esto ahorraría  muchas iteraciones si resulta ser falsa la condición.Después se fija el jugadorP o principal, y el jugadorS o secundario, haciendo uso de punteros para evitar la creación de variables y tener una sola definición funcional en todo el código por así decirlo.

La clase tablero tiene un arreglo que almacena las posibles direcciones en las que se puede hacer un encierro tipo sanduche, por lo tanto se inicia un for que comprobará cada una de las direcciones, después se hace una comprobación para comprobar que que las coordenadas X y Y siguen estando en un rango válido y que en estas casillas esté el caracter del jugador secundario, después si esto resulta verdadero se avanza en la misma dirección para comprobar si hay una ficha del jugadorP, si no se cumple nada se retorna false.

### Realización de una Jugada

Para realizar una jugada, se utilizara un metodo que recibe el resultado del previo algoritmo (comprobacion de la validez de la jugada) y calcula la posición que va a jugar el usuario con respecto a su turno, base a esto se utilizan distintos ciclos encargados de verificar el acmino que forma la ficha al hacer el tipo sandwich y toma en consideración las posiciones en el arreglo que tendra que cambiar, tal y para cambiar por ejemplo que cuando llega y se forma una diagonal, el algoritmo va y busca la diagonal como tal.

## Experiencia e Aprendizaje

El desarrollo del pensamiento para pogramar enfocado a objetos, un acercamiento a como se deberia de modelar y cuantas cosas en verdad se deben de tomar en consideración a la hora de atajar algun tipo de problema que requiera esta modalidad de programación, que por lo visto la mayor parte se pueden realizar desde esto, nuestra experiencia fue bastante positiva pues al momento de empezar a modelar teniamos bastante clara la manera en que definimos las cosas, sin embargo a la hora de implementar los algoritmos para que el juego funcionara correctamente, la validez y realizar las jugadas fue lo más complicado pues estas requerian de algun modo que estuvieran relacionadas entre sí y que permitieran como tal simular lo que hace el othello originalmente, nos conllevo a replantear como haciamos las clases varias veces, pero nos terminamos dando cuenta fue de que la gran parte de los errores era más en como pensabamos las mecanicas del juego y no el modelamiento del juego como tal.

