#pragma once
#include "empresaDots.h"
#include"ProcesaCompuesto.h"
#include"CampoNuevePuntos.h"
#include"CampoSeisPuntos.h"
#include"CampoQuincePuntos.h"
#include"CampoResultante.h"
#include "Partida.h" 
#include "maquina.h"
#include "ListaPartida.h"
using namespace std;
class vista
{
public:
	static int menuGeneral();
	// Jugar

	static void menuJuego(ListaPartida*, empresaDots*);

	static bool iniciarSesion(empresaDots*);
	static int modoDeJuego();
	static ProcesaCompuesto* crearCampo();
	static void turnoJugador(char, ContenedorM*, Partida*);
	static void turnoJugadorCercano(char, ContenedorM*, Partida*);//para estrategia cercana
	static Partida* partidaJugadorJugador();
	static maquina* crearMaquina();
	static void turnoMaquina(ContenedorM*, Partida*, maquina*);
	static Partida* partidaJugadorMaquina();


	static int elegirRepeticion(ListaPartida*);
	static void verRepeticion(ListaPartida*);


	//Empresa - Jugador
	static void menuEmpresa(empresaDots*);
	static void suscribirJugador(empresaDots*);
	static void codigoActual(empresaDots*);
	static void jugadoresSuscritos(empresaDots*);
	static void simulacionCambioDia(empresaDots*);

	static void error();
};
