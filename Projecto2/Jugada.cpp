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
	s << nombre<<endl;
	return s.str();
}