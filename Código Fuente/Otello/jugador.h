#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


class jugador
{

private:
    string nombreJugador;
    char* caracterRepre;
    unsigned short int cantFichas;

public:
    jugador();
    jugador(string& nombreJugador,char* caracterRepre);


    //Métodos getter and setter
    char *getCaracterRepre() const;
    string getNombreJugador() const;
    void setNombreJugador(const string &newNombreJugador);
    unsigned short getCantFichas() const;
    void setCantFichas(unsigned short newCantFichas);
    void setCaracterRepre(char *newCaracterRepre);
};

#endif // JUGADOR_H
