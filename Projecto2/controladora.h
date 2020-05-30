#pragma once
#include "vista.h"

class controladora
{
private:
	empresaDots* empresa;
public:
	controladora();
	virtual ~controladora();


	//Controles temporales para empresa - jugador
	void controlMenuEmpresa();
	void controlSuscribirJugador();
	void controlCodigo();
	void controlJugadoresSuscritos();
	void controlCambioDia();

};