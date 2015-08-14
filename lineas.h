#ifndef LINEAS_H
#define LINEAS_H
#include <string>
using namespace std;

class Lineas{
	int numero;
	int ID_Cliente;
public:
	Lineas(int,int);
	Lineas(Lineas&);
	~Lineas();
	string toString()const;
	int getNumero()const;
	int getIDCliente()const;
};

#endif