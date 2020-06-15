#pragma once
#include "ListaPartida.h"
#include "empresaDots.h"

class juego
{
	private:
		empresaDots* empresa;
		ListaPartida* partidas;
	public:
		juego();
		virtual ~juego();

		ListaPartida* getPartidas();
		empresaDots* getEmpresa();

		void guardarPartidas();
};