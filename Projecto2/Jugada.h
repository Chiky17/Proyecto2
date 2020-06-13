#pragma once
#include<sstream>
#include<string>

using namespace std;

class Jugada {
private:
	int posX1;
	int posY1;
	int posX2;
	int posY2;
	char nombre;
public:
	Jugada(int=0, int = 0, int = 0, int = 0, char='.');
	~Jugada();
	int getposX1();
	int getposX2();
	int getposY1();
	int getposY2();
	char getNombre();

	void setposX1(int);
	void setposX2(int);
	void setposY1(int);
	void setposY2(int);
	void setNombre(char);

	string toString();

};