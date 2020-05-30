#include "jugador.h"

jugador::jugador(string n, string c, empresaDots* e) :nombre(n), cedula(c), empresa(e)
{
	empresa->attach(this);
}
jugador::~jugador()
{

}

string jugador::getCedula()
{
	return cedula;
}

string jugador::toString() const
{
	stringstream s;

	s << "Nombre: " << nombre << "\nCedula: " << cedula;
	return s.str();
}
string jugador::mostrarCodigo()
{
	return empresa->getCodigo();
}