#pragma once
#include "empresaDots.h"

class vista
{
public:
	static int menuGeneral();
	// Jugar
	static int menuJuego();
	static bool iniciarSesion(empresaDots*);
	static int modoDeJuego();
	//Empresa - Jugador
	static int menuEmpresa();
	static void suscribirJugador(empresaDots*);
	static void codigoActual(empresaDots*);
	static void jugadoresSuscritos(empresaDots*);
	static void simulacionCambioDia(empresaDots*);

};
