#include"ListaJugada.h"

ListaJugada::ListaJugada()
{
	primero = NULL;
	actual = NULL;
}
void ListaJugada::insertarFinal(Jugada* e) {
	actual = primero;
	if (primero == NULL) // la lista esta vacia
	{
		primero = new nodoJugada(e, NULL);
	}
	else
	{
		while (actual->getSig() != NULL) // este ciclo posiciona el puntero en 
		{                                // el ultimo de la lista
			actual = actual->getSig();
		}
		actual->setSig(new nodoJugada(e, NULL));

	}

}

Jugada* ListaJugada::obtJugada(int n) {
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



int ListaJugada::cuentaNodos() {
	int con = 0;
	actual = primero;
	while (actual != NULL) {
		con++;
		actual = actual->getSig();
	}
	return con;
}
string ListaJugada::toString()
{
	stringstream s;
	int con = 1;
	actual = primero;
	s << "\n__________________________________________________________________________________" << endl;
	if (actual == NULL)
	{
		s << " No hay Jugadas" << endl;
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


bool ListaJugada::listaVacia() {
	if (primero == NULL) return true;
	else return false;
}


bool ListaJugada::eliminaFinal() {

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


ListaJugada::~ListaJugada() {
	while (!listaVacia())
	{
		eliminaFinal();
	}
}

//--------------------------------------------------------------------------------------------------------------------

nodoJugada::nodoJugada(Jugada* e, nodoJugada* s) {
	info = e;
	sig = s;
}
nodoJugada:: ~nodoJugada() {
	delete info;
}
void nodoJugada::setInfo(Jugada* e) {
	info = e;
}
Jugada* nodoJugada::getInfo() {

	return info;
}
void nodoJugada::setSig(nodoJugada* s) {
	sig = s;
}
nodoJugada* nodoJugada::getSig() {
	return sig;
}
string nodoJugada::toStringNodo() {
	stringstream s;
	s << info->toString() << endl;
	return s.str();
}
