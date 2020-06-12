#pragma once
#include "ContenedorM.h"

class arbitro // quizas clase servicio (static)
{
public:
	static bool compruebaRango(int, int, int, int, ContenedorM*);
	static bool dirrecionJugada(int, int, int, int, ContenedorM*);
	static bool comprobarAbajo(int, int, ContenedorM*);
};
