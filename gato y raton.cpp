#include<string.h>
#include<string>
#include"Inteligencia.h"


string** matriz;
int opcion, lugar, opcion2;

void inicializar();
void vs(int,string,string);
void limpiarMatriz(string**);
int contador = 0, jugador1 = 0, jugador2 = 0, empate = 0 ;
int band = 0;

int main(){
char dato[50], dato1[50];
	do {
		cout << "\t.>>Menu<<" << endl;
		cout << "1.-Jugar vs consola" << endl;
		cout << "2.-Jugar jugador1 vs jugador2" << endl;
		cout << "3.-Revisar puntajes"<<endl;
		cout << "Salir del juego" << endl;
		cout << "Digita una opcion \n[]>>";cin >> opcion2;
		switch (opcion2) {
		case 1:vs(1,"X","O");break;
		case 2:
			cin.ignore();
			cout << "Objeto del primer Jugador []>> ";cin.getline(dato, 2, '\n');
			cout << "Objeto del segundo jugador []>>";cin.getline(dato1, 2, '\n');
			vs(2,dato,dato1);break;
		case 3: limpiarMatriz(matriz);
			break;
		default: cout << "opcion no encotrada" << endl;
		}
		
	} while (opcion2 != 3);
	return 0;
}
void inicializar() {
	matriz = new string * [3];
	for (int i = 0;i < 3;i++) {
		matriz[i] = new string[3];
	}
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			*(*(matriz + i) + j) = " ";
		}
	}
}
void vs(int opcion3, string dato1, string dato2) {
	inicializar();
	Cuerpo* juego1 = new Cuerpo(matriz, 3, 3, dato1, dato2, jugador1, jugador2);
	juego1->mostrarDatos();
	while (contador <= 4) {
		do {
			cout << "(Jugador 1)Digita el lugar [1-9] >> "; cin >> lugar;
			juego1->mover(lugar);
			juego1->setAgregarAljuego(juego1->getX(), juego1->getY(), juego1->getDatoX());
		} while (juego1->getS() != 1);
		juego1->mostrarDatos();
		juego1->revisar(juego1->getDatoX());

		if (juego1->revisar(juego1->getDatoX()) == 1) {
			cout << "\n\n\n";
			cout << "Gana el jugador 1" << endl;
			juego1->mostrarDatos();
			juego1++;
			break;
		}
		else if (juego1->revisarMatrizLlena() == 1) {
			cout << "\n\n\n";
			cout << "\tEsto es un empate" << endl;
			empate++;
			break;
		}
		do {
			switch (opcion3) {
			case 1:lugar = 1 + rand() % (10 - 1);break;
			case 2: cout << "(Jugador 2)Digita el lugar [1-9] >> "; cin >> lugar;
				break;
			default: cout << " " << endl;
			}
			juego1->mover(lugar);
			juego1->setAgregarAljuego(juego1->getX(), juego1->getY(), juego1->getDAtoY());
		} while (juego1->getS() != 1);
		if (opcion3 == 2) {
			juego1->mostrarDatos();
		}
		else if (opcion3 == 1) {
			cout << "Turno de Consola" << endl;
			juego1->mostrarDatos();
		}
		juego1->revisar(juego1->getDAtoY());
		if (juego1->revisar(juego1->getDAtoY()) == 1) {
			cout << "\n\n\n";
			cout << "\tGana el jugador 2" << endl;
			juego1->mostrarDatos();
			jugador2++;
			break;
		}
		else if (juego1->revisarMatrizLlena() == 1) {
			cout << "Esto es un empate" << endl;
			empate++;
			break;
		}
		juego1->revisarMatrizLlena();
	}
}

void limpiarMatriz(string **matriz) {
	for (int i = 0;i < 3;i++) {
		delete[] matriz[i];
	}delete[] matriz;
}
