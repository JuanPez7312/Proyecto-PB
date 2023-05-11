/*
Autores: Juan Páez Camilo Galeano
Programa: Parqueadero}
Fecha: 2 de Julio del 2023
*/
//librerias
#include <iostream>
#include <vector>
#include <locale>
#include <iomanip>
#define DESC 0.1
//cobros por minuto en pesos
#define CAR 139 
#define MOT 97
#define BIC 10
using namespace std;
//Estructuras
struct cliente{
	char nombre[40];
	char apellidos[40];
	char id[40];
};
struct vehiculo{
	char matricula[6];
	char color[40];
	char marca[40];
	char modelo[40];
	int tipo; //(1)Automóviles, camperos, camionetas y vehículos pesados (2)Motocicletas (3)Bicicletas
};
//Prototipos
float calcularTiempo(char fechaingre[40], char fechasal[40],float horaingre, float horasal);
float calularTarifa(float tiempo,  int tipo);
void mostrarTarifas();
void run();
//main
int main(){
	setlocale(LC_ALL,"");
	run(); 
	return 0;
}
void run(){
	int consoleWidth=154, opc;
	cout << setw(consoleWidth) << setfill(' ');
	cout<<"______________________________________________________________________"<<endl;
	consoleWidth=154;
	cout << setw(consoleWidth) << setfill(' ');
	cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;

	consoleWidth =140;
	cout << setw(consoleWidth) << setfill(' ');
	cout<<"Bienvenido al parqueadero El Rayo Mcqueen\n";
	mostrarTarifas();
	do{
		consoleWidth =127;
		cout << setw(consoleWidth) << setfill(' ');
		cout<<"(1)Ingresar\t(2)Salir\n";
		consoleWidth =120;
		cout << setw(consoleWidth) << setfill(' ');
		cout<<"Opción: ";
		cin>>opc;
		if(opc<1 || opc>2){
			consoleWidth =126;
			cout << setw(consoleWidth) << setfill(' ');
			cout<<"Opción inválida\n";
		}
	}while(opc<1 || opc>2);
	
	
}
//Funcion que imprime las tarifas del parquiadero
void mostrarTarifas(){
	cout<<endl;
	int consoleWidth;
	consoleWidth=146;
	cout << setw(consoleWidth) << setfill(' ');
	cout<<"Las tarifas de nuestro parqueadero son las siguientes\n";
	consoleWidth=136;
	cout << setw(consoleWidth) << setfill(' ');
	cout<<"Automóviles, camperos, camionetas y vehículos pesados: "<<CAR<<" pesos por minuto"<<endl;
	consoleWidth=116;
	cout << setw(consoleWidth) << setfill(' ');
	cout<<"Motocicletas: "<<MOT<<" pesos por minuto"<<endl;
	consoleWidth=115;
	cout << setw(consoleWidth) << setfill(' ');
	cout<<"Bicicletas: "<<BIC<<" pesos por minuto"<<endl;
	
	consoleWidth=154;
	cout << setw(consoleWidth) << setfill(' ');
	cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
	consoleWidth=154;
	cout << setw(consoleWidth) << setfill(' ');
	cout<<"______________________________________________________________________"<<endl;
	} 





