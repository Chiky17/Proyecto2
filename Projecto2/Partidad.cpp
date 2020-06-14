#include"Partida.h"

Partida::Partida(ListaJugada* j, ProcesaCompuesto* c):jugadas(j),proCompu(c){}

Partida::~Partida(){
	delete proCompu;
}
ListaJugada* Partida::getJugadas(){
	return jugadas;
}
ProcesaCompuesto* Partida::getProCompu() {
	return proCompu;
}

void Partida::setJugadas(ListaJugada* l) {
	jugadas = l;
}
void Partida::setProCompu(ProcesaCompuesto* c) {
	proCompu = c;
}

string Partida::toString() {
	return " ";
}
