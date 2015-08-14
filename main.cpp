#include "ciudad.h"
#include "cliente.h"
#include "lineas.h"
#include "llamadas.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>

void WCiudadBin();
void WClienteBin();
void WLineaBin();
void WLlamadaBin();
void RCiudadBin();
void RClienteBin();
void RLineaBin();
void RLlamadaBin();

using namespace std;

/*struct Ciudad{
	int ID_Ciudad;
	char nombre[40];
};

struct Cliente{
	int ID_Cliente;
	char nombre[40];
	char genero;
	int ID_Ciudad;
};

struct Linea{
	int ID_Cliente;
	int numero;
};

struct Llamada{
	int numero;
	char* inic;
	char fin[14];
	int destino;
};

ostream& operator <<(ostream& output, const Linea& line){
	output <<line.numero<<","<<line.ID_Cliente;
	return output;
}

ostream& operator <<(ostream& output, const Llamada& call){
	output <<call.numero<<','<<call.inic<<','<<call.fin<<','<<call.destino;
	return output;
}


vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str); // Convierte a stringstream
	string tok;
	while(getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}
	return internal;
}


int main(int argc, char const *argv[]){
	ifstream infile;
	infile.open("llamada.txt",ifstream::in);
	string str;
	//stringstream ss(str);
	
	if(infile.is_open()){
		while (getline(infile, str)){
			vector<string> linea_str = split(str,',');
			Llamada nuevo;
			nuevo.numero=atoi(linea_temp.at(0).c_str());
			strcpy(nuevo.inic,linea_temp.at(1).c_str());
			strcpy(nuevo.fin,linea_temp.at(2).c_str());
			nuevo.destino=atoi(linea_temp.at(3).c_str());
			cout<<nuevo<<endl;
		};
		infile.close();
	}
	return 0;
}*/



int main(int argc, char const *argv[]){
	/*RCiudadBin();
	RClienteBin();
	RLineaBin();
	RLlamadaBin();*/
	WCiudadBin();
	WClienteBin();
	WLineaBin();
	WLlamadaBin();
	
	return 0;
}

void RCiudadBin(){
	ifstream infile("ciudades.bin",ios::binary);
	infile.seekg(0);
	while(!infile.eof()){
		char IdCiudad[4];
		char NombreCiudad[40];
		infile.read((char*)IdCiudad, sizeof(IdCiudad));
		infile.read((char*)NombreCiudad, sizeof(NombreCiudad));
	}
	infile.close();
}

void RClienteBin(){
	ifstream infile("clientes.bin",ios::binary);
	infile.seekg(0);
	while(!infile.eof()){
		char IdCliente[14];
		char NombreCliente[40];
		char Genero[2];
		char IdCiudad[4];
		infile.read((char*)IdCliente, sizeof(IdCliente));
		infile.read((char*)NombreCliente, sizeof(NombreCliente));
		infile.read((char*)Genero, sizeof(Genero));
		infile.read((char*)IdCiudad, sizeof(IdCiudad));
		cout <<IdCliente << " | " << NombreCliente << " | " << Genero << " | " << IdCiudad <<endl;
	}
	infile.close();
}

void RLineaBin(){
	ifstream infile("linea.bin",ios::binary);
	infile.seekg(0);
	while(!infile.eof()){
		char Numero[9];
		char Id[14];
		infile.read((char*)Numero, sizeof(Numero));
		infile.read((char*)Id, sizeof(Id));
		cout <<Numero << " | " << Id << endl;
	}
	infile.close();
}

void RLlamadaBin(){
	ifstream infile("llamada.bin",ios::binary);
	infile.seekg(0);
	while(!infile.eof()){
		char Numero[9];
		char inic[20];
		char fin[20];
		char IdCiudad[4];
		infile.read((char*)Numero, sizeof(Numero));
		infile.read((char*)inic, sizeof(inic));
		infile.read((char*)fin, sizeof(fin));
		infile.read((char*)IdCiudad, sizeof(IdCiudad));
		cout <<Numero << " | " << inic << " | " << fin << " | " << IdCiudad <<endl;
	}
	infile.close();
}

void WCiudadBin(){
	ifstream infile("ciudad.txt");
	ofstream outFile("ciudad.bin");
	while(!infile.eof()){
		char NombreCiudad[40];
		char IdCiudad[4];
		string str1 = "", str2 = "";
		getline(infile, str1, ',');
		getline(infile, str2, ',');
		for (int i = 0; i < 40; ++i){
			NombreCiudad[i] = str1[i];
		}
		for (int i = 0; i < 4; ++i){
			IdCiudad[i] = str2[i];
		}
		outFile.write((char*)IdCiudad, sizeof(IdCiudad));
		outFile.write((char*)NombreCiudad, sizeof(NombreCiudad));
	}
	infile.close();
	outFile.close();
}

void WClienteBin(){
	ifstream infile("cliente.txt");
	ofstream outFile("cliente.bin");
	while(!infile.eof()){
		char IdCliente[14];
		char NombreCliente[40];
		char Genero[2];
		char IdCiudad[4];
		string str1 = "", str2 = "",str3 = "",str4 = "";
		getline(infile, str1, ',');
		getline(infile, str2, ',');
		getline(infile, str3, ',');
		getline(infile, str4, ',');
		for (int i = 0; i < 14; ++i){
			IdCliente[i] = str1[i];
		}
		for (int i = 0; i < 40; ++i){
			NombreCliente[i] = str2[i];
		}
		for (int i = 0; i < 2; ++i){
			Genero[i] = str3[i];
		}
		for (int i = 0; i < 4; ++i){
			IdCiudad[i] = str4[i];
		}
		outFile.write((char*)IdCliente, sizeof(IdCliente));
		outFile.write((char*)NombreCliente, sizeof(NombreCliente));
		outFile.write((char*)Genero, sizeof(Genero));
		outFile.write((char*)IdCiudad, sizeof(IdCiudad));
	}
	infile.close();
	outFile.close();
	
}

void WLineaBin(){
	ifstream infile("linea.txt");
	ofstream outFile("linea.bin");
	while(!infile.eof()){
		char Id[14];
		char Numero[9];
		string str1 = "", str2 = "";
		getline(infile, str1, ',');
		getline(infile, str2, ',');
		for (int i = 0; i < sizeof(Id); ++i){
			Id[i] = str1[i];
		}
		for (int i = 0; i < sizeof(Numero); ++i){
			Numero[i] = str2[i];
		}
		outFile.write((char*)Numero, sizeof(Numero));
		outFile.write((char*)Id, sizeof(Id));
	}
	infile.close();
	outFile.close();
	
}

void WLlamadaBin(){
	ifstream infile("llamada.txt");
	ofstream outFile("llamada.bin");
	while(!infile.eof()){
		char Numero[9];
		char inic[20];
		char fin[20];
		char IdCiudad[4];
		string str1 = "", str2 = "",str3 = "",str4 = "";
		getline(infile, str1, ',');
		getline(infile, str2, ',');
		getline(infile, str3, ',');
		getline(infile, str4, ',');
		for (int i = 0; i < sizeof(Numero); ++i){
			Numero[i] = str1[i];
		}
		for (int i = 0; i < sizeof(inic); ++i){
			inic[i] = str2[i];
		}
		for (int i = 0; i < sizeof(fin); ++i){
			fin[i] = str3[i];
		}
		for (int i = 0; i < sizeof(IdCiudad); ++i){
			IdCiudad[i] = str4[i];
		}
		outFile.write((char*)Numero, sizeof(Numero));
		outFile.write((char*)inic, sizeof(inic));
		outFile.write((char*)fin, sizeof(fin));
		outFile.write((char*)IdCiudad, sizeof(IdCiudad));
	}
	infile.close();
	outFile.close();
}
