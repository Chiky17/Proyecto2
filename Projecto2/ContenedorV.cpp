#include"ContenedorV.h"

ContenedorV::ContenedorV() {
	tam = 10;//preguntar 
	can = 0;
	vec = new CampoAbstracto * [tam];
	for (int i = 0; i < tam; i++)
	{
		vec[i] = NULL;
	}
}
ContenedorV:: ~ContenedorV() {
	for (int i = 0; i < can; i++)
	{
		delete vec[i];
	}
	delete[] vec;
}
void ContenedorV::agregaCampo(CampoAbstracto* obj) {
	if (can < tam) {
		vec[can++] = obj;
	}
}
int ContenedorV::getTam() {
	return tam;
}
int ContenedorV::getCan() {
	return can;
}
CampoAbstracto* ContenedorV::getCampo(int pos) {
	if (pos < can && pos >= 0)
		return vec[pos];
	else
		return NULL;
}