#ifndef CONTENEDORM_H
#define CONTENEDORM_H

#include<sstream>
#include<string>
#include<iostream>

#include"Punto.h"
using namespace std;

class ContenedorM {
private:
	Punto* m[5][70];
	int fil;
	int col;

public:
	ContenedorM();
	virtual ~ContenedorM();
	void ingresaPunto(int i, int j, Punto* p);
	Punto* getPunto(int i, int j);
	string toString(char);

	int columnaFinal();
	bool compruebaCuadro(int, int);
	void puntoJugador(int, int, char); // recibe ultima jugada, si hace cuadro, retorna el nom de jugador
	bool estaLlena();
	int cuentaPuntos(char, string);

	int getCol();
	bool compruebaTrazo(Punto*, Punto*);
	int getReciente();
};

#endif // !CONTENEDORM_H