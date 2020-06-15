#include "controladora.h"
//#include "utiles.h"
controladora::controladora()
{
	_juego = new juego;
}
controladora::~controladora()
{
	delete _juego;
}

void controladora::control1()
{
	int opcion = 0;

	do
	{
		system("cls");
		opcion = control2();
		system("pause");
	} while (opcion != 3);

	

}
int controladora::control2()
{
	int opcion = 0;

	switch (opcion = vista::menuGeneral())
	{
		case 1:
			vista::menuJuego(_juego->getPartidas(), _juego->getEmpresa()); break;
		case 2:
			vista::menuEmpresa(_juego->getEmpresa()); break;
		case 3:
			break;
	default:
		vista::error();
	}

	return opcion;
}