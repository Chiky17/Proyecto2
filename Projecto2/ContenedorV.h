#ifndef CONTENEDORV_H
#define CONTENEDORV_H

#include<iostream>
#include<sstream>
#include"CampoAbstracto.h"
#include"CampoNuevePuntos.h"
#include"CampoQuincePuntos.h"
#include"CampoSeisPuntos.h"

using namespace std;

class ContenedorV {
private:
	int can;
	int tam;
	CampoAbstracto** vec;

public:
	ContenedorV();
	virtual ~ContenedorV();
	void agregaCampo(CampoAbstracto*);
	int getTam();
	int getCan();
	CampoAbstracto* getCampo(int);


};

#endif // !CONTENEDORV_H
