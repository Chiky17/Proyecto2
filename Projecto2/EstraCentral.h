#ifndef ESTRACENTRAL_H
#define ESTRACENTRAL_H
#include"Estrategia.h"

class EstraCentral : public Estrategia {
public:
	EstraCentral();
	virtual ~EstraCentral();
	virtual bool aplicaEstra(ContenedorM*,Partida*);

};
#endif // !ESTRACENTRAL_H
