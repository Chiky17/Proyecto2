#include"EstraCercano.h"

EstraCercano::EstraCercano() {

}
EstraCercano:: ~EstraCercano() {

}
bool EstraCercano::aplicaEstra(ContenedorM* m) {
	//hacer metedo para saber si la matriz esta llena que tire una exepcion...
	//pero afuera del metodo.. o en caso de que sea una matriz nula..
	bool flat = false;
	int ultimo = m->getReciente();
	int col = m->columnaFinal();
	int x = 0;
	int y = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < col; j++) {
			if (m->getPunto(i, j)->getDesactivado() == false) {
				if (m->getPunto(i, j)->getNumPaso() == ultimo) {
					x = i;
					y = j;
				}
			}
		}
	}

	Punto* p = NULL; Punto* p1 = NULL; Punto* p2 = NULL; Punto* p3 = NULL; Punto* p4 = NULL;

	//------------------------------------

	p = m->getPunto(x, y);
	p1 = m->getPunto(x + 1, y);//abajo
	p2 = m->getPunto(x - 1, y);//arriba
	p3 = m->getPunto(x, y - 1);//izquirda
	p4 = m->getPunto(x, y + 1);//derecha

	if (m->compruebaTrazo(p, p1)) {//abajo
		if (p->getAbajo() != true && p1->getArriba() != true) {
			p->setAbajo(true);
			p1->setArriba(true);
			p->setNumPaso(ultimo + 1);
			p1->setNumPaso(ultimo + 1);
			return true;
		}
	}
	if (m->compruebaTrazo(p, p2)) {//arriba
		if (p->getArriba() != true && p2->getAbajo() != true) {
			p->setArriba(true);
			p2->setAbajo(true);
			p->setNumPaso(ultimo + 1);
			p2->setNumPaso(ultimo + 1);
			return true;
		}
	}
	if (m->compruebaTrazo(p, p3)) {//izquierda
		if (p->getIzquierda() != true && p3->getDerecha() != true) {
			p->setIzquierda(true);
			p3->setDerecha(true);
			p->setNumPaso(ultimo + 1);
			p3->setNumPaso(ultimo + 1);
			return true;
		}
	}
	if (m->compruebaTrazo(p, p4)) {//derecha
		if (p->getDerecha() != true && p4->getIzquierda() != true) {
			p->setDerecha(true);
			p4->setIzquierda(true);
			p->setNumPaso(ultimo + 1);
			p4->setNumPaso(ultimo + 1);
			return true;
		}
	}
	return false;//si tira false que se use EstraAleatoreo... esto ya es afuera del método
}