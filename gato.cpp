using namespace std;
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {

    int jugadas = 1, jugador = 1, fila = 0, col = 0, ganador = 0;
    char gato[3][3];
    char resp1, resp2, resp3, resp4;
    bool salir;


    int imprimir() {
        system("cls");
        cout << endl;
        cout << "\t    0    1    2" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "\t" << i << " ";
            for (int j = 0; j < 3; j++) {
                cout << "[ " << gato[i][j] << " ]";
            }
            cout << endl;
        }
        cout << endl;
    }

    int main() {
        system("color c");
        cout << endl;
        Sleep(200);
        cout << "\t\t<< El juego del Gato >>" << endl;
        Sleep(200);
        cout << "\t\t   -----------------" << endl;
        Sleep(1000);
        cout << "    Instrucciones:" << endl;
        Sleep(200);
        cout << "    [1] Solo pueden jugar dos personas." << endl;
        Sleep(200);
        cout << "    [2] El jugador 1 ocupa el caracter: x ." << endl;
        Sleep(200);
        cout << "    [3] El jugador 2 ocupa el caracter: o ." << endl;
        Sleep(200);
        cout << "    [4] El turno se alterna entre ambos jugadores." << endl;
        Sleep(200);
        cout << "    [5] El jugador en turno escribe la cordenada de su proximo tiro." << endl;
        Sleep(200);
        cout << "    [6] Gana el jugador que genere primero una linea de 3." << endl << endl;
        Sleep(1000);
        cout << endl; cout << endl;
        cout << "    Desea jugar? [y/n]:\t";
        cin >> resp1;

        if (resp1 == 'y') {
            system("cls");

            do {
                imprimir();
                do {
                    if (jugadas % 2 == 1) {
                        cout << endl;
                        cout << "Es el turno del jugador " << jugador << endl;
                        do {
                            cout << "Indique la fila: "; cin >> fila;
                            //fila-=1;
                            cout << "Indique la columna: "; cin >> col;
                            //col-=1;
                            if (fila > 2 || col > 2 || fila < 0 || col < 0) {
                                cout << "Coordenadas incorrectas, intente otra vez." << endl;
                            }
                            if (gato[fila][col] == 'x' || gato[fila][col] == 'o') {
                                cout << "Coordenada ya usada, intente otra vez." << endl;
                            }
                        } while (fila > 2 || col > 2 || fila < 0 || col < 0 || gato[fila][col] == 'x' || gato[fila][col] == 'o');
                        gato[fila][col] = 'x';
                        imprimir();
                        if ((gato[0][0] == 'x') && (gato[0][0] == gato[0][1]) && (gato[0][0] == gato[0][2]) ||
                            (gato[1][0] == 'x') && (gato[1][0] == gato[1][1]) && (gato[1][0] == gato[1][2]) ||
                            (gato[2][0] == 'x') && (gato[2][0] == gato[2][1]) && (gato[2][0] == gato[2][2]) ||

                            (gato[0][0] == 'x') && (gato[0][0] == gato[1][1]) && (gato[0][0] == gato[2][2]) ||
                            (gato[0][2] == 'x') && (gato[0][2] == gato[1][1]) && (gato[0][2] == gato[2][0]) ||

                            (gato[0][0] == 'x') && (gato[0][0] == gato[1][0]) && (gato[0][0] == gato[2][0]) ||
                            (gato[0][1] == 'x') && (gato[0][1] == gato[1][1]) && (gato[0][1] == gato[2][1]) ||
                            (gato[0][2] == 'x') && (gato[0][2] == gato[1][2]) && (gato[0][2] == gato[2][2])
                            ) {
                            cout << endl;
                            cout << "Felicidades! Gana el jugador 1" << endl;
                            ganador = 1;
                        }
                        jugador = 2;
                    }

                    if (jugadas % 2 == 0) {
                        cout << endl;
                        cout << "Es el turno del jugador " << jugador << endl;
                        do {
                            cout << "Indique la fila: "; cin >> fila;
                            //fila-=1;
                            cout << "Indique la columna: "; cin >> col;
                            //col-=1;
                            if (fila >= 3 || col >= 3 || fila < 0 || col < 0) {
                                cout << "Coordenadas incorrectas, intente otra vez." << endl;
                            }
                            if (gato[fila][col] == 'x' || gato[fila][col] == 'o') {
                                cout << "Coordenada ya usada, intente otra vez." << endl;
                            }
                        } while (fila >= 3 || col >= 3 || fila < 0 || col < 0 || gato[fila][col] == 'x' || gato[fila][col] == 'o');
                        gato[fila][col] = 'o';
                        imprimir();
                        if ((gato[0][0] == 'o') && (gato[0][0] == gato[0][1]) && (gato[0][0] == gato[0][2]) ||
                            (gato[1][0] == 'o') && (gato[1][0] == gato[1][1]) && (gato[1][0] == gato[1][2]) ||
                            (gato[2][0] == 'o') && (gato[2][0] == gato[2][1]) && (gato[2][0] == gato[2][2]) ||

                            (gato[0][0] == 'o') && (gato[0][0] == gato[1][1]) && (gato[0][0] == gato[2][2]) ||
                            (gato[0][2] == 'o') && (gato[0][2] == gato[1][1]) && (gato[0][2] == gato[2][0]) ||

                            (gato[0][0] == 'o') && (gato[0][0] == gato[1][0]) && (gato[0][0] == gato[2][0]) ||
                            (gato[0][1] == 'o') && (gato[0][1] == gato[1][1]) && (gato[0][1] == gato[2][1]) ||
                            (gato[0][2] == 'o') && (gato[0][2] == gato[1][2]) && (gato[0][2] == gato[2][2])) {
                            cout << endl;
                            cout << "Felicidades! Gana el jugador 2" << endl;
                            ganador = 1;
                        }
                        jugador = 1;
                    }

                    if (ganador == 1) {
                        jugadas = 10;
                    }
                    jugadas++;
                } while (jugadas < 10);

                if (jugadas < 100 && ganador != 1) {
                    cout << "Es un empate, ningun jugador gana." << endl;
                }

                cout << endl << "Desea jugar otra vez? [y/n]:\t";
                cin >> resp4;
                if (resp4 == 'n') {
                    system("cls");
                    cout << endl;
                    cout << "\tGracias por jugar!" << endl;
                    salir = false;
                }
                else {
                    salir = true;
                    jugadas = 1;
                    jugador = 1;
                    ganador = 0;
                    system("cls");
                    cout << "\t<< Tablero >>" << endl;
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            gato[i][j] = ' ';
                        }
                    }
                    imprimir();
                }
            } while (salir == true);
        }
        else {
            cout << "\n\tPues que aburrido alv :v" << endl;
        }

        getch();
        return 0;
    }
};