#include "vista.h"
#include "utiles.h"
int vista::menuGeneral()
{
	int opcion;

	system("cls");
	imprimeCadena("[1] Juego\n");
	imprimeCadena("[2] Menu empresa\n");
	imprimeCadena("[3] Salir\n");
	imprimeCadena("Opcion: ");
	opcion = leerEntero();
	system("cls");
	return opcion;
}

int vista::menuJuego()
{
	int opcion;

	system("cls");
	imprimeCadena("[1] Jugar\n");
	imprimeCadena("[2] Ver repeticion\n");
	imprimeCadena("[3] Volver\n");
	imprimeCadena("Opcion: ");
	opcion = leerEntero();
	system("cls");
	return opcion;
}
bool vista::iniciarSesion(empresaDots* empresa) // false si el codigo o id son incorrectos   - Aqui se entra si elige jugar
{
	string id, codigo;

	system("cls");
	imprimeCadena("Digite su cedula: "); id = leerCadena2();
	if (empresa->estaJugador(id))
	{
		imprimeCadena("Digite el codigo del dia de hoy: "); codigo = leerCadena2();
		if (codigo == empresa->getCodigo())
			return true;
		else
			return false;
	}
	else
		return false;
}
int vista::modoDeJuego() // si inicio sesion true
{
	int opcion;

	system("cls");
	imprimeCadena("[1] Jugador vs Jugador\n");
	imprimeCadena("[2] Jugador vs Maquina\n");
	imprimeCadena("Opcion: "); opcion = leerEntero();
	return opcion;
}

int vista::menuEmpresa()
{
	int opcion;

	system("cls");
	imprimeCadena("[1] Suscribir Jugador\n");
	imprimeCadena("[2] Codigo actual\n");
	imprimeCadena("[3] Jugadores suscritos\n");
	imprimeCadena("[4] Simular cambio de dia\n");
	imprimeCadena("[5] Salir\n");
	imprimeCadena("Opcion: ");
	opcion = leerEntero();
	system("cls");
	return opcion;
}
void vista::suscribirJugador(empresaDots* empresa)
{
	string id, nom;

	imprimeCadena("Digite la cedula del jugador: "); id = leerCadena2();
	if (!empresa->estaJugador(id))
	{
		imprimeCadena("Digite el nombre del jugador: "); nom = leerCadena2();
		jugador* jugaAux = new jugador(nom, id, empresa);
		system("cls");
		imprimeCadena("\tJugador suscrito correctamente\n\n");
	}
	else
	{
		system("cls");
		imprimeCadena("\tEl jugador ya esta suscrito a la empresa\n\n");
	}
	system("pause");
}
void vista::codigoActual(empresaDots* empresa)
{
	string id;

	imprimeCadena("Digite la cedula del jugador: ");  id = leerCadena2();
	if (empresa->estaJugador(id))
	{
		jugador* aux = empresa->devuelveJugador(id);
		imprimeCadena( "Codigo del dia: " + aux->mostrarCodigo() + "\n\n");
	}
	else
	{
		system("cls");
		imprimeCadena( "\tJugador no esta suscrito a la empresa\n\n");
	}
	system("pause");
}
void vista::jugadoresSuscritos(empresaDots* empresa)
{
	imprimeCadena(empresa->mostrarJugadores() + "\n\n");
	system("pause");
}
void vista::simulacionCambioDia(empresaDots* empresa)
{
	empresa->cambioDeDia();
	imprimeCadena( "El codigo ha cambiado\nLos jugadores suscritos han sido borrados para comenzar el dia\n\n");
	system("pause");
}
