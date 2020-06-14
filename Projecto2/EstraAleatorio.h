#ifndef ESTRAALEATORIO_H
#define ESTRAALEATORIO_H
#include"Estrategia.h"

class EstraAleatorio : public Estrategia {
public:
	EstraAleatorio();
	virtual ~EstraAleatorio();

	virtual bool aplicaEstra(ContenedorM*,Partida*);

};
#endif // !ESTRAALEATORIO_H
