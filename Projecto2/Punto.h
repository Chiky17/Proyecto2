#ifndef PUNTO_H
#define PUNTO_H

#include<string>
#include<iostream>
#include<sstream>

using namespace std;

class Punto {
private:
	bool arriba;
	bool abajo;
	bool izquierda;
	bool derecha;
	bool desactivado;
	int numPaso;

public:
	Punto(bool = false, bool = false, bool = false, bool = false, bool = false, int = 0);
	virtual ~Punto();

	//gets
	bool getArriba();
	bool getAbajo();
	bool getIzquierda();
	bool getDerecha();
	bool getDesactivado();
	int getNumPaso();

	//sets
	void setArriba(bool);
	void setAbajo(bool);
	void setDerecha(bool);
	void setIzquierda(bool);
	void setDesactivado(bool);
	void setNumPaso(int);

	friend ostream& operator<<(ostream&, const Punto&);


};

#endif // !PUNTO_H