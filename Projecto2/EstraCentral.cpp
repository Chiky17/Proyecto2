#include"EstraCentral.h"

EstraCentral::EstraCentral() {

}
EstraCentral:: ~EstraCentral() {

}
string EstraCentral::getNombreEstra() {
	return "EstraCentral";
}
bool EstraCentral::aplicaEstra(ContenedorM* m,Partida* parti) {
	int ultimo = m->getReciente();
	int con = 0;
	int col = m->columnaFinal();
	int mitad = col / 2;
	int x = rand() % (5);
	int y = rand() % (col);


	Punto* p = NULL; Punto* p1 = NULL; Punto* p2 = NULL; Punto* p3 = NULL; Punto* p4 = NULL;

	while (con < 4) {

		x = 2 + rand() % (3 - 2);
		if (mitad > 3) {
			y = 2 + rand() % ((mitad + 1) - 2);
		}
		else {
			y = 1 + rand() % (col - 1);
		}


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

				Jugada* jugadita = new Jugada(x, y, x + 1, y, 'M');
				parti->getJugadas()->insertarFinal(jugadita);

				return true;
			}
		}

		if (m->compruebaTrazo(p, p2)) {//arriba
			if (p->getArriba() != true && p2->getAbajo() != true) {
				p->setArriba(true);
				p2->setAbajo(true);
				p->setNumPaso(ultimo + 1);
				p2->setNumPaso(ultimo + 1);

				Jugada* jugadita = new Jugada(x, y, x - 1, y, 'M');
				parti->getJugadas()->insertarFinal(jugadita);

				return true;
			}
		}

		if (m->compruebaTrazo(p, p3)) {//izquierda
			if (p->getIzquierda() != true && p3->getDerecha() != true) {
				p->setIzquierda(true);
				p3->setDerecha(true);
				p->setNumPaso(ultimo + 1);
				p3->setNumPaso(ultimo + 1);

				Jugada* jugadita = new Jugada(x, y, x, y - 1, 'M');
				parti->getJugadas()->insertarFinal(jugadita);

				return true;
			}
		}

		if (m->compruebaTrazo(p, p4)) {//derecha
			if (p->getDerecha() != true && p4->getIzquierda() != true) {
				p->setDerecha(true);
				p4->setIzquierda(true);
				p->setNumPaso(ultimo + 1);
				p4->setNumPaso(ultimo + 1);

				Jugada* jugadita = new Jugada(x, y, x, y + 1, 'M');
				parti->getJugadas()->insertarFinal(jugadita);

				return true;
			}
		}
		con++;
	}
	return false;//si tira false usar aleatoreo...
}