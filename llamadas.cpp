#include "llamadas.h"
#include <string.h>
#include <sstream>

using namespace std;

Llamadas::Llamadas(int numero,double inicio, double final,int destino){
	this->numero=numero;
	this->inicio=inicio;
	this->final=final;
	this->destino=destino;
}

/*Llamadas::Llamadas(Llamadas& c){
	numero=c.numero;
	inicio=c.inicio;
	final=c.final;
	destino=c.destino;
}	

Llamadas::~Llamadas(){

}*/

string Llamadas::toString()const{
	stringstream ss;
	ss<<numero<<", "<<inicio<<", "<<final<<", "<<destino;
	return ss.str();
}

int Llamadas::getNumero()const{
	return numero;
}

double Llamadas::getInicio()const{
	return inicio;
}

double Llamadas::getFinal()const{
	return final;
}

int Llamadas::getDestino()const{
	return destino;
}