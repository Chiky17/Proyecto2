#pragma once
#include"Partida.h"

using namespace std;
class nodoPartida;

class ListaPartida
{
private:
	nodoPartida* primero;
	nodoPartida* actual;
	int can;
public:
	ListaPartida();
	void insertarFinal(Partida*);
	bool eliminaFinal();
	string toString();
	/*string toStringCompleto();
	Partida* getPartida(string);*/
	Partida* obtPartida(int);
	int cuentaNodos();
	bool listaVacia();
	~ListaPartida();

	//void guardarJugadas(ostream&);
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
