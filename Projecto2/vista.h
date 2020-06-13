#pragma once
#include "empresaDots.h"
#include"ProcesaCompuesto.h"
#include"CampoNuevePuntos.h"
#include"CampoSeisPuntos.h"
#include"CampoQuincePuntos.h"
#include"CampoResultante.h"
#include "Partida.h"
using namespace std;
class vista
{
public:
	static int menuGeneral();
	// Jugar
	static int menuJuego();
	static bool iniciarSesion(empresaDots*);
	static int modoDeJuego();
	static ProcesaCompuesto* crearCampo();
	static Partida* partidaJugadorJugador();
	static void turnoJugador(char, ContenedorM*, Partida*);
	//static 
	//Empresa - Jugador
	static int menuEmpresa();
	static void suscribirJugador(empresaDots*);
	static void codigoActual(empresaDots*);
	static void jugadoresSuscritos(empresaDots*);
	static void simulacionCambioDia(empresaDots*);

};
