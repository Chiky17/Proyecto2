#include "vista.h"

int vista::menuEmpresa()
{
	int opcion;

	system("cls");
	cout << "[1] Suscribir Jugador\n";
	cout << "[2] Codigo actual\n";
	cout << "[3] Jugadores suscritos\n";
	cout << "[4] Simular cambio de dia\n";
	cout << "[5] Salir\n";
	cout << "Opcion: ";
	cin >> opcion;
	system("cls");
	return opcion;
}
void vista::suscribirJugador(empresaDots* empresa)
{
	string id, nom;

	cout << "Digite la cedula del jugador: "; cin >> id;
	if (!empresa->estaJugador(id))
	{
		cout << "Digite el nombre del jugador: "; cin >> nom;
		jugador* jugaAux = new jugador(nom, id, empresa);
		system("cls");
		cout << "\tJugador suscrito correctamente\n\n";
	}
	else
	{
		system("cls");
		cout << "\tEl jugador ya esta suscrito a la empresa\n\n";
	}
	system("pause");
}
void vista::codigoActual(empresaDots* empresa)
{
	string id;

	cout << "Digite la cedula del jugador: "; cin >> id;
	if (empresa->estaJugador(id))
	{
		jugador* aux = empresa->devuelveJugador(id);
		cout << "Codigo del dia: " << aux->mostrarCodigo() << endl << endl;
	}
	else
	{
		system("cls");
		cout << "\tJugador no esta suscrito a la empresa\n\n";
	}
	system("pause");
}
void vista::jugadoresSuscritos(empresaDots* empresa)
{
	cout << empresa->mostrarJugadores() << endl << endl;
	system("pause");
}
void vista::simulacionCambioDia(empresaDots* empresa)
{
	empresa->cambioDeDia();
	cout << "El codigo ha cambiado\nLos jugadores suscritos han sido borrados para comenzar el dia\n\n";
	system("pause");
}
