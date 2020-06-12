#ifndef CAMPOABSTRACTO_H
#define CAMPOABSTRACTO_H

#include<string>
#include<sstream>
#include<iostream>

using namespace std;

class CampoAbstracto {
public:
	CampoAbstracto() {}
	virtual ~CampoAbstracto() {}
	virtual string getCodigo() = 0;

};


#endif // !CAMPOABSTRACTO_H
