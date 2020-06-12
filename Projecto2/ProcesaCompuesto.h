#ifndef PROCESACOMPUESTO_H
#define PROCESACOMPUESTO_H

#include"CampoResultante.h"
#include"ContenedorM.h"

using namespace std;

class ProcesaCompuesto {
private:
	ContenedorV* contVec;
	ContenedorM* contMat;
	int separador;
public:
	ProcesaCompuesto(ContenedorV* cv);
	virtual ~ProcesaCompuesto();
	void pasarInfoDeVecAMat();
	ContenedorM* getMatriz();
	void acomodo(int fil, int col);

};

#endif // !PROCESACOMPUESTO_H
