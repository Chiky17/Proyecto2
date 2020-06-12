#ifndef CAMPORESULTANTE_H
#define CAMPORESULTANTE_H

#include"CampoAbstracto.h"
#include"ContenedorV.h"

class CampoResultante : public CampoAbstracto {
private:
	string codigo;
	ContenedorV* vec;
public:
	CampoResultante();
	virtual ~CampoResultante();
	string getCodigo();
	void ingresaCampo(CampoAbstracto*);
	ContenedorV* retornaContenedor();

};


#endif // !CAMPORESULTANTE_H
