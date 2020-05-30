#pragma once
#include <sstream>
#include "listaJugador.h"
using namespace std;

class jugador;
class listaJugador;

class empresaDots
{
private:
	string codigo; // se actualiza en cada simulacion de dia
	listaJugador* jugadores;
public:
	empresaDots();
	virtual ~empresaDots();

	// Estos 2 metodos para simular el cambio de dia
	void generaCodigo(); // genera un codigo nuevo
	void eliminaJugadores();
	void cambioDeDia();

	string getCodigo();

	void attach(jugador*);
	string mostrarJugadores(); // jugadores inscritos ese dia
	bool estaJugador(string);
	jugador* devuelveJugador(string);
};