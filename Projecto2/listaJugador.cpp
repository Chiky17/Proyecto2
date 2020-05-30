#include "listaJugador.h"

//----------------------- Definicion nodoJugador ----------------------------
nodoJugador::nodoJugador(jugador* i, nodoJugador* n)
{
	info = i;
	siguiente = n;
}
nodoJugador::~nodoJugador()
{
	delete info;
}

jugador* nodoJugador::getInfo()
{
	return info;
}
nodoJugador* nodoJugador::getSig()
{
	return siguiente;
}
void nodoJugador::setInfo(jugador* i)
{
	info = i;
}
void nodoJugador::setSig(nodoJugador* s)
{
	siguiente = s;
}

//----------------------- Definicion listaJugador ------------------------------

listaJugador::listaJugador()
{
	primero = nullptr;
	actual = nullptr;
	can = 0;
}
listaJugador::~listaJugador()
{
	while (!listaJugadorVacia())
	{
		actual = primero;
		primero = actual->getSig();
		delete actual;
	}
}
void listaJugador::eliminarJugadores()
{
	while (!listaJugadorVacia())
	{
		actual = primero;
		primero = actual->getSig();
		delete actual;
	}
}

void listaJugador::agregarInicio(jugador* info)
{
	primero = new nodoJugador(info, primero);
	can++;
}
bool listaJugador::listaJugadorVacia()
{
	return (primero == nullptr) ? true : false;
}
string listaJugador::toString()
{
	stringstream s;
	int cont = 1;
	jugador* aux = nullptr;

	if (!listaJugadorVacia())
	{
		actual = primero;
		while (actual != nullptr)
		{
			aux = actual->getInfo();
			s << "--------------------------------------------\n";
			s << "[" << cont << "] " << aux->toString() << "\n--------------------------------------------\n";
			actual = actual->getSig();
			cont++;
		}
	}
	else
		s << "--------------- Sin Jugadores ---------------\n";

	return s.str();
}
bool listaJugador::existeJugador(string cedula) // Busca jugador por id, si existe true,sino false
{
	actual = primero;
	jugador* aux = nullptr;

	while (actual != nullptr)
	{
		aux = actual->getInfo();
		if (aux->getCedula() == cedula)
			return true;
		actual = actual->getSig();
	}
	return false;
}
jugador* listaJugador::regresaJugador(string cedula)
{
	actual = primero;
	jugador* aux = nullptr;

	while (actual != nullptr)
	{
		aux = actual->getInfo();
		if (aux->getCedula() == cedula)
			return aux;
		actual = actual->getSig();
	}
	return nullptr;
}