#include"EstraIslas.h"
#include<time.h>

EstraIslas::EstraIslas() {

}
EstraIslas:: ~EstraIslas() {

}
string EstraIslas::getNombreEstra() {
	return "EstraIslas";
}
bool EstraIslas::aplicaEstra(ContenedorM* m,Partida* parti) {
	int con = 0;
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

	//cout << x << "y " << y << endl;
	//solo para saber los valores... quitar lo de arriba comentado..
	//------------------------------------
	p = m->getPunto(x, y);
	p1 = m->getPunto(x + 1, y);//abajo
	p2 = m->getPunto(x - 1, y);//arriba
	p3 = m->getPunto(x, y - 1);//izquirda
	p4 = m->getPunto(x, y + 1);//derecha

	if (m->compruebaTrazo(p, p1)) {//abajo
		if (p->getArriba() != true && p->getIzquierda() != true) {
			if (p->getAbajo() != true && p1->getArriba() != true) {
				p->setAbajo(true);
				p1->setArriba(true);
				//p->setNumPaso(ultimo + 1);// esta
				p1->setNumPaso(ultimo + 1);

				Jugada* jugadita = new Jugada(x, y, x + 1, y, 'M');
				parti->getJugadas()->insertarFinal(jugadita);

				return true;
			}
		}

	}
	if (m->compruebaTrazo(p, p4)) {//derecha
		if (p->getIzquierda() != true && p->getAbajo() != true) {
			if (p->getDerecha() != true && p4->getIzquierda() != true) {
				p->setDerecha(true);
				p4->setIzquierda(true);
				///p->setNumPaso(ultimo + 1);//esta
				p4->setNumPaso(ultimo + 1);

				Jugada* jugadita = new Jugada(x, y, x, y + 1, 'M');
				parti->getJugadas()->insertarFinal(jugadita);

				return true;
			}
		}
	}
	if (m->compruebaTrazo(p, p2)) {//arriba
		if (p->getIzquierda() == true) {
			if (p->getArriba() != true && p2->getAbajo() != true) {
				p->setArriba(true);
				p2->setAbajo(true);
				//p->setNumPaso(ultimo + 1);//esta
				p2->setNumPaso(ultimo + 1);

				Jugada* jugadita = new Jugada(x, y, x - 1, y, 'M');
				parti->getJugadas()->insertarFinal(jugadita);

				return true;
			}
		}
	}
	if (m->compruebaTrazo(p, p3)) {//izquierda
		if (p->getAbajo() == true) {
			if (p->getIzquierda() != true && p3->getDerecha() != true) {
				p->setIzquierda(true);
				p3->setDerecha(true);
				//p->setNumPaso(ultimo + 1);//esta
				p3->setNumPaso(ultimo + 1);

				Jugada* jugadita = new Jugada(x, y, x, y - 1, 'M');
				parti->getJugadas()->insertarFinal(jugadita);

				return true;
			}
		}
	}


	return false;
}