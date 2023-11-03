#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <string>
#include <jugador.h>}

using namespace std;

class tablero
{

private:
    unsigned short int filas;
    unsigned short int columnas;
    unsigned char** Tablero;
    short int direccionesValidas[8][2];
    jugador* jugador1;
    jugador* jugador2;


public:
    tablero();
    tablero(short int filas, short int columnas, jugador* jugador1, jugador* jugador2);
    ~tablero();

    void inicializarTablero();
    void imprimirTablero();
    string filaAmigable();
    string numeracionFila();
    bool validezJugada(short int& numJugador,short int& fila, short int& columna);
    void realizarJugada(short int& numJugador,short int& fila, short int& columna);
    void actualizarCantFichas();
    short int contJugadas(short int& numJugador);


    unsigned short int getFilas() const;
    void setFilas(unsigned int newFilas);
    unsigned short int getColumnas() const;
    void setColumnas(unsigned int newColumnas);
};

#endif // TABLERO_H
