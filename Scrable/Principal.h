#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <vector>
#include <time.h>
#include <iostream>
#include "Bicola.h"
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Principal
{

	vector<char> jugador1;
	vector<char> jugador2;
	vector<char> palabra;
	Bicola<char> bicola;
	bool termino = false;
	int ganadas1=0;
	int ganadas2=0;
	

public:

	Principal();
	void generarFichas();
	int aleatorio();
	void tablero();
	void fichaJ1();
	void fichaJ2();
	void buscarPalabra();
	void verificarPalabra(int identifi);
	void reiniciarTablero();
	int findIndex(vector<char>& arr, char item);


};


#endif // !PRINCIPAL_H


