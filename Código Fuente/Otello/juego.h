#ifndef JUEGO_H
#define JUEGO_H

#include <jugador.h>
#include <tablero.h>
#include <limits>
#include <chrono>

class juego
{
    char negro = '-';
    char blanco = '*';
    unsigned int dimensionTablero;
    string ganador;
    string historial;


public:
    juego();
    juego(string& ruta);

    void cargar_Historial(string& ruta);
    void menu();
    void menu_juego();

    template <typename T>
    T obtener_Entrada(string mensaje, T inf, T max);
    string generar_DMHA();
    void entrada_Array(short int arreglo[2]);
    void guardar_Cambios(string destino, string contenido);



};

#endif // JUEGO_H
