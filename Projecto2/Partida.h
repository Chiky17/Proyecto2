#pragma once
#include<sstream>
#include<string>
#include"ListaJugada.h"
#include"ProcesaCompuesto.h"

using namespace std;
 
class Partida {
private:
	ListaJugada* jugadas;
	ProcesaCompuesto* proCompu;
	int can = 0;
public:
	Partida(ListaJugada* = NULL, ProcesaCompuesto* = NULL);
	~Partida();

	ListaJugada* getJugadas();
	ProcesaCompuesto* getProCompu();

	void setJugadas(ListaJugada*);
	void setProCompu(ProcesaCompuesto*);

	string toString();

	void guardar(ostream&);
};