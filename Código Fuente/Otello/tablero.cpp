#include "tablero.h"

tablero::tablero()
{

    /*
     * Constructor por defecto de tablero
     *
     * Variables inicializadas:
     *  - validas: un arreglo con bastantes posiciones para la comprobacion de la validez de la direccion que se toma en el juego
     *  - filas, columnas: por defecto en 8 así como en el juego original
     *  - Tablero: el tablero como tal para armar el arreglo el cual se usara para los datos del transcurso del juego
     *
     */

    short int validas[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1, 1},{-1, -1}};

    for(int i = 0; i<8; i++){
        this -> direccionesValidas[i][0] = validas[i][0];
        this -> direccionesValidas[i][1] = validas[i][1];
    }

    filas = 8;
    columnas = 8;

    Tablero = new unsigned char*[filas];

    for(int i = 0; i < filas; i++){
        Tablero[i] = new unsigned char[columnas];
    }


}

tablero::tablero(short int filas, short int columnas, jugador* jugador1, jugador* jugador2)
{
    /*
     * Constructor sobrecargado con filas, columnas y ambos jugadores con sus respectivos nombres
     *
     * Es el mismo concepto del anterior más sin embargo este esta dado para controlar los datos que reciben
     * en ejecución
     *
     */

    short int validas[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1, 1},{-1, -1}};

    this->filas = filas;
    this->columnas = columnas;
    this->jugador1 = jugador1;
    this->jugador2 = jugador2;

    for(int i = 0; i<8; i++){
        this -> direccionesValidas[i][0] = validas[i][0];
        this -> direccionesValidas[i][1] = validas[i][1];
    }


    Tablero = new unsigned char*[filas];

    for(int i = 0; i < filas; i++){
        Tablero[i] = new unsigned char[columnas];
    }


}


tablero::~tablero()
{
    /*
     * Destructor de la clase tablero (para liberar la memoria dinámica)
     *
     */

    // Liberación de memoria dinámica

    for(int i = 0; i<filas; i++){
        delete[] Tablero[i];
    }
    delete[] Tablero;

}

void tablero::inicializarTablero()
{

    /*
     * Metodo encargado de tomar los datos e inicializar el tablero originalmente con las posiciones iniciales
     *
     * Variables Inicializadas:
     *  - caractearRepre1: caracter representativo para el jugador 1
     *  - caracterRepre2: caracter representativo para el jugador 2
     *
     *  Retornos:
     *   - none
     */

    char* caracterRepre1 = jugador1->getCaracterRepre();
    char* caracterRepre2 = jugador2->getCaracterRepre();

    for(int i = 0;i<filas;i++){
        for(int j = 0; j<columnas;j++){
            Tablero[i][j] = ' ';
        }
    }

    Tablero[(filas/2)-1][(filas/2)-1] = *caracterRepre2;
    Tablero[(filas/2)][(filas/2)] = *caracterRepre2;
    Tablero[(filas/2)][(filas/2)-1] = *caracterRepre1;
    Tablero[(filas/2)-1][(filas/2)] = *caracterRepre1;


}


void tablero::actualizarCantFichas()
{

    /*
     * Metodo encargado de actualizar la cant de fichas en el tablero
     *
     * Variables inicializadas:
     *  - jugador_1: cant fichas para player1
     *  - jugador_2: cant fichas para player2
     *
     * Retornos:
     *  - none
     *
     */

    unsigned short int jugador_1 = 0;
    unsigned short int jugador_2 = 0;
    char* caracter1 = jugador1->getCaracterRepre();
    char* caracter2 = jugador2->getCaracterRepre();


    for(int i = 0; i< filas; i++){
        for(int j = 0; j < columnas; j++){
            if(Tablero[i][j] == *caracter1){
                jugador_1 ++;
            }
            else if(Tablero[i][j] == *caracter2){
                jugador_2 ++;
            }


        }
    }


    jugador1->setCantFichas(jugador_1);
    jugador2->setCantFichas(jugador_2);

}

bool tablero::validezJugada(short int& numJugador, short int& fila, short int& columna) {

    /*
     * Metodo encargado de verificar si la jugada que se realizara es valida (esta va muy de la mano realizarJugada)
     *
     * Variables Inicializadas:
     *  - jugadorP
     *  - jugadorS
     *  - coordenadaX,coordenadaY
     *
     * Retorno:
     *  - bool
     *
     */

    char* jugadorP;
    char* jugadorS;
    short int coordenadaX = 0;
    short int coordenadaY = 0;

    if(Tablero[fila][columna] != ' '){
        return false;
    }


    if (numJugador == 1) {
        jugadorP = jugador1->getCaracterRepre();
        jugadorS = jugador2->getCaracterRepre();
    }
    else if (numJugador == 2) {
        jugadorS = jugador1->getCaracterRepre();
        jugadorP = jugador2->getCaracterRepre();
    }


    for (int i = 0; i < 8; i++) {
        coordenadaX = direccionesValidas[i][0] + fila;
        coordenadaY = direccionesValidas[i][1] + columna;

        if ((coordenadaX >= 0 && coordenadaX < filas) && (coordenadaY >= 0 && coordenadaY < columnas) && Tablero[coordenadaX][coordenadaY] == *jugadorS) {

            coordenadaX += direccionesValidas[i][0];
            coordenadaY += direccionesValidas[i][1];

            while ((coordenadaX >= 0 && coordenadaX < filas) && (coordenadaY >= 0 && coordenadaY < columnas)){
                if (Tablero[coordenadaX][coordenadaY] == *jugadorP) {
                    return true;
                }
                if (Tablero[coordenadaX][coordenadaY] != *jugadorS) {
                    break;
                }
                coordenadaX += direccionesValidas[i][0];
                coordenadaY += direccionesValidas[i][1];
            }
        }
    }

    return false;
}

void tablero::realizarJugada(short int &numJugador, short int &fila, short int &columna)
{

    /*
     * Metodo encargado de realizar la jugada dicha por el jugador en su respectivo turno
     *
     * Variables Inicializadas:
     *  - jugadorP
     *  - jugadorS
     *  - coordenadaX, coordenadaY: encargadas de marcar la pos que se usara para la jugada
     *
     * Retornos:
     *  - none
     *
     */

    char* jugadorP;
    char* jugadorS;
    short int coordenadaX = 0;
    short int coordenadaY = 0;

    if (numJugador == 1) {
        jugadorP = jugador1->getCaracterRepre();
        jugadorS = jugador2->getCaracterRepre();
    }
    else if (numJugador == 2) {
        jugadorS = jugador1->getCaracterRepre();
        jugadorP = jugador2->getCaracterRepre();
    }

    if(!(validezJugada(numJugador,fila,columna))){
        cout << "La jugada no es valida" << endl;
        return;
    }

    Tablero[fila][columna] = *jugadorP;

    for (int i = 0; i < 8; i++) {
        coordenadaX = fila + direccionesValidas[i][0];
        coordenadaY = columna + direccionesValidas[i][1];
        while ((coordenadaX >= 0 && coordenadaX < filas) && (coordenadaY >= 0 && coordenadaY < columnas) && Tablero[coordenadaX][coordenadaY] == *jugadorS){
            coordenadaX += direccionesValidas[i][0];
            coordenadaY += direccionesValidas[i][1];
        }
        if ((coordenadaX >= 0 && coordenadaX < filas) && (coordenadaY >= 0 && coordenadaY < columnas) && Tablero[coordenadaX][coordenadaY] == *jugadorP) {
            coordenadaX -= direccionesValidas[i][0];
            coordenadaY -= direccionesValidas[i][1];
            while(Tablero[coordenadaX][coordenadaY] == *jugadorS){
                Tablero[coordenadaX][coordenadaY] = *jugadorP;
                coordenadaX -= direccionesValidas[i][0];
                coordenadaY -= direccionesValidas[i][1];
            }
        }
    }
}


short tablero::contJugadas(short int& numJugador)
{
    /*
     * Metodo encargado de contar el total de jugadas disponibles en el tablero
     *
     * Variables Inicializadas:
     *  - cont: contador
     *
     * Retornos:
     *  - short int cont
     */

    short int cont = 0;

    for(short int i = 0; i < filas; i++){
        for(short int j = 0; j < columnas; j++){
            if(validezJugada(numJugador,i,j)){
                cont ++;
            }
        }
    }

    return cont;
}


string tablero::filaAmigable()
{
    //METODOS ENCARGADOS DE LA VISUALIZACIÓN DEL TABLERO DE MANERA AMIGABLE Y ESTETICA

    string cadena;

    for(int i = 0; i<filas;i++){
        cadena += "+---";
        if(i == filas-1){
            cadena += "+";
        }
    }
    return cadena;

}

string tablero::numeracionFila()
{
    //METODOS ENCARGADOS DE LA VISUALIZACIÓN DEL TABLERO DE MANERA AMIGABLE Y ESTETICA
    string numeracion = "  ";
    for(int i = 1; i <= filas;i++){
        if(i >= 0 && i<= 9){
            numeracion += to_string(i);
            numeracion += "   ";
        }
        else{
            numeracion += to_string(i);
            numeracion += "  ";
        }

    }
    return numeracion;
}

void tablero::imprimirTablero()
{
    //METODOS ENCARGADOS DE LA VISUALIZACIÓN DEL TABLERO DE MANERA AMIGABLE Y ESTETICA
    string numeracion = numeracionFila();
    string fila = filaAmigable();
    cout << numeracionFila() << endl;
    for (int i = 0; i < filas; i++) {
        if (i >= 0) {
            cout << fila << endl;
        }
        cout << "|";
        for (int j = 0; j < columnas; j++) {
            if(Tablero[i][j] == *(jugador1->getCaracterRepre())){
                cout << " " << "\033[34m" << Tablero[i][j] << "\033[0m" << " |";
            }
            else{
                cout << " " << Tablero[i][j] << " |";
            }
        }
        cout << " " << i+1 << endl;
    }
    cout << fila << endl;
}

unsigned short int tablero::getFilas() const
{
    return filas;
}

void tablero::setFilas(unsigned int newFilas)
{
    filas = newFilas;
}

unsigned short int tablero::getColumnas() const
{
    return columnas;
}

void tablero::setColumnas(unsigned int newColumnas)
{
    columnas = newColumnas;
}













