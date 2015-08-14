#ifndef LLAMADAS_H
#define LLAMADAS_H
#include <string>
using namespace std;

class Llamadas{
	int numero;
	double inicio;
	double final;
	int destino;
public:
	Llamadas(int,double,double,int);
	/*Llamadas(Llamadas&);
	~Llamadas();*/
	string toString()const;
	int getNumero()const;
	double getInicio()const;
	double getFinal()const;
	int getDestino()const;
};

#endif