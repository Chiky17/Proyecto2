#include"ListaPartida.h"


ListaPartida::ListaPartida()
{
	primero = NULL;
	actual = NULL;
}
void ListaPartida::insertarFinal(Partida* e) {
	actual = primero;
	if (primero == NULL) // la lista esta vacia
	{
		primero = new nodoPartida(e, NULL);
	}
	else
	{
		while (actual->getSig() != NULL) // este ciclo posiciona el puntero en 
		{                                // el ultimo de la lista
			actual = actual->getSig();
		}
		actual->setSig(new nodoPartida(e, NULL));

	}

}

Partida* ListaPartida::obtPartida(int n) {
	int can = 1;
	actual = primero;
	if (actual == NULL) {
		return NULL;
	}
	while (actual->getSig() != NULL && can < n) {
		actual = actual->getSig();
		can++;
	}
	if (can == n) {
		return actual->getInfo();
	}
	return NULL;
}



int ListaPartida::cuentaNodos() {
	int con = 0;
	actual = primero;
	while (actual != NULL) {
		con++;
		actual = actual->getSig();
	}
	return con;
}
string ListaPartida::toString()
{
	stringstream s;
	int con = 1;
	actual = primero;
	s << "\n__________________________________________________________________________________" << endl;
	if (actual == NULL)
	{
		s << " No hay Partidas" << endl;
	}

	while (actual != NULL)
	{
		s << " No." << con << " " << actual->toStringNodo();
		con++;
		actual = actual->getSig();
	}
	s << "__________________________________________________________________________________" << endl;
	return s.str();
}


Partida* ListaPartida::getPartida(string nom)
{
	actual = primero;
	while (actual != NULL)
	{
		if (actual->getInfo()->getNombre() == nom) {
			return actual->getInfo();
		}
		actual = actual->getSig();
	}
	return NULL;
}


bool ListaPartida::listaVacia() {
	if (primero == NULL) return true;
	else return false;
}


bool ListaPartida::eliminaFinal() {

	actual = primero;	// caso 1: la lista vacia
	if (primero == NULL)
	{
		return false;
	}
	else
	{
		// caso 2: la lista solo tiene un elemento
		if (primero->getSig() == NULL)
		{
			delete primero;
			primero = NULL;
		}
		else
		{// caso 3: la lista solo tiene 2 o mas elementos

			while (actual->getSig()->getSig() != NULL)
			{
				actual = actual->getSig();
			}
			delete  actual->getSig();
			actual->setSig(NULL);
		}
		return true;
	}
}


ListaPartida::~ListaPartida() {
	while (!listaVacia())
	{
		eliminaFinal();
	}
}

//--------------------------------------------------------------------------------------------------------------------

nodoPartida::nodoPartida(Partida* e, nodoPartida* s) {
	info = e;
	sig = s;
}
nodoPartida:: ~nodoPartida() {
	delete info;
}
void nodoPartida::setInfo(Partida* e) {
	info = e;
}
Partida* nodoPartida::getInfo() {

	return info;
}
void nodoPartida::setSig(nodoPartida* s) {
	sig = s;
}
nodoPartida* nodoPartida::getSig() {
	return sig;
}
string nodoPartida::toStringNodo() {
	stringstream s;
	s << info->toString() << endl;
	return s.str();
}
