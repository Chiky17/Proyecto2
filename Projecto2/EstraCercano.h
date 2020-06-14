#ifndef ESTRACERCANO_H
#define ESTRACERCANO_H
#include"Estrategia.h"

class EstraCercano : public Estrategia {
public:
	EstraCercano();
	virtual ~EstraCercano();
	virtual bool aplicaEstra(ContenedorM*,Partida*);

};
#endif // !ESTRACERCANO_H