#pragma once
#include "vista.h"
#include "juego.h"


class controladora
{
private:
	juego* _juego;
public:
	controladora();
	virtual ~controladora();

	void control1();
	int control2();

};