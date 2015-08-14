#include "lineas.h"
#include <string.h>
#include <sstream>

using namespace std;

Lineas::Lineas(int numero,int ID_Cliente){
	this->numero=numero;
	this->ID_Cliente=ID_Cliente;
}

Lineas::Lineas(Lineas& c){
	numero=c.numero;
	ID_Cliente=c.ID_Cliente;
}

Lineas::~Lineas(){

}

string Lineas::toString()const{
	stringstream ss;
	ss<<numero<<", "<<ID_Cliente;
	return ss.str();
}

int Lineas::getNumero()const{
	return numero;
}

int Lineas::getIDCliente()const{
	return ID_Cliente;
}
