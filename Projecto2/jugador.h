#pragma once
#include <sstream>
#include <iostream>
#include "empresaDots.h"
using namespace std;

class empresaDots;
class listaJugador;

class jugador
{
private:
	string nombre;
	string cedula;
	empresaDots* empresa;
public:
	jugador(string, string, empresaDots*);
	virtual ~jugador();

	string getCedula();

	string toString() const; // Para la empresa - Muestra nombre e id
	string mostrarCodigo(); // Se extrae el codigo (diario) de la empresa
};
