#include "cliente.h"
#include <string.h>
#include <sstream>

using namespace std;

Cliente::Cliente(int ID_Cliente,char* nombre,char genero,int ID_Ciudad){
	this->ID_Cliente=ID_Cliente;
	this->nombre=new char[strlen(nombre)+1];
	strcpy(this->nombre,nombre);
	this->genero=genero;
	this->ID_Ciudad=ID_Ciudad;
}

Cliente::Cliente(const Cliente& c){
	ID_Cliente=c.ID_Cliente;
	nombre=new char[strlen(c.nombre)+1];
	strcpy(nombre,c.nombre);
	genero=c.genero;
	ID_Ciudad=c.ID_Ciudad;
}

Cliente::~Cliente(){
	/*if(name){
		delete[] name;
	}*/
}

string Cliente::toString()const{
	stringstream ss;
	ss<<ID_Cliente<<", "<<nombre<<", "<<genero<<", "<<ID_Ciudad;
	return ss.str();
}

int Cliente::getIDCliente()const{
	return ID_Cliente;
}

char* Cliente::getNombre()const{
	return nombre;
}

char Cliente::getGenero()const{
	return genero;
}

int Cliente::getIDCiudad()const{
	return ID_Ciudad;
}