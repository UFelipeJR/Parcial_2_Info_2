#include "jugador.h"

jugador::jugador()
{

    /*
     * Constructor de la clase jugador
     *
     * Variables Inicializadas:
     *  - defecto: caracter por defecto en caso de que no se reciba ningun nombre
     *  - nombreJugador: placeholder para el nombre del jugador en caso de no recibir ninguno
     *  - caracterRepre: toma por referencia el defecto que es un espacio en blanco
     *  - cantFichas: como en el juego original se comienzan con dos, aqui se declara con un 2
     *
     */

    char defecto = ' ';
    nombreJugador = "Generico";
    cantFichas = 2;
    caracterRepre = &defecto;

}

jugador::jugador(string& nombreJugador, char* caracterRepre)
{
    /*
     * El constructor sobrecargado de jugador
     * recibe nombreJugador y caracterRepre
     * inicializa cantFichas en 2 como el anterior
     *
     */

    this->nombreJugador = nombreJugador;
    this->caracterRepre = caracterRepre;
    cantFichas = 2;
}

// Método getter y setter

char *jugador::getCaracterRepre() const
{
    return caracterRepre;
}

string jugador::getNombreJugador() const
{
    return nombreJugador;
}

void jugador::setNombreJugador(const string &newNombreJugador)
{
    nombreJugador = newNombreJugador;
}

unsigned short jugador::getCantFichas() const
{
    return cantFichas;
}

void jugador::setCantFichas(unsigned short newCantFichas)
{
    cantFichas = newCantFichas;
}

void jugador::setCaracterRepre(char *newCaracterRepre)
{
    caracterRepre = newCaracterRepre;
}
