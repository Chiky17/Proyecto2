#pragma once
#include <iostream>
#include <sstream>
#include "jugador.h"
using namespace std;

class empresaDots;
class jugador;

class nodoJugador
{
private:
	jugador* info;
	nodoJugador* siguiente;
public:
	nodoJugador(jugador*, nodoJugador*);
	virtual ~nodoJugador();

	jugador* getInfo();
	nodoJugador* getSig();
	void setInfo(jugador*);
	void setSig(nodoJugador*);
};

//----------------- Clase listaJugador --------------------------------

class listaJugador
{
private:
	nodoJugador* primero;
	nodoJugador* actual;
	int can;
public:
	listaJugador();
	virtual ~listaJugador();
	void eliminarJugadores();

	void agregarInicio(jugador*);
	bool listaJugadorVacia();
	string toString();
	bool existeJugador(string);
	jugador* regresaJugador(string);
};
