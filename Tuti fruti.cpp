/*UTN
TP Nº:
Autor: Mariano Alejandro Visgarra
Ejercicio:
*/

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <string.h>
#include <iomanip>
using namespace std;

void CargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

void gotoxy(int x, int y){
    HANDLE manipulador;
    COORD coordenadas;
    manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
    coordenadas.X = x;
    coordenadas.Y = y;
    SetConsoleCursorPosition(manipulador, coordenadas);
}

string getPresentDateTime()
{
    time_t tt;
    struct tm *st;
    time(&tt);
    st = localtime(&tt);
    return asctime(st);
}

void completar(char pal[30]){
    gotoxy(21,4); CargarCadena(pal, 29);
}

void gameOn(int &seconds){ //hacer gotoxy y borrar el "setear tiempo"
    int tamPalabra;
    tamPalabra = getPresentDateTime().size();
    while(seconds>= 1){
        Sleep(1000);
        gotoxy(0,15);
        cout<<"Tiempo restante: "<<seconds << " segundos..." <<endl;
        seconds--;
        gotoxy(120-tamPalabra,15);
        cout << getPresentDateTime();
    }
}

void cargarCategorias (char cat1[30], char cat2[30], char cat3[30], char cat4[30], char cat5[30]){ //PARA HACER CICLO NECESITA MATRIZ... PERO CON CHAR ESTA DIFICIL O NO ACEPTA EL ISO
    cout << "Antes de jugar, ingresa las categorias que quieras completar a continuacion (maximo 5)" << endl;
    cout << "Ingrese categoria " << "1: " << endl;
    CargarCadena(cat1,29);
    cout << "Ingrese categoria " << "2: " << endl;
    CargarCadena(cat2,29);
    cout << "Ingrese categoria " << "3: " << endl;
    CargarCadena(cat3,29);
    cout << "Ingrese categoria " << "4: " << endl;
    CargarCadena(cat4,29);
    cout << "Ingrese categoria " << "5: " << endl;
    CargarCadena(cat5,29);
}

void tablaCategorias(char cat1[30], char cat2[30], char cat3[30], char cat4[30], char cat5[30]) { //realizar array de strings con distintas categorias
    system("cls");
    gotoxy(0,1); cout << "========================================================================================================================" << endl;
    cout << setw(20) << left << cat1;
    for(int i=2;i<14;i++){
        gotoxy(20,i); cout << "|";
    }
    gotoxy(21,2); cout << setw(20) << cat2;
    for(int i=2;i<14;i++){
        gotoxy(40,i); cout << "|";
    }
    gotoxy(41,2); cout << setw(20) << cat3;
    for(int i=2;i<14;i++){
        gotoxy(60,i); cout << "|";
    }
    gotoxy(61,2); cout << setw(20) << cat4;
    for(int i=2;i<14;i++){
        gotoxy(80,i); cout << "|";
    }
    gotoxy(81,2); cout << setw(20) << cat5;
    for(int i=2;i<14;i++){
        gotoxy(100,i); cout << "|";
    }
    gotoxy(101,2); cout << setw(15) << right << "Letra y puntos" << endl;
}


char generarLetra(){
    char letra;
    gotoxy(45,0); cout << "Generando letra al azar: ";
    letra = rand()%26+65;
    Sleep(2500);
    return letra;
}

void menuPrincipal(){
    cout << "============MENU================" <<endl;
    cout << "1. JUGAR" <<endl;
    cout << "2. SUBMENU 1" << endl;
    cout << "3. SUBMENU 2" << endl;
    cout << "0. SALIR" << endl;
    cout << "================================" << endl;
    cout << "Ingrese una opcion: " << endl;
}

int main () {
    int opc;
    int seconds;
    char cat1[30], cat2[30], cat3[30], cat4[30], cat5[30];

    while(true){
        menuPrincipal();
        cin >> opc;
        switch(opc){
        case 1:
            system("cls");
            cargarCategorias(cat1, cat2, cat3, cat4, cat5);
            cout << "Setear tiempo de juego en segundos: ";
            cin >> seconds;
            system("cls");
            tablaCategorias(cat1, cat2, cat3, cat4, cat5);
            cout << generarLetra() << endl;
            gameOn(seconds);   //Ciclo que hace cuenta regresiva y marca el tiempo presente
            system("pause");
            break;
        case 2:
            system("cls");
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "opc1" <<endl;
            break;
        case 0:
            return 0;
        }
    }

	return 0;
}
