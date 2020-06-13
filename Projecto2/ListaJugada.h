#pragma once
#include"Jugada.h"

class nodoJugada;

class ListaJugada
{
private:
	nodoJugada* primero;
	nodoJugada* actual;
public:
	ListaJugada();
	void insertarFinal(Jugada*);
	bool eliminaFinal();
	string toString();
	Jugada* obtJugada(int);
	int cuentaNodos();
	bool listaVacia();
	~ListaJugada();
};


class nodoJugada
{
private:
	Jugada* info;
	nodoJugada* sig;
public:
	nodoJugada(Jugada*, nodoJugada*);
	~nodoJugada();
	void setInfo(Jugada*);
	Jugada* getInfo();
	void setSig(nodoJugada*);
	nodoJugada* getSig();
	string toStringNodo();


};