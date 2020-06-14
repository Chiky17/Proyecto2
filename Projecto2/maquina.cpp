#include "maquina.h"

maquina::maquina()
{
	estra = nullptr;
}

maquina::~maquina()
{
}

void maquina::setEstrategia(Estrategia* es)
{
	estra = es;
}

bool maquina::aplicarEstrategia(ContenedorM* matriz,Partida* parti)
{
	return estra->aplicaEstra(matriz,parti);
}
