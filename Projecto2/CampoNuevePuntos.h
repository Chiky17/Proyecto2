#ifndef CAMPONUEVEPUNTOS_H
#define CAMPONUEVEPUNTOS_H

#include"CampoAbstracto.h"

class CampoNuevePuntos : public CampoAbstracto
{
	private:
		string codigo;

	public:
		CampoNuevePuntos();
		virtual ~CampoNuevePuntos();
		string getCodigo();


};
#endif // !CAMPONUEVEPUNTOS_H
