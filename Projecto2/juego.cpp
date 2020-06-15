#include "juego.h"

juego::juego()
{
    partidas = ListaPartida::recuperarPartidas();
    empresa = new empresaDots;
}

juego::~juego()
{
    delete empresa;
    delete partidas;
}

ListaPartida* juego::getPartidas()
{
    return partidas;
}

empresaDots* juego::getEmpresa()
{
    return empresa;
}

void juego::guardarPartidas()
{
    partidas->guardarPartidas();
}