#ifndef ESTRAPERIFERICO_H
#define ESTRAPERIFERICO_H
#include"Estrategia.h"

class EstraPeriferico : public Estrategia {
public:
	EstraPeriferico();
	virtual ~EstraPeriferico();
	virtual bool aplicaEstra(ContenedorM*);

};
#endif // !ESTRAPERIFERICO_H
