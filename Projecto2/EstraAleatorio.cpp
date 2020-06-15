#include"EstraAleatorio.h"
#include<time.h>
#include <stdlib.h>

EstraAleatorio::EstraAleatorio() {

}
EstraAleatorio:: ~EstraAleatorio() {

}
string EstraAleatorio::getNombreEstra() {
	return "EstraAleatorio";
}
bool EstraAleatorio::aplicaEstra(ContenedorM* m,Partida* parti) {
	//hacer metedo para saber si la matriz esta llena que tire una exepcion...
	//pero afuera del metodo.. o en caso de que sea una matriz nula..
	int ultimo = m->getReciente();
	//srand(time(NULL)); //es el mismo de abajo .. igual hay que quitarlo
	//srand((unsigned int)time(NULL)); //Poner semila afuera de método
	bool flat = false;
	int col = m->columnaFinal();
	int x = rand() % (5);
	int y = rand() % (col);


	Punto* p = NULL; Punto* p1 = NULL; Punto* p2 = NULL; Punto* p3 = NULL; Punto* p4 = NULL;

	while (!flat) {

		x = rand() % (5);
		y = rand() % (col);

		//cout << x << "y " << y << endl;
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
				flat = true;

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

	}
	return false;//no se que pasa si aletoreo no encuentra

}