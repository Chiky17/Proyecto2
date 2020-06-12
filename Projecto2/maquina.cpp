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

void maquina::aplicarEstrategia(ContenedorM* matriz)
{
	estra->aplicaEstra(matriz);
}
