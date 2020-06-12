#ifndef CAMPOQUINCEPUNTOS_H
#define CAMPOQUINCEPUNTOS_H

#include"CampoAbstracto.h"


class CampoQuincePuntos : public CampoAbstracto {
private:
	string codigo;

public:
	CampoQuincePuntos();
	virtual ~CampoQuincePuntos();
	string getCodigo();


};


#endif // !CAMPOQUINCEPUNTOS_H