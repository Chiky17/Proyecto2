#include"ContenedorM.h"
#include "arbitro.h"

ContenedorM::ContenedorM() {
	fil = 5;
	col = 70;
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			m[i][j] = NULL;
		}
	}
}
ContenedorM::~ContenedorM() {
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			if (m[i][j] != NULL) {
				delete m[i][j];
			}
		}
	}
}
void ContenedorM::ingresaPunto(int i, int j, Punto* p) { // Excepcion, el if dentro del try, else throw
	if ((i >= 0 && i < 5) && (j >= 0 && j < 70)) {
		m[i][j] = p;
	}
}

Punto* ContenedorM::getPunto(int i, int j) {
	if ((i >= 0 && i < 5) && (j >= 0 && j < 70)) {
		return m[i][j];
	}
	return NULL;
}
string ContenedorM::toString(string nom) {
	stringstream s;
	int k = 0;
	Punto* p = NULL;
	for (int i = 0; i < col; i++)
		if (m[0][i] != NULL)
			if (i == 0)
				s << "   " << i;
			else
				s << "    " << i;
	for (int i = 0; i < fil; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (m[i][j] != NULL)
			{
				p = m[i][j];
				if (p->getArriba())
				{
					/*if (compruebaCuadro(i, j))
						s << "  | j";
					else
						s << "  |  ";*/
					s << "  | " << puntoJugador(i, j, nom);
				}
				else
					s << "     ";
			}
		}
		if (m[i][k] != NULL)
			s << endl;
		s << i;
		//--------------------------------------------
		for (int j = 0; j < col; j++)
		{

			if (m[i][j] != NULL)
			{
				p = m[i][j];
				if (p->getDesactivado() != true) {//Se genera caracter si punto esta activado 

					if (p->getIzquierda() && p->getDerecha())
					{
						s << "--o--";
					}
					else
						if (p->getIzquierda())
						{
							s << "--o  ";
						}
						else
							if (p->getDerecha())
							{
								s << "  o--";
							}
					//---------------------------------------------
					if (p->getDerecha() == false && p->getIzquierda() == false)
					{
						s << "  o  ";
					}

				}
				if (p->getDesactivado() == true)//si esta desasactivado punto solo se pone espacio y as� no afectar las matrices de 15
				{
					s << "     ";
				}
			}
		}
		if (m[i][k] != NULL)
			s << endl;
	}
	s << endl;
	return s.str();
}

int ContenedorM::columnaFinal() {
	for (int i = 0; i < col; i++)
	{
		if (m[0][i] == NULL)
			return i;
	}
	return getCol();
}
bool ContenedorM::compruebaCuadro(int x1, int y1) // alguien tiene que recibir el caracter
{
	if (y1 != columnaFinal() - 1)
	{
		if (m[x1][y1]->getDerecha() && m[x1][y1]->getArriba())
			if (m[x1 - 1][y1]->getDerecha() && m[x1][y1 + 1]->getArriba())
				return true;
	}
	/*else
		if (m[x1][y1]->getIzquierda() && m[x1][y1]->getArriba())
			if (m[x1 - 1][y1]->getIzquierda())
				return true;*/
	return false;
}
string ContenedorM::puntoJugador(int x1, int y1, string nom)
{
	if (compruebaCuadro(x1, y1))
		return nom;
	else
		return " ";
}
bool ContenedorM::estaLlena()
{
	for(int i = 0; i < fil; i++)
		for (int j = 0; j < columnaFinal(); j++)
		{
			if (m[i][j] != NULL)
				if (i == 0 && j == 0)
				{
					if (!m[i][j]->getAbajo() || !m[i][j]->getDerecha())
						return false;
				}
				else
					if (i == 0)
					{
						if (!m[i][j]->getAbajo() || !m[i][j]->getDerecha() || !m[i][j]->getArriba())
							return false;
					}
					else
						if (j == 0)
						{
							if (j != columnaFinal() - 1)
							{
								if (!m[i][j]->getAbajo() || !m[i][j]->getDerecha() || !m[i][j]->getIzquierda())
									return false;
							}
							else
								if (!m[i][j]->getAbajo() || !m[i][j]->getIzquierda())
									return false;
						}
						else
							if (!m[i][j]->getAbajo() || !m[i][j]->getDerecha() || !m[i][j]->getArriba() || !m[i][j]->getIzquierda())
								return false;
		}
	return true;
}

int ContenedorM::getCol()
{
	return col;
}

bool ContenedorM::compruebaTrazo(Punto* p1, Punto* p2) {
	if (p1 == NULL || p2 == NULL) {
		return false;
	}
	if (p1->getDesactivado() || p2->getDesactivado()) {
		return false;
	}
	return true;
}

int ContenedorM::getReciente() {
	int con = 0;
	int colu = columnaFinal();
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < colu; j++) {
			if (m[i][j]->getNumPaso() > con)
				con = m[i][j]->getNumPaso();
		}
	}
	return con;
}
