#ifndef CIUDAD_H
#define CIUDAD_H
#include <string>
using namespace std;

class Ciudad{
	int ID_Ciudad;
	char* nombre;
public:
	Ciudad(int,char*);
	Ciudad(const Ciudad&);
	~Ciudad();
	string toString()const;
	int getID()const;
	char* getNombre()const;
};

#endif