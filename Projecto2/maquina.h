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
	void setEstrategia(Estrategia*);
	void aplicarEstrategia(ContenedorM*);
};