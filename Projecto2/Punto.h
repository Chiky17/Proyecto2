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
	char nombre;

public:
	Punto(bool = false, bool = false, bool = false, bool = false, bool = false, int = 0,char=' ');
	virtual ~Punto();

	//gets
	bool getArriba();
	bool getAbajo();
	bool getIzquierda();
	bool getDerecha();
	bool getDesactivado();
	int getNumPaso();
	char getNombre();

	//sets
	void setArriba(bool);
	void setAbajo(bool);
	void setDerecha(bool);
	void setIzquierda(bool);
	void setDesactivado(bool);
	void setNumPaso(int);
	void setNombre(char);

	friend ostream& operator<<(ostream&, const Punto&);


};

#endif // !PUNTO_H