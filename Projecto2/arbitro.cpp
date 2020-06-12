#include "arbitro.h"
bool arbitro::compruebaRango(int x1, int y1, int x2, int y2, ContenedorM* matriz) // true si jugada valida
{
	if ((x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0) && (x2 < 5 && x1 < 5) && (y1 < matriz->columnaFinal() && y2 < matriz->columnaFinal()))
		return true;
	else
		return false;
}
bool arbitro::dirrecionJugada(int x1, int y1, int x2, int y2, ContenedorM* matriz)
{
	Punto* x1y1 = matriz->getPunto(x1, y1);
	Punto* x2y2 = matriz->getPunto(x2, y2);

	if (compruebaRango(x1, y1, x2, y2, matriz))
	{
		//   Que dirrecion se hace true
		if (x2 == x1 + 1 && y1 == y2) // (x1,y1)= abajo - (x2,y2)= arriba
		{
			if (comprobarAbajo(x2, y2, matriz))
			{
				x1y1->setAbajo(true);
				x2y2->setArriba(true);
				//return "abajo";
				return true;
			}
		}
		else
			if (x2 == x1 - 1 && y2 == y1) // (x1,y1)= arriba - (x2,y2)= abajo
			{
				x1y1->setArriba(true);
				x2y2->setAbajo(true);
				//return "arriba";
				return true;
			}
			else
				if (x1 == x2 && y2 == y1 - 1) // (x1,y1)= izquierda - (x2,y2)= derecha
				{
					x1y1->setIzquierda(true);
					x2y2->setDerecha(true);
					//return "izquierda";
					return true;
				}
				else
					if (x1 == x2 && y2 == y1 + 1) // (x1,y1)= derecha - (x2,y2)= izquierda
					{
						x1y1->setDerecha(true);
						x2y2->setIzquierda(true);
						//return "derecha";
						return true;
					}
	}
	else
		//return "invalido";
		return true;
}
bool arbitro::comprobarAbajo(int x2, int y2, ContenedorM* matriz)
{
	return !matriz->getPunto(x2, y2)->getDesactivado();
}