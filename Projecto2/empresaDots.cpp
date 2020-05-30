#include "empresaDots.h"
#include <time.h>

empresaDots::empresaDots()
{
    jugadores = new listaJugador;
    generaCodigo();
}
empresaDots::~empresaDots()
{
    delete jugadores;
}

void empresaDots::generaCodigo()
{
    codigo = "123456";
    srand(time(NULL));

    codigo[0] = 97 + rand() % (122 - 97);
    codigo[1] = 97 + rand() % (122 - 97);
    codigo[2] = 97 + rand() % (122 - 97);

    codigo[3] = 48 + rand() % (57 - 48);
    codigo[4] = 48 + rand() % (57 - 48);
    codigo[5] = 48 + rand() % (57 - 48);
}
void empresaDots::eliminaJugadores()
{
    jugadores->eliminarJugadores();
}
void empresaDots::cambioDeDia()
{
    generaCodigo();
    eliminaJugadores();
}

string empresaDots::getCodigo()
{
    return codigo;
}
void empresaDots::attach(jugador* j)
{
    jugadores->agregarInicio(j);
}
string empresaDots::mostrarJugadores()
{
    return jugadores->toString();
}
bool empresaDots::estaJugador(string c)
{
    return jugadores->existeJugador(c);
}
jugador* empresaDots::devuelveJugador(string c)
{
    if (estaJugador(c))
        return jugadores->regresaJugador(c);
    else
        return nullptr;
}