#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H
#include"ContenedorM.h"
using namespace std;

class Estrategia { //Interfaz... <<Abstract>>
public:
	virtual bool aplicaEstra(ContenedorM*) = 0;

};

#endif // !ESTRATEGIA_H
