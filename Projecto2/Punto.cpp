#include"Punto.h"

Punto::Punto(bool a, bool ab, bool i, bool d, bool b, int num,char nom) :
	arriba(a), abajo(ab), izquierda(i), derecha(d), desactivado(b), numPaso(num),nombre(nom) {

}
Punto::~Punto() {

}

//gets
bool Punto::getArriba() {
	return arriba;
}
bool Punto::getAbajo() {
	return abajo;
}
bool Punto::getIzquierda() {
	return izquierda;
}
bool Punto::getDerecha() {
	return derecha;
}
bool Punto::getDesactivado() {
	return desactivado;
}
int Punto::getNumPaso() {
	return numPaso;
}
char Punto::getNombre()
{
	return nombre;
}
//sets

void Punto::setArriba(bool a) {
	arriba = a;
}
void Punto::setAbajo(bool a) {
	abajo = a;
}
void Punto::setDerecha(bool d) {
	derecha = d;
}
void Punto::setIzquierda(bool i) {
	izquierda = i;
}
void Punto::setDesactivado(bool b) {
	desactivado = b;
}
void Punto::setNumPaso(int n) {
	numPaso = n;
}
void Punto::setNombre(char n)
{
	nombre = n;
}
ostream& operator<<(ostream& out, const Punto& p) {
	return out << "o";
}