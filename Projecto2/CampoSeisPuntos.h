#ifndef CAMPOSEISPUNTOS_H
#define CAMPOSEISPUNTOS_H

#include"CampoAbstracto.h"


class CampoSeisPuntos : public CampoAbstracto {
private:
	string codigo;

public:
	CampoSeisPuntos();
	virtual ~CampoSeisPuntos();
	string getCodigo();


};

#endif // !CAMPOSEISPUNTOS_H