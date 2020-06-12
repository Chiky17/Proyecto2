#pragma once
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include<string>
#include<iostream>

using namespace std;

static void imprimeCadena(string c) {
	cout << c << endl;
}
string leerCadena() {
	string x;
	getline(cin, x);
	for (size_t i = 0; i < x.length(); i++) {
		x[i] = toupper(x[i]);
	}
	return x;

}

string leerCadena2() {
	string x;
	getline(cin, x);
	return x;
}
char convaGenero() {
	char gen;
	bool flat = true;
	while (flat) {
		cin >> gen;
		gen = toupper(gen);
		if (gen == 'M' || gen == 'F') {
			cin.clear();
			cin.ignore(1024, '\n');
			return gen;
		}
		else {
			cout << "Caracter incorrecto, ingrese M (para masculino) o F(para femenino)-> ";
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
	return gen;
}

string enteroAstring(int c) {
	string cadena;
	cadena = to_string(c);
	return cadena;
}

string FloatAstring(float c) {
	string cadena;
	cadena = to_string(c);
	return cadena;
}

int leerEntero() {
	int n;
	bool continuar = true;
	while (true) {
		if (cin >> n) {
			cin.clear();
			cin.ignore(1024, '\n');

			return n;
		}
		else {
			cout << "Valor incorrecto.. digita un NUMERO" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

float leerFloat() {
	float n;
	bool continuar = true;
	while (true) {
		if (cin >> n) {
			cin.clear();
			cin.ignore(1024, '\n');

			return n;
		}
		else {
			cout << "Valor incorrecto.. digita UN NUMERO" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

void limpiaPantalla() {
	system("cls");
}

void esperandoEnter() {
	cin.get();
}
void imprimSinEndl(string s) {
	cout << s;
}
string mayuscula(string pal) {
	for (size_t i = 0; i < pal.length(); i++) {
		pal[i] = toupper(pal[i]);
	}
	return pal;
}

bool verificaContrasena(string x) {
	bool mayu = false, num = false;
	for (size_t i = 0; i < x.length(); i++) {
		if (isdigit(x[i])) {
			num = true;
		}
		if (isupper(x[i])) {

			mayu = true;
		}
	}
	if (mayu && num)
		return true;
	else
		return false;
}

string charAstring(char a) {
	string s(1, a);
	return s;
}