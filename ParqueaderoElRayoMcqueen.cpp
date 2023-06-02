/*
Autores: Juan Páez Camilo Galeano
Programa: Parqueadero
Autores: Juan Páez Camilo Galeano
Programa: Parqueadero
Fecha: 2 de Julio del 2023
*/
//librerias
#include <iostream>
#include <vector>
#include <locale>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
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
	string nombrecompleto;
	string id;
	string matri;
} cli;
struct fecha{
	int year;
	int mes;
	int dia;
} fecha;
	int tipoid; //(1)Tarjeta identidad (2)Cedula de ciudadania (3)Otro
};
struct vehiculo{
	string matricula;
	string color;
	string marca;
	string modelo;
	int tipo; //(1)AutomÃ³viles, camperos, camionetas y vehÃ­culos pesados (2)Motocicletas (3)Bicicletas
};
//Prototipos
float calcularPago(float tiempo, int tipo, int visitas, float tiemposali);
void mosCen(string mens);
void mostrarTarifas();
void ingresarDatos();
float obtenerTiempo();
void salida();
int run(int opc);
int tamPantalla();
void pedCen(int n);
//main
int main(){
	setlocale(LC_ALL, "");
	//Comandos para que la consola siempre se muestre ampliada
	HWND consoleWindow = GetConsoleWindow();
	ShowWindow(consoleWindow, SW_MAXIMIZE);
	int opc=0, ja=0;
	//Ciclo para realizar más consultas
	while(ja!=3){
		system("cls");
		ja=run(opc);
	}
	int opc;
	//Ciclo para realizar mÃ¡s consultas
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
	mosCen("--------------------------------------------- Gracias por usar este programa ten bonita vida :) ---------------------------------------------\n");
	return 0;
}
//Funcion principal
int run(int opc){
	string input;
	mosCen("______________________________________________________________________\n");
	mosCen("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
	cout<<endl;
	mosCen("Bienvenido al parqueadero El Rayo Mcqueen\n");
	mosCen("Somos el parqueadero que parquea\n");
	cout<<endl;
	mostrarTarifas();
	mosCen("(1)Ingreso  (2)Salida  (3)Salir del Programa\n");
	mosCen("Opción: \n");
	//Ciclo que verifica el valor ingresado
	do{	
		pedCen(1);
		getline(cin, input);
		try{
			opc = stoi(input);
			if(opc<1 || opc>3){
				mosCen("Opción inválida\n");
			}
		}catch (const exception& e){
			mosCen( "La entrada no es válida. Debe ingresar un valor entero\n");
	do{
		mosCen("(1)Ingresar\t(2)Salir\n");
		mosCen("Opción: \n");
		pedCen(1);
		cin>>opc;
		if(opc<1 || opc>2){
			mosCen("Opción inválida\n");
		}
	}while(opc<1 || opc>3);
	system("cls");
	if(opc==1){
		ingresarDatos();
		return 1;
	}else if(opc==2){
		salida();
		return 2;
	}else{
		return 3;
	}	
}
//Funcion para saber el tiempo
float obtenerTiempo(){
	// Obtener la marca de tiempo actual	
    time_t currentTime = time(NULL);
    // Convertir la marca de tiempo en una estructura de tiempo local
    tm* localTime = localtime(&currentTime);
    // Obtener los componentes de fecha y hora
    fecha.year= localTime->tm_year+1900;
	fecha.mes=localTime->tm_mon;
	fecha.dia=localTime->tm_mday; 
    int ho = localTime->tm_hour;
    int mi = localTime->tm_min;
    float seg = localTime->tm_sec;
    float tiempo = (ho*60)+mi;
    tiempo+=(seg/60);
  	return tiempo;
}
//Funcion de salida
void salida(){
	ifstream archivo("datos.txt");
	vector<string> datoslinea;
	string linea;
	int visitas=0;
	cout<<endl;
	mosCen("--------------------------------------------- Salida ---------------------------------------------\n");
	cout<<endl;
	mosCen("Ingrese por favor su número de identificación (sin espacios ni puntos)\n");
	cout<<endl;
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
	mosCen("Ingrese su nÃºmero de identificación (sin espacios ni puntos): \n");
	cin.ignore();
	pedCen(10);
	cin>>cli.id;
	cout<<endl;
	system("cls");
	while(getline(archivo, linea)){
		if(linea.find(cli.id) != std::string::npos){
			visitas+=1;
			istringstream iss(linea);
	        string dato;
			while (iss >> dato) {
	            datoslinea.push_back(dato);
	        }
	    }
	}
	string nombre=datoslinea[0]+" "+datoslinea[1];
	string matricula=datoslinea[4];
	float tiempo=stof(datoslinea[5]);
	int tipo=stoi(datoslinea[3]);
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"Factura de Pago ----------------------------------\n";
	cout<<endl;
	cout<<"Fecha:     "<<fecha.year<<" / "<<fecha.mes<<" / "<<fecha.dia<<endl;
	cout<<endl;
	cout<<"Cliente:   "<<nombre<<endl;
	cout<<endl;
	cout<<"Matricula: "<<matricula<<endl;
	cout<<endl;
	float pres=calcularPago(tiempo, tipo, visitas,0);
	cout<<endl;
	cout<<"Total a Pagar ---------------------------- "<<fixed<<setprecision(2)<<pres<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"Ser vivo "<<nombre<<" espero que tenga un día maravilloso\n";
	cout<<endl;
	system("pause");
}
//Funcion que pide los datos del cliente
float calcularPago(float tiempo, int tipo, int visitas, float tiemposali){
	float pago, totaltiem;
	if(tiemposali==0){
		tiemposali=obtenerTiempo();
	}
	totaltiem=tiemposali-tiempo;
	switch(tipo){
		case 1:
			pago=totaltiem*CAR;
			break;
		case 2:
			pago=totaltiem*MOT;
			break;
		case 3:
			pago=totaltiem*BIC;
			break;
		default:
			cout<<"No se puede llegar aca, pero si si, felicitaciones, lo rompiste\n";
	}
	if(visitas>=2){
		float des=pago*DESC;
		cout<<"Descuento: "<<des<<endl;
		return (pago-des);
	}else{
		cout<<"Descuento: 0"<<endl;
		return pago;
	}
}
void ingresarDatos(){
	string input;
	cout<<endl;
	mosCen("--------------------------------------------- Ingreso ---------------------------------------------\n");
	int tipoid, tipoveh;
	ofstream archivo("datos.txt", std::ios::app);
	string marca,color,modelo;
	cout<<endl;
	mosCen("----------------- Datos personales -----------------\n");
	cout<<endl;
	mosCen("Ingrese su nombre completlo: \n");
	cout<<endl;
	pedCen(6);
	getline(cin, cli.nombrecompleto);
	cout<<endl;
	archivo<<cli.nombrecompleto<<" ";
	mosCen("Ingrese su tipo de identificación: \n");
	cout<<endl;
	mosCen("(1)T.I.  (2)C.C.  (3)Otro\n");
	cout<<endl;
	mosCen("Opción: \n");
	//Ciclo que verifica el valor ingresado
	cout<<endl;
	do{
		pedCen(1);
		getline(cin, input);
		try{
			tipoid = stoi(input);
			if(tipoid<1 || tipoid>3){
				mosCen("Opción inválida\n");
			}
		}catch (const exception& e){
			mosCen( "La entrada no es válida. Debe ingresar un valor entero\n");
		}
	}while(tipoid<1 || tipoid>3);
	cout<<endl;
	mosCen("Ingrese su número de identificación (sin espacios ni puntos): \n");
	cout<<endl;
	pedCen(10);
	cin>>cli.id;
	cout<<endl;
	archivo<<cli.id<<" ";	
	system("cls");
	mosCen("----------------- Datos del vehiculo -----------------\n");
	cout<<endl;
	mosCen("Ingrese el tipo de vehiculo que ingresa\n");
	cout<<endl;
	mosCen("(1)Automóvil, campero, camioneta y vehículo pesado\n");
	cout<<endl;
	mosCen("(2)Motocicleta\n");
	cout<<endl;
	mosCen("(3)Bicicleta\n");
	cout<<endl;
	cin.ignore();
	do{
		pedCen(1);
		getline(cin, input);
		try{
			tipoveh = stoi(input);
			if(tipoveh<1 || tipoveh>3){
				mosCen("Opción inválida\n");
			}
		}catch (const exception& e){
			mosCen( "La entrada no es válida. Debe ingresar un valor entero\n");
		}
	}while(tipoveh<1||tipoveh>3);
	cout<<endl;
	archivo<<tipoveh<<" ";
	mosCen("Ingrese la matricula de su vehiculo (en caso de bicicleta el número de la Tarjeta de Propiedad)\n");
	cout<<endl;
	mosCen("Ingrese la matricula de su vehiculo (en caso de bicicleta el nÃºmero de la Tarjeta de Propiedad)\n");
	pedCen(6);
	cin.ignore();
	getline(cin,cli.matri);
	cout<<endl;
	archivo<<cli.matri<<" ";
	mosCen("Ingrese la marca de su vehiculo\n");
	cout<<endl;
	pedCen(10);
	cin.ignore();
	getline(cin,marca);
	cout<<endl;
	mosCen("Ingrese el color de su vehiculo\n");
	cout<<endl;
	pedCen(10);
	cin.ignore();
	getline(cin,color);
	cout<<endl;
	mosCen("Ingrese el modelo de su vehiculo\n");
	cout<<endl;
	pedCen(10);
	cin.ignore();
	getline(cin, modelo);
	cout<<endl;
	float entrada = obtenerTiempo();
	archivo<<entrada<<endl;
	archivo.close();
	mosCen("Desea dejar su vehiculo por más de 12 horas en nuestro gran parqueadero\n");
	cout<<endl;
	mosCen("(1)Si \t(2)No\n");
	int opc7;
	cout<<endl;
	do{
		pedCen(1);
		getline(cin, input);
		try{
			opc7 = stoi(input);
			if(opc7<1 || opc7>2){
				mosCen("Opción inválida\n");
			}
		}catch (const exception& e){
			mosCen( "La entrada no es válida. Debe ingresar un valor entero\n");
		}
	}while(opc7<1 || opc7>2);
	if(opc7==1){
		float pago1,pago2;
		mosCen("Ingrese la hora en que recogera el vehiculo (hh:mm)\n");
		cout<<endl;
		string horareco;
		pedCen(5);
		cin>>horareco;
		cout<<endl;
	    char separador = ':';	
	    size_t pos = 0;
	    string hora;
	    while ((pos = horareco.find(separador)) != std::string::npos) {
	        hora = horareco.substr(0, pos);
	        horareco.erase(0, pos + 1);
	    }
		int horaint = stoi(hora);
		int minutos = stoi(horareco);
		float minureco=horaint*60+minutos;
		float minuactual=obtenerTiempo();
		ifstream archivo("datos.txt");
		vector<string> datoslinea;
		string linea;
		int visitas=0;
		system("cls");
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"Factura de Pago ----------------------------------\n";
		cout<<endl;
		cout<<"Fecha:     "<<fecha.year<<" / "<<fecha.mes<<" / "<<fecha.dia<<endl;
		cout<<endl;
		cout<<"Cliente:   "<<cli.nombrecompleto<<endl;
		cout<<endl;
		cout<<"Matricula: "<<cli.matri<<endl;
		cout<<endl;
		while(getline(archivo, linea)){
			if(linea.find(cli.id) != std::string::npos){
				visitas+=1;
				istringstream iss(linea);
		        string dato;
				while (iss >> dato) {
		            datoslinea.push_back(dato);
		        }
		    }
		}
		if(minureco<minuactual){
			pago1= calcularPago(minuactual, tipoveh, 0, 1440);
			pago2= calcularPago(0, tipoveh, 0, minureco);
			pago1+=pago2;
		}else{
			pago1=calcularPago(minuactual, tipoveh,0,minureco);
		}
		if(visitas>=2){
			pago1=pago1-(pago1*DESC);
			cout<<"Descuento: "<<pago1*DESC<<endl;
		}else{
			cout<<"Descuento: 0"<<endl;
		}
		cout<<endl;
		cout<<"Total a Pagar ---------------------------- "<<fixed<<setprecision(2)<<pago1<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"Ser vivo "<<cli.nombrecompleto<<" espero que tenga un día maravilloso\n";
		cout<<endl;
		system("pause");
	}else{
		return;
	}
}
//Funcion que imprime las tarifas del parqueadero
void mostrarTarifas(){
	ostringstream ss;
	ostringstream ss1;
	ostringstream ss2;
	int car=CAR,mot=MOT,bic=BIC;
	string m1=" pesos por minuto\n";
	mosCen("Las tarifas de nuestro parqueadero son las siguientes\n");
	ss << car;
	string pres = ss.str();
	string men="AutomÃ³viles, camperos, camionetas y vehÃ­culos pesados: ";
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
//Funcion que calcula el tamaño de la pantalla
//Funcion que genera una clave aleatoria
string generarClaveAleatoria(){
	int longitud=5;
    string caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string clave;
    // Inicializar la semilla del generador de nÃºmeros aleatorios
    srand(std::time(0));
    for (int i = 0; i < longitud; ++i) {
        int indice = rand() % caracteres.length();
        clave += caracteres[indice];
    }
    return clave;
}
//Funcion que calcula el tamaÃ±o de la pantalla
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
