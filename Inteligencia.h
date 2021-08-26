#include"Cuerpo.h"

class Inteligencia : public Cuerpo{
private:
	int n;
public:
	Inteligencia(string** tablero, int nfilas, int ncolumnas, string dato1, string dato2, int jugador1, int jugador2, int n1) : Cuerpo(tablero,nfilas,ncolumnas,dato1, dato2,jugador1,jugador2){
		this->n = n1;
	}


};