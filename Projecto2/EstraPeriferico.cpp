#include"EstraPeriferico.h"

EstraPeriferico::EstraPeriferico() {

}
EstraPeriferico:: ~EstraPeriferico() {

}
bool EstraPeriferico::aplicaEstra(ContenedorM* m) {

	int ultimo = m->getReciente();
	int col = m->columnaFinal();
	int x = 0;
	int y = 0;

	Punto* p = NULL; Punto* p1 = NULL; Punto* p2 = NULL; Punto* p3 = NULL; Punto* p4 = NULL;

	//Linea de Arriba
	for (int j = 0; j < col - 1; j++) {
		p = m->getPunto(0, j);
		p4 = m->getPunto(0, j + 1);
		if (m->compruebaTrazo(p, p4)) {//derecha
			if (p->getDerecha() != true && p4->getIzquierda() != true) {
				p->setDerecha(true);
				p4->setIzquierda(true);
				p->setNumPaso(ultimo + 1);
				p4->setNumPaso(ultimo + 1);
				return true;
			}
		}
	}
	//Linea de derecha
	for (int i = 0; i < 5; i++) {
		p = m->getPunto(i, col - 1);
		p1 = m->getPunto(i + 1, col - 1);
		if (m->compruebaTrazo(p, p1)) {//abajo
			if (p->getAbajo() != true && p1->getArriba() != true) {
				p->setAbajo(true);
				p1->setArriba(true);
				p->setNumPaso(ultimo + 1);
				p1->setNumPaso(ultimo + 1);
				return true;
			}
		}
	}

	//Linea de izquierda
	for (int i = 0; i < 5; i++) {
		p = m->getPunto(i, 0);
		p1 = m->getPunto(i + 1, 0);
		if (m->compruebaTrazo(p, p1)) {//abajo
			if (p->getAbajo() != true && p1->getArriba() != true) {
				p->setAbajo(true);
				p1->setArriba(true);
				p->setNumPaso(ultimo + 1);
				p1->setNumPaso(ultimo + 1);
				return true;
			}
		}
	}

	//Linea de abajo
	for (int i = 0; i < col - 1; i++) {
		p = m->getPunto(4, i);
		p4 = m->getPunto(4, i + 1);//derecha
		if (m->compruebaTrazo(p, p4)) {//derecha
			if (p->getDerecha() != true && p4->getIzquierda() != true) {
				p->setDerecha(true);
				p4->setIzquierda(true);
				p->setNumPaso(ultimo + 1);
				p4->setNumPaso(ultimo + 1);
				return true;
			}
		}
	}
	for (int i = 0; i < col - 1; i++) {
		p = m->getPunto(2, i);
		p4 = m->getPunto(2, i + 1);//derecha
		p3 = m->getPunto(3, i + 1);
		if (m->compruebaTrazo(p, p4)) {//derecha
			if (p->getDerecha() != true && p4->getIzquierda() != true && p3->getDesactivado()) {
				p->setDerecha(true);
				p4->setIzquierda(true);
				p->setNumPaso(ultimo + 1);
				p4->setNumPaso(ultimo + 1);
				return true;
			}
		}
	}

	//falta los lados de los del medio
	return false;//usar aleatoreo despues, si tira false... condicion afuera...
}
