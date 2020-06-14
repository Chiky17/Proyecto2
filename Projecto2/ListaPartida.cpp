#include"ListaPartida.h"


ListaPartida::ListaPartida()
{
	primero = NULL;
	actual = NULL;
	can = 0;
}
void ListaPartida::insertarFinal(Partida* e) {
	actual = primero;
	if (primero == NULL) // la lista esta vacia
	{
		primero = new nodoPartida(e, NULL);
		can++;
	}
	else
	{
		while (actual->getSig() != NULL) // este ciclo posiciona el puntero en 
		{                                // el ultimo de la lista
			actual = actual->getSig();
		}
		actual->setSig(new nodoPartida(e, NULL));
		can++;
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


//Partida* ListaPartida::getPartida(string nom)
//{
//	actual = primero;
//	while (actual != NULL)
//	{
//		if (actual->getInfo()->getNombre() == nom) {
//			return actual->getInfo();
//		}
//		actual = actual->getSig();
//	}
//	return NULL;
//}


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

void ListaPartida::guardarPartidas()
{
	string archivo = "../Partidas.txt";
	ofstream salida(archivo.c_str(), ios::trunc);

	salida << cuentaNodos() << '\n';
	for (int i = cuentaNodos(); i >= 1; i--)
	{
		obtPartida(i)->guardar(salida);
		//salida << '\n';
	}

	salida.close();
}

ListaPartida* ListaPartida::recuperarPartidas()
{
	string archivo = "../Partidas.txt";
	ifstream entrada(archivo.c_str());
	string _can;
	ListaPartida* lista = new ListaPartida();

	getline(entrada, _can, '\n');
	int can = stoi(_can);

	for (int i = 1; i <= can; i++)
	{
		lista->insertarFinal(Partida::recuperar(entrada));
	}
	return lista;

	entrada.close();
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
