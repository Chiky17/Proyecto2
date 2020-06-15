#pragma once
#include"EstraAleatorio.h"
#include"EstraCercano.h"
#include"EstraPeriferico.h"
#include"EstraCentral.h"
#include"EstraIslas.h"


class maquina
{
private:
	Estrategia* estra;
public:
	maquina();
	virtual ~maquina();
	string getNombre();
	void setEstrategia(Estrategia*);
	bool aplicarEstrategia(ContenedorM*,Partida*);
};