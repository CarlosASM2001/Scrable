#include "Principal.h"



Principal::Principal() {

	srand(time(NULL));
	generarFichas();
	tablero();

}

void Principal::generarFichas() {

	for (int i = 0; i < 7;i++) {
		jugador1.push_back(char(aleatorio()));
		jugador2.push_back(char(aleatorio()));

	}

}

int Principal::aleatorio() {

	int random = (97 + rand() % (122 - 97));

	return random;
}

void Principal::tablero() {

	char opcion='s';

	
	do {

		bool band1 = false;
		bool band2 = false;

		system("cls");
		cout << ' ' << endl;
		cout << ' ' << endl;
		cout << ' ' << endl;
		cout <<setw(90)<< "*********************************************************" << endl;
		cout<<setw(72)<< "EL GANADOR DEL SORTEO ES!!" << endl;
		cout <<setw(90)<< "*********************************************************" << endl;
		cout << ' ' << endl;
		cout << ' ' << endl;
		cout << ' ' << endl;
		system("PAUSE");
		srand(time(NULL));
		int random = (1 + rand()) % (3 - 1);

		

		while (!termino) {

			if (random == 1) {
				
				band1 = true;

				fichaJ1();
				if (termino) { break; }
				fichaJ2();
			}
			else {
				
				band2 = true;

				fichaJ2();
				if (termino) { break; }
				fichaJ1();
			}
		

			
			if ((jugador1.size() == 0) && (jugador2.size() == 0)) {
				system("cls");
				cout <<setw(25)<< "\n\n\nJugador 1 y Jugador 2 se quedaron sin fichas, reiniciando juego" << endl;
				bicola.Vaciar();
				generarFichas();
				break;
			}


		}


		if (termino) {
			reiniciarTablero();
		}





		cout << "Continuar Jugando? (s/n)" << endl;
		opcion = _getch();

		

	} while (opcion=='s');
	

}

void Principal::fichaJ1() {

	char opc;
	char deseo;
	char lado;
	bool opcion=true;
	bool encontrado = false;


	system("cls");

	bicola.imprimir();
	cout << " " << endl;

	cout << ' ' << endl;
	cout << ' ' << endl;
	cout << ' ' << endl;
	cout << ' ' << endl;
	cout << ' ' << endl;
	cout << ' ' << endl;
	cout << setw(70) << "*********************************************************" << endl;
	cout <<setw(50)<<"FICHAS Jugador 1" << endl;
	for (int i = 0;i < jugador1.size();i++) {
		cout <<setw(10)<< jugador1[i];
	}
	cout << " " << endl;

	cout << setw(105) << "Partidas Ganadas" << endl;
	cout << setw(100) << "jugador 1: " << ganadas1 << endl;
	cout << setw(100) << "jugador 2: " << ganadas2 << endl;

	if (jugador1.size() == 0) {
		return;
	}

	cout << "Desea jugar esta ronda?(s/n)" << endl;
	deseo = _getch();



	if (deseo == 's') {
		while (!encontrado) {
			cout << "Elige una ficha: " << endl;
			opc = _getch();
			auto pos = findIndex(jugador1, opc);
			if (pos != -1) {

				cout << "Agregar Izquierda o Derecha (i/d): " << endl;
				lado = _getch();
				if (lado == 'i') {
					opcion = true;
				}
				else if (lado == 'd') {
					opcion = false;
				}
				bicola.Agregar(opc, opcion);
				encontrado = true;


				auto element_remove = jugador1.begin() + pos;
				if (element_remove != jugador1.end()) {
					jugador1.erase(element_remove);
				}

			}
			else {
				cout << "No tienes esa ficha" << endl;
			}

		}

		verificarPalabra(1);

	}
	else {
		cout << "....pasando ronda" << endl;
	}


	

}

void Principal::fichaJ2() {

	char opc;
	char deseo;
	char lado;
	bool opcion = true;
	bool encontrado = false;


	system("cls");

	bicola.imprimir();
	cout << " " << endl;
	cout << ' ' << endl;
	cout << ' ' << endl;
	cout << ' ' << endl;
	cout << ' ' << endl;
	cout << ' ' << endl;
	cout << ' ' << endl;
	cout << setw(70) << "*********************************************************" << endl;
	cout <<setw(50)<< "FICHAS Jugador 2" << endl;
	for (int i = 0;i < jugador2.size();i++) {
		cout <<setw(10)<< jugador2[i];
	}
	cout << " " << endl;

	cout << setw(105) << "Partidas Ganadas" << endl;
	cout << setw(100) << "jugador 1: " << ganadas1 << endl;
	cout << setw(100) << "jugador 2: " << ganadas2 << endl;

	if (jugador2.size() == 0) {
		return;
	}

	cout << "Desea jugar esta ronda?(s/n)" << endl;
	deseo = _getch();

	if (deseo == 's') {
		while (!encontrado) {
			cout << "Elige una ficha: " << endl;
			opc = _getch();

			auto pos = findIndex(jugador2, opc);
			if (pos != -1) {

				cout << "Agregar Izquierda o Derecha (i/d): " << endl;
				lado = _getch();
				if (lado == 'i') {
					opcion = true;
				}
				else if (lado == 'd') {
					opcion = false;
				}
				bicola.Agregar(opc, opcion);
				encontrado = true;


				auto element_remove = jugador2.begin() + pos;
				if (element_remove != jugador2.end()) {
					jugador2.erase(element_remove);
				}


			}
			else {
				cout << "No tienes esa ficha" << endl;
			}

		}

		verificarPalabra(2);

	}
	else {
		cout << ".....pasando ronda" << endl;
	}

	

}

int Principal::findIndex(vector<char>& arr, char item) {

	auto ret = std::find(arr.begin(), arr.end(), item);

	if (ret != arr.end())
		return ret - arr.begin();
	return -1;
}

void Principal::verificarPalabra(int identi) {

	int tam=0;

	palabra = bicola.Devolver();
	tam = palabra.size();

	/*for (int i = 0; i < palabra.size(); i++) {
		cout << "vector palabra: " << palabra[i] << endl;
	}*/

	if (tam >= 3) {
		buscarPalabra();
		if (termino) {
			
			if (identi == 1) {
				cout <<setw(30)<< "Es el jugador numero 1" << endl;
				ganadas1++;
			}
			else {
				cout <<setw(30)<< "Es el jugador numero 2" << endl;
				ganadas2++;
			}

		}

	}

	system("PAUSE");

}

void Principal::buscarPalabra() {

	string nombreArchivo = "Diccionario.txt";
	fstream archivo(nombreArchivo.c_str());
	string linea;

	string s(palabra.begin(), palabra.end());
	
	system("cls");
	//cout <<setw(55)<< "palabra " << s << endl;


	if (archivo.fail()) {
		cout << "Archivo " << nombreArchivo << " genero error" << endl;
	}
	else {
		while (getline(archivo, linea)) {

			if (strcmp((char*)s.c_str(), (char*)linea.c_str()) == 0) {
				termino = true;
				cout <<setw(48)<< "GANADOR CON LA PALABRA!!" << endl;
				cout <<setw(48)<< s << endl;
				break;
			}
			


		}
		if (!termino) {
			cout <<setw(30)<< "\n\n\nLa palabra " << s << " no existe en el diccionario" << endl;
		}
	}


	





}

void Principal::reiniciarTablero() {

	char lado;
	bool opcion=false;
	char res;

	system("cls");

	do {
		bicola.imprimir();
		cout << "\nReiniciando Tablero" << endl;
		cout << ' ' << endl;
		cout << "Eliminar Izquierda o Derecha (i/d): " << endl;
		lado = _getch();
		if (lado == 'i') {
			opcion = true;
		}
		else if (lado == 'd') {
			opcion = false;
		}

		bicola.Eliminar(lado, opcion);


		cout << "Desea Seguir Eliminando?(s/n)" << endl;
		res = _getch();

	} while (res == 's');
	
	jugador1.clear();
	jugador2.clear();
	generarFichas();
	termino = false;














}