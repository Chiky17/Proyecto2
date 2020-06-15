#ifndef ESTRAPERIFERICO_H
#define ESTRAPERIFERICO_H
#include"Estrategia.h"

class EstraPeriferico : public Estrategia {
public:
	EstraPeriferico();
	virtual ~EstraPeriferico();
	virtual bool aplicaEstra(ContenedorM*,Partida*);
	virtual string getNombreEstra();
};
#endif // !ESTRAPERIFERICO_H
