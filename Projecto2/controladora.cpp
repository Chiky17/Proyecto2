#include "controladora.h"

controladora::controladora()
{
	empresa = new empresaDots();
}
controladora::~controladora()
{
	delete empresa;
}

void controladora::controlMenuEmpresa()
{
	int opcion;
	do {
		opcion = vista::menuEmpresa();
		switch (opcion) {
		case 1: controlSuscribirJugador();		break;
		case 2: controlCodigo();				break;
		case 3: controlJugadoresSuscritos();    break;
		case 4: controlCambioDia();
		};
	} while (opcion != 5);
}
void controladora::controlSuscribirJugador()
{
	vista::suscribirJugador(empresa);
}
void controladora::controlCodigo()
{
	vista::codigoActual(empresa);
}
void controladora::controlJugadoresSuscritos()
{
	vista::jugadoresSuscritos(empresa);
}
void controladora::controlCambioDia()
{
	vista::simulacionCambioDia(empresa);
}
