#include "ciudad.h"
#include <string.h>
#include <sstream>

using namespace std;

Ciudad::Ciudad(int ID_Ciudad,char* nombre){
	this->ID_Ciudad=ID_Ciudad;
	this->nombre=new char[strlen(nombre)+1];
	strcpy(this->nombre,nombre);
}

Ciudad::Ciudad(const Ciudad& c){
	ID_Ciudad=c.ID_Ciudad;
	nombre=new char[strlen(c.nombre)+1];
	strcpy(nombre,c.nombre);
}

Ciudad::~Ciudad(){
	/*if(nombre){
		delete[] nombre;
	}*/
}

string Ciudad::toString()const{
	stringstream ss;
	ss<<ID_Ciudad<<", "<<nombre;
	return ss.str();
}

int Ciudad::getID()const{
	return ID_Ciudad;
}

char* Ciudad::getNombre()const{
	return nombre;
}