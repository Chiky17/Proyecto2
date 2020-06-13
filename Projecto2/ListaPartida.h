#pragma once

#include"Partida.h"

class nodoPartida;

class ListaPartida
{
private:
	nodoPartida* primero;
	nodoPartida* actual;
public:
	ListaPartida();
	void insertarFinal(Partida*);
	bool eliminaFinal();
	string toString();
	string toStringCompleto();
	Partida* getPartida(string);
	Partida* obtPartida(int);
	int cuentaNodos();
	bool listaVacia();
	~ListaPartida();
};


class nodoPartida
{
private:
	Partida* info;
	nodoPartida* sig;
public:
	nodoPartida(Partida*, nodoPartida*);
	~nodoPartida();
	void setInfo(Partida*);
	Partida* getInfo();
	void setSig(nodoPartida*);
	nodoPartida* getSig();
	string toStringNodo();
	string toStringNodoCom();

};
