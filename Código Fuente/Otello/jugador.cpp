#include "jugador.h"

jugador::jugador()
{
    char defecto = ' ';
    nombreJugador = "Generico";
    cantFichas = 2;
    caracterRepre = &defecto;


}

jugador::jugador(string& nombreJugador, char* caracterRepre)
{
    this->nombreJugador = nombreJugador;
    this->caracterRepre = caracterRepre;
    cantFichas = 2;
}

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
