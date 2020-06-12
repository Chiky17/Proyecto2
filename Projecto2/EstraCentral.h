#ifndef ESTRACENTRAL_H
#define ESTRACENTRAL_H
#include"Estrategia.h"

class EstraCentral : public Estrategia {
public:
	EstraCentral();
	virtual ~EstraCentral();
	virtual bool aplicaEstra(ContenedorM*);

};
#endif // !ESTRACENTRAL_H
