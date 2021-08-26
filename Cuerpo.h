#include <iostream>
#include<math.h>
using namespace std;

class Cuerpo {
private:
	int jugadas, jugador, nfilas, ncolumanas, ganador;
	string **tablero1;
	int s;
	bool salir;
	string dato1;
	string dato2;
	int x, y;
	int jugador1 = 0, jugador2 = 0, contador =0;

public:
	
	Cuerpo(string **tablero, int nfilas,int ncolumnas,string dato1, string dato2, int jugador1, int jugador2 ) {
		this->tablero1 = tablero;
		this->nfilas = nfilas;
		this->ncolumanas = ncolumnas;
		this->dato1 = dato1;
		this->jugador1 = jugador1;
		this->jugador2 = jugador2;
		this->dato2 = dato2;
	}
	~Cuerpo() {

	}
	void** setTablero(string** tablero) {
		this->tablero1 = tablero;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {

	this->y = y;
	}
	string getDatoX() {
		return dato1;
	}
	string getDAtoY() {
		return dato2;
	}
	string **getTablero() {
		return tablero1;
	}
	void setContador(int contador) {
		this->contador = contador;
	}
	int getContador() {
		return contador;
	}

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void setJugador1(int f) {
		this->jugador1 = f;
	}
	void setJugador2(int g) {
		this->jugador2 = g;
	}
	int getJugador1() {
		return jugador1;
	}
	int getJugador2() {
		return jugador2;
	}
	string  **mostrarDatos() {
		int contador = 0;
		for (int i = 0;i < nfilas;i++) {
			for (int j = 0;j < ncolumanas;j++) {
				contador++;
				cout << contador;
					cout << "|" << *(*(tablero1 + i) + j) << "|";
			}cout << "\n";
		}
		return tablero1;
	}
	string **setAgregarAljuego(int x, int y, string dato) {
			if (tablero1[x][y] == dato1 || tablero1[x][y] == dato2) {
				setS(2);
			}
			else {
				tablero1[x][y] = dato;
				setS(1);
			}
		return tablero1;
	}

	void setS(int s) {
		this->s = s;
	}
	int getS() {
		return s;
	}
	void mover(int lugar) {
		switch (lugar) {
		case 1:setX(0), setY(0);break;
		case 2:setX(0), setY(1);break;
		case 3:setX(0), setY(2);break;
		case 4:setX(1), setY(0);break;
		case 5:setX(1), setY(1);break;
		case 6:setX(1), setY(2);break;
		case 7:setX(2), setY(0);break;
		case 8:setX(2), setY(1);break;
		case 9:setX(2), setY(2);break;
		case 10: break;
		default: cout << "No hay esa opcion" << endl;
		}
	}
	int revisar(string dato1) {
		int band = 0;
		if ((tablero1[0][0] == dato1) && (tablero1[1][1] == dato1) && (tablero1[2][2] == dato1) ||
			((tablero1[2][0] == dato1) && (tablero1[1][1] == dato1) && (tablero1[0][2] == dato1)) ||
			((tablero1[0][0] == dato1) && (tablero1[1][0] == dato1) && (tablero1[2][0] == dato1))||
			((tablero1[0][1] == dato1) && (tablero1[1][1] == dato1) && (tablero1[2][1] == dato1))||
			((tablero1[0][2] == dato1) && (tablero1[1][2] == dato1) && (tablero1[2][2] == dato1))||
			((tablero1[0][0] == dato1) && (tablero1[0][1] == dato1) && (tablero1[0][2] == dato1))||
			((tablero1[1][0] == dato1) && (tablero1[1][1] == dato1) && (tablero1[1][2] == dato1))||
			((tablero1[2][0] == dato1) && (tablero1[2][1] == dato1) && (tablero1[2][2] == dato1)))
		{
			band = 1;
		}
		else {
			band = 2;
		}
		return band;
	}
	int revisarMatrizLlena() {
		int b = 0;
		contador++;
		for (int i = 0;i < nfilas;i++) {
			for (int j = 0;j < ncolumanas;j++) {
				if (*(*(tablero1 + i) + j) == getDatoX() && (contador >= 12) || 
					*(*(tablero1 + i) + j) == getDAtoY() && (contador >= 12)) {
					b = 1;
				}
			}
		}
		return b;
	}

};