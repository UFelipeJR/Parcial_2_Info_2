#include "juego.h"

juego::juego()
{
    historial = "";
    dimensionTablero = 8;
}

juego::juego(short int dimensionTablero)
{
    historial = "";
    this -> dimensionTablero = dimensionTablero;
}


template<typename T>
T juego::obtener_Entrada(string mensaje, T inf, T max)
{
    T opcion;

    while (true) {
        cout << mensaje;
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "La entrada no es valida. Debe ser un numero." << endl;
        }
        else if (opcion >= inf && opcion <= max) {
            break;
        }
        else {
            cout << "Opcion invalida" << endl;
        }
    }

    return opcion;
}

void juego::cargar_Historial(string& ruta){

    unsigned long long int size;
    fstream archivo;


    try{
        archivo.open(ruta,ios::in | ios::ate);

        if(archivo.is_open()){
            size = archivo.tellg();
            archivo.seekg(0);

            for(unsigned long long i=0;i<size;i++){
                historial.push_back(archivo.get());
            }
        }
        else{
            throw runtime_error("No se pudo abrir el archivo");
        }

        archivo.close();

    } catch(const exception &e){
        cerr << "Error: " << e.what() << endl;

    }
}




void juego::menu()
{
    short int opcion = -1;
    string ruta = "../Otello/Archivos/historial.txt";
    cargar_Historial(ruta);
    do{
        cout << "------------ Menu Principal Otello ------------" << endl;
        cout << "1. Jugar Partida" << endl;
        cout << "2. Mostrar Historial de Partidas" << endl;
        cout << "3. Salir" << endl;
        opcion = obtener_Entrada("Ingrese una opcion:", 1, 3);
        switch(opcion){
            case 1:
                system("cls");
                menu_juego();
                break;
            case 2:
                cout << "Historial de Partidas" << endl;
                system("cls");
                cout << historial << endl;
                break;
            case 3:
                guardar_Cambios(ruta,historial);
                exit(1);

        }

    }

    while(opcion != 3);

}

void juego::menu_juego()
{
    jugador player1;
    jugador player2;
    tablero Tablero(dimensionTablero,dimensionTablero,&player1,&player2);
    string nombreAux;

    short int opcion = -1;
    short int pos[2];
    short turno = 1;
    short jug1 = 1, jug2 = 2;
    short contTotal = 0;
    string resultados;

    cout << "Ingrese el Nombre del Jugador 1:"; cin >> nombreAux;
    player1.setNombreJugador(nombreAux);
    player1.setCaracterRepre(&negro);

    cout << "Ingrese el Nombre del Jugador 2:"; cin >> nombreAux;
    player2.setNombreJugador(nombreAux);
    player2.setCaracterRepre(&blanco);


    Tablero.inicializarTablero();

    do{
        cout << "------------ Partida En Curso ------------" << endl;

        cout << "El Jugador 1: " << player1.getNombreJugador() << "\t"
        << "Cantidad de Fichas:" << player1.getCantFichas() << "\t"
        << "Caracter Representativo:"<< *player1.getCaracterRepre()
        << "\t" << "Color: Negro" << endl;

        cout << "El Jugador 2: " << player2.getNombreJugador() << "\t"
        << "Cantidad de Fichas:" << player2.getCantFichas() << "\t"
        << "Caracter Representativo:"<< *player2.getCaracterRepre()
        << "\t" << "Color: Blanco" << endl;


        Tablero.imprimirTablero();
        Tablero.actualizarCantFichas();

        cout << "Cantidad de Turnos Disponibles: " << Tablero.contJugadas(turno) << endl;

        while(true){

            if(Tablero.contJugadas(turno) == 0){
                cout << "No hay turnos disponibles" << endl;
                break;
            }
            cout << "Turno Jugador 1: " << player1.getNombreJugador() <<  endl;
            entrada_Array(pos);
            pos[0] --;
            pos[1] --;

            if(Tablero.validezJugada(turno,pos[0],pos[1])){
                Tablero.realizarJugada(turno,pos[0],pos[1]);
                turno = 2;
                break;
            }
            else{
                cout << "La jugada no es valida" << endl;
            }
        }

        Tablero.imprimirTablero();
        Tablero.actualizarCantFichas();


        cout << "Cantidad de Turnos Disponibles: " << Tablero.contJugadas(turno) << endl;

        while(true){
            if(Tablero.contJugadas(turno) == 0){
                cout << "No hay turnos disponibles" << endl;
                break;
            }
            cout << "Turno Jugador 2: " << player2.getNombreJugador() <<  endl;
            entrada_Array(pos);
            pos[0] --;
            pos[1] --;
            if(Tablero.validezJugada(turno,pos[0],pos[1])){
                Tablero.realizarJugada(turno,pos[0],pos[1]);
                turno = 1;
                break;
            }
            else{
                cout << "La jugada no es valida" << endl;
            }
        }


    if((Tablero.contJugadas(jug1) == 0)&&(Tablero.contJugadas(jug2) == 0)){
        cout << "Juego Finalizado" << endl;
        Tablero.imprimirTablero();
        if(player1.getCantFichas() > player2.getCantFichas()){
            ganador = player1.getNombreJugador();
            historial = "Jugador 1: " + player1.getNombreJugador() + ", Jugador 2: " + player2.getNombreJugador() + ", Fecha y Hora: " + generar_DMHA() + ", Ganador: " + ganador  + ", Cantidad de Fichas: " + to_string(player1.getCantFichas()) + "\n";
            cout << "Jugador 1: " + player1.getNombreJugador() + ", Jugador 2: " + player2.getNombreJugador() + ", Fecha y Hora: " + generar_DMHA() + ", Ganador: " + ganador  + ", Cantidad de Fichas: " + to_string(player1.getCantFichas()) + "\n" << endl;
        }
        else if(player1.getCantFichas() < player2.getCantFichas()){
            ganador = player2.getNombreJugador();
            historial = "Jugador 1: " + player1.getNombreJugador() + ", Jugador 2: " + player2.getNombreJugador() + ", Fecha y Hora: " + generar_DMHA() + ", Ganador: " + ganador  + ", Cantidad de Fichas: " + to_string(player2.getCantFichas()) + "\n";
            cout << "Jugador 1: " + player1.getNombreJugador() + ", Jugador 2: " + player2.getNombreJugador() + ", Fecha y Hora: " + generar_DMHA() + ", Ganador: " + ganador  + ", Cantidad de Fichas: " + to_string(player2.getCantFichas()) + "\n" << endl;
        }
        else{
            ganador = "Empate";
            historial = "Jugador 1: " + player1.getNombreJugador() + ", Jugador 2: " + player2.getNombreJugador() + ", Fecha y Hora: " + generar_DMHA() + ", Ganador: " + ganador + "\n";
            cout << "Jugador 1: " + player1.getNombreJugador() + ", Jugador 2: " + player2.getNombreJugador() + ", Fecha y Hora: " + generar_DMHA() + ", Ganador: " + ganador + "\n" << endl;
        }
        break;
    }


    contTotal = Tablero.contJugadas(jug1) + Tablero.contJugadas(jug2);
    }
    while((contTotal != Tablero.getFilas()*Tablero.getColumnas())||(contTotal != 0)); //Condición para cantidad de fichas
    menu();



}

string juego::generar_DMHA()
{
    string registro;
    auto now = chrono::system_clock::now();
    time_t end_time = chrono::system_clock::to_time_t(now);
    registro = ctime(&end_time);
    registro = registro.substr(0, registro.size() - 1);
    return registro;
}

/*
void juego::entrada_Array(short int arreglo[2])
{
    cout << "Ingrese dos numeros fila y la columna separados por un espacio:" << endl;
    cin >> arreglo[0] >> arreglo[1];
}
*/

void juego::entrada_Array(short int arreglo[2])
{
    cout << "Ingrese dos numeros fila y columna separados por un espacio:" << endl;
    bool entradaValida = false;

    while (!entradaValida) {
        if (cin >> arreglo[0] >> arreglo[1]) {
            if (arreglo[0] >= numeric_limits<short>::min() && arreglo[0] <= numeric_limits<short>::max() &&
                arreglo[1] >= numeric_limits<short>::min() && arreglo[1] <= numeric_limits<short>::max()) {
                entradaValida = true;
            } else {
                cout << "Entrada no valida. Ingrese dos numeros filas y columnas separados por un espacio: " << endl;
            }
        } else {
            cout << "Entrada no valida. Ingrese dos numeros filas y columnas separados por un espacio: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}



void juego::guardar_Cambios(string destino, string contenido)
{
    fstream archivo;
    archivo.open(destino, ios::out);
    archivo << contenido;
    archivo.close();
}




