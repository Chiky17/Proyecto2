#include "controladora.h"
#include <fstream>
#include "arbitro.h"
#include "ListaPartida.h"
int main()
{
	//controladora con;
	//con.controlMenuEmpresa();

	/*ListaPartida* partidas = new ListaPartida;
	partidas = ListaPartida::recuperarPartidas();*/


	/*Partida* partidita = vista::partidaJugadorMaquina();
	system("cls");
	Partida* partidita1 = vista::partidaJugadorMaquina();
	partidas->insertarFinal(partidita);
	partidas->insertarFinal(partidita1);

	partidas->guardarPartidas();*/




	//// repeticion de todas
	//int j = 0;
	//Jugada* jugadita;
	//ContenedorM* matriz;
	//for (int i = 1; i <= partidas->cuentaNodos(); i++)
	//{
	//	j = partidas->obtPartida(i)->getJugadas()->cuentaNodos();
	//	matriz = partidas->obtPartida(i)->getProCompu()->getMatriz();
	//	for (int k = 1; k <= j; k++)
	//	{
	//		jugadita = partidas->obtPartida(i)->getJugadas()->obtJugada(k);
	//		arbitro::dirrecionJugada(jugadita->getposX1(), jugadita->getposY1(), jugadita->getposX2(), jugadita->getposY2(), matriz);
	//		cout << "\n" << matriz->toString('M');
	//		system("cls");
	//	}
	//	system("pause");
	//}

	vista::partidaJugadorMaquina();
}

