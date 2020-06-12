#include"ProcesaCompuesto.h"

ProcesaCompuesto::ProcesaCompuesto(ContenedorV* cv) {
	separador = 0;
	contVec = cv;
	contMat = new ContenedorM();
	pasarInfoDeVecAMat();
}
ProcesaCompuesto:: ~ProcesaCompuesto() {
	delete contMat;
	delete contVec;//preguntar...
}
void ProcesaCompuesto::pasarInfoDeVecAMat() {
	int con = 0;
	if (contVec->getCan() != 0) {
		for (int i = 0; i < contVec->getCan(); i++) {
			if (contVec->getCampo(i)->getCodigo() == "seisPuntos")
				acomodo(3, 2);

			if (contVec->getCampo(i)->getCodigo() == "nuevePuntos")
				acomodo(3, 3);

			if (contVec->getCampo(i)->getCodigo() == "quincePuntos")
				acomodo(5, 3);
		}
	}
}
void ProcesaCompuesto::acomodo(int fil, int col) {
	int con = 0;
	while (con != col) {
		for (int i = 0; i < 5; i++)
		{
			if (i < fil) {
				contMat->ingresaPunto(i, separador, new Punto());
			}
			else {
				contMat->ingresaPunto(i, separador, new Punto());//para campos de 6 y 9 , rellenar restantes para no afectar la de 15
				contMat->getPunto(i, separador)->setDesactivado(true);
			}

		}
		con++;
		separador++;
	}
}
ContenedorM* ProcesaCompuesto::getMatriz() {
	return contMat;
}