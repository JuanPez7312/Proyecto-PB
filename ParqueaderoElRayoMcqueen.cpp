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
#include <string>
#include <random>
#include <sstream>
#include <windows.h>
#include <ctime>
#define DESC 0.1
//cobros por minuto en pesos
#define CAR 139 
#define MOT 97
#define BIC 10
#define TC tamPantalla()
using namespace std;
//Estructuras
struct cliente{
	string nombre;
	string apellidos;
	string id;
	int tipoid; //(1)Tarjeta identidad (2)Cedula de ciudadania (3)Otro
};
struct vehiculo{
	string matricula;
	string color;
	string marca;
	string modelo;
	int tipo; //(1)Automóviles, camperos, camionetas y vehículos pesados (2)Motocicletas (3)Bicicletas
};
//Prototipos
float calcularTiempo(float horaingre, float horasal, int dias);
float calularTarifa(float tiempo,  int tipo);
void obtenerTiempo(int mostrar);
void mosCen(string mens);
void mostrarTarifas();
void ingresarDatos();
string generarClaveAleatoria();
void run();
int tamPantalla();
void pedCen(int n);
//main
int main(){
	setlocale(LC_ALL, "");
	//Comandos para que la consola siempre se muestre ampliada
	HWND consoleWindow = GetConsoleWindow();
	ShowWindow(consoleWindow, SW_MAXIMIZE);
	int opc;
	//Ciclo para realizar más consultas
	do{
		system("cls");
		run();
		//Ciclo que verifica el valor ingresado
		do{
			system("cls");
			mosCen("(1)Nuevo\t(2)Cerrar\n");
			mosCen("Opción: \n");
			pedCen(1);
			cin>>opc;
			if(opc<1 ||opc>2){
				mosCen("Entrada inválida reintentelo ");
				system("pause");
			}
		}while(opc<1 ||opc>2);
	}while(opc==1);
	system("cls");
	mosCen("Gracias por usar este programa ten bonita vida :) \n");
	return 0;
}
//Funcion principal
void run(){
	int opc;
	mosCen("______________________________________________________________________\n");
	mosCen("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
	mosCen("Bienvenido al parqueadero El Rayo Mcqueen\n");
	mostrarTarifas();
	//Ciclo que verifica el valor ingresado
	do{
		mosCen("(1)Ingresar\t(2)Salir\n");
		mosCen("Opción: \n");
		pedCen(1);
		cin>>opc;
		if(opc<1 || opc>2){
			mosCen("Opción inválida\n");
		}
	}while(opc<1 || opc>2);
	system("cls");
	if(opc==1){
		ingresarDatos();
		mosCen("Su clave es: ");
		string cla=generarClaveAleatoria();
		mosCen(cla);
		system("pause");
	}	
}
//Funcion que recibe un entero si es 1 muestra la hora, si no calcula la hora con una pasada
void obtenerTiempo(int mostrar){
// Obtener la marca de tiempo actual
    time_t currentTime = time(NULL);
    // Convertir la marca de tiempo en una estructura de tiempo local
    tm* localTime = localtime(&currentTime);
    // Obtener los componentes de fecha y hora
    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;
    int hour = localTime->tm_hour;
    int minute = localTime->tm_min;
    if(mostrar==1){
    	cout << "Fecha y hora de ingreso: " << year << "-" << month << "-" << day << " " << hour << ":" << minute <<endl;
	}
	//Aca iria algo para poder tener un modulo para poder guardar los datos en un archivo
	//Que se vaya escribiendo hasta que se cierre el programa, para poder hacer reviciones del mismo despues
}
//Funcion que pide los datos del cliente
void ingresarDatos(){
	cliente cli;
	vehiculo vehiculo;
	mosCen("----------------- Datos personales -----------------\n");
	mosCen("Ingrese su(s) nombre(s): \n");
	pedCen(6);
	cin.ignore();
	getline(cin, cli.nombre);
	mosCen("Ingrese su(s) apellido(s): \n");
	pedCen(9);
	cin.ignore();
	getline(cin, cli.apellidos);
	mosCen("Ingrese su tipo de identificación: \n");
	mosCen("(1)T.I.  (2)C.C.  (3)Otro\n");
	mosCen("Opción: \n");
	//Ciclo que verifica el valor ingresado
	do{
		pedCen(1);
		cin>>cli.tipoid;
		if(cli.tipoid<1 || cli.tipoid>3){
			mosCen("Entrada inválida, reintentelo\n");
		}
	}while(cli.tipoid<1 || cli.tipoid>3);
	mosCen("Ingrese su número de identificación (sin espacios ni puntos): \n");
	cin.ignore();
	pedCen(10);
	cin>>cli.id;
	system("cls");
	mosCen("----------------- Datos del vehiculo -----------------\n");
	mosCen("Ingrese la matricula de su vehiculo (en caso de bicicleta el número de la Tarjeta de Propiedad)\n");
	pedCen(6);
	cin.ignore();
	getline(cin, vehiculo.matricula);
	mosCen("Ingrese la marca de su vehiculo\n");
	pedCen(10);
	cin.ignore();
	getline(cin, vehiculo.marca);
	mosCen("Ingrese el color de su vehiculo\n");
	pedCen(10);
	getline(cin, vehiculo.color);
	mosCen("Ingrese el modelo de su vehiculo\n");
	pedCen(10);
	getline(cin, vehiculo.modelo);
	obtenerTiempo(1);
	//Aca iria algo para poder tener un modulo para poder guardar los datos en un archivo
	//Que se vaya escribiendo hasta que se cierre el programa, para poder hacer reviciones del mismo despues
	//Pero todavia no sabemos de eso entonces dejo un system pause :)
	system("pause");
}
//Funcion que imprime las tarifas del parqueadero
void mostrarTarifas(){
	cout<<endl;
	ostringstream ss;
	ostringstream ss1;
	ostringstream ss2;
	int car=CAR,mot=MOT,bic=BIC;
	string m1=" pesos por minuto\n";
	mosCen("Las tarifas de nuestro parqueadero son las siguientes\n");
	ss << car;
	string pres = ss.str();
	string men="Automóviles, camperos, camionetas y vehículos pesados: ";
	string resul=men+pres+m1;
	mosCen(resul);
	ss1 << mot;
	string pres1 = ss1.str();
	string men1="Motocicletas: ";
	string resul1=men1+pres1+m1;
	mosCen(resul1);
	ss2 << bic;
	string pres2= ss2.str();
	string men2="Bicicletas: ";
	string resul2=men2+pres2+m1;
	mosCen(resul2);
	mosCen("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
	mosCen("______________________________________________________________________\n");
}
//Funcion que genera una clave aleatoria
string generarClaveAleatoria(){
	int longitud=5;
    string caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string clave;
    // Inicializar la semilla del generador de números aleatorios
    srand(std::time(0));
    for (int i = 0; i < longitud; ++i) {
        int indice = rand() % caracteres.length();
        clave += caracteres[indice];
    }
    return clave;
}
//Funcion que calcula el tamaño de la pantalla
int tamPantalla(){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
} 
//Funcion que pide los datos en un espacio centrado
void pedCen(int n){
    int espa =(TC/2)-n;
    cout<<setw(espa)<<"";
}
//Funcion que imprime un texto centrado
void mosCen(string mens){
	int tamTex=mens.size();
    int espa = (TC - tamTex) / 2;
    cout<<setw(espa)<<""<<mens;
}

//Me gusta su mamá






