#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H
#include"ContenedorM.h"
#include "Partida.h"
using namespace std;

class Estrategia { //Interfaz... <<Abstract>>
public:
	virtual bool aplicaEstra(ContenedorM*,Partida*) = 0;
	virtual string getNombreEstra() = 0;

};

#endif // !ESTRATEGIA_H
