#include"Jugada.h"


Jugada::Jugada(int x1, int y1, int x2, int y2, char n):posX1(x1),posY1(y1),posX2(x2),posY2(y2),nombre(n){}

Jugada::~Jugada(){}

int Jugada::getposX1() {
	return posX1;
}
int Jugada::getposX2() {
	return posX2;
}
int Jugada::getposY1() {
	return posY1;
}
int Jugada::getposY2() {
	return posY2;
}
char Jugada::getNombre() {
	return nombre;
}

void Jugada::setposX1(int p) {
	posX1 = p;
}
void Jugada::setposX2(int p) {
	posX2 = p;
}
void Jugada::setposY1(int p) {
	posY1 = p;
}
void Jugada::setposY2(int p) {
	posY2 = p;
}
void Jugada::setNombre(char n) {
	nombre = n;
}

string Jugada::toString() {
	stringstream s;
	s << nombre<<posX1<<posX2<<posY1<<posY2<<endl;
	return s.str();
}

void Jugada::guardar(ostream& salida)
{
	salida << posX1 << '\t';
	salida << posY1 << '\t';
	salida << posX2 << '\t';
	salida << posY2 << '\t';
	salida << nombre;
}
Jugada* Jugada::recuperar(istream& entrada)
{
	string x1, y1, x2, y2,nom;

	getline(entrada, x1, '\t');
	getline(entrada, y1, '\t');
	getline(entrada, x2, '\t');
	getline(entrada, y2, '\t');
	getline(entrada, nom, '\n');

	int _x1 = stoi(x1);
	int _y1 = stoi(y1);
	int _x2 = stoi(x2);
	int _y2 = stoi(y2);
	char _nom = nom[0];

	return new Jugada(_x1, _y1, _x2, _y2, _nom);
}