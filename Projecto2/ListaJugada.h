#pragma once
#include"Jugada.h"

class nodoJugada;

class ListaJugada
{
private:
	nodoJugada* primero;
	nodoJugada* actual;
	int can = 0;
public:
	ListaJugada();
	void insertarFinal(Jugada*);
	bool eliminaFinal();
	string toString();
	Jugada* obtJugada(int);
	int cuentaNodos();
	bool listaVacia();
	~ListaJugada();

	void guardarJugadas(ostream&);
	static ListaJugada* recuperarJugadas(istream&);
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