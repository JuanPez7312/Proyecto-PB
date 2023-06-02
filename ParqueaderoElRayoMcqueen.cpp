/*
Autores: Juan Páez y Camilo Galeano
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
#include <conio.h>
#include <cstdlib>
#include <chrono>
#include <thread>
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
//Prototipos
float calcularPago(float tiempo, int tipo, int visitas, float tiemposali);
void mosCen(string mens);
void mostrarTarifas();
void ingresarDatos();
float obtenerTiempo();
void cargando();
void salida();
int run(int opc);
int tamPantalla();
void pedCen(int n);
void screamer();
//main
int main(){
	system("title Raio Mcqueen");
	setlocale(LC_ALL, "");
	//Comandos para que la consola siempre se muestre ampliada
	HWND consoleWindow = GetConsoleWindow();
	ShowWindow(consoleWindow, SW_MAXIMIZE);
	int opc=0, ja=0;
	//Ciclo para realizar más consultas
	while(ja!=3){
		system("cls");
		screamer();
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    // Establecer el color de fondo
	    CONSOLE_SCREEN_BUFFER_INFOEX info;
	    info.cbSize = sizeof(info);
	    GetConsoleScreenBufferInfoEx(hConsole, &info);
	    info.ColorTable[0] = RGB(99,71, 133);  // Color de fondo
	    SetConsoleScreenBufferInfoEx(hConsole, &info);
		system("cls");
		cin.ignore();
		ja=run(opc);
	}
	screamer();
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
	cout << R"(
         ___                                         ___                    ___                    ___                    ___                    ___                                         ___                    ___     
        /\  \                   ___                 /\  \                  /\__\                  /\__\                  /\  \                  /\__\                   ___                 /\  \                  /\  \    
       /::\  \                 /\  \               /::\  \                /::|  |                /:/  /                 /::\  \                /::|  |                 /\  \               /::\  \                /::\  \   
      /:/\:\  \                \:\  \             /:/\:\  \              /:|:|  |               /:/  /                 /:/\:\  \              /:|:|  |                 \:\  \             /:/\:\  \              /:/\:\  \  
     /::\~\:\__\               /::\__\           /::\~\:\  \            /:/|:|  |__            /:/__/  ___            /::\~\:\  \            /:/|:|  |__               /::\__\           /:/  \:\__\            /:/  \:\  \ 
    /:/\:\ \:|__|           __/:/\/__/          /:/\:\ \:\__\          /:/ |:| /\__\           |:|  | /\__\          /:/\:\ \:\__\          /:/ |:| /\__\           __/:/\/__/          /:/__/ \:|__|          /:/__/ \:\__\
    \:\~\:\/:/  /          /\/:/  /             \:\~\:\ \/__/          \/__|:|/:/  /           |:|  |/:/  /          \:\~\:\ \/__/          \/__|:|/:/  /          /\/:/  /             \:\  \ /:/  /          \:\  \ /:/  /
     \:\ \::/  /           \::/__/               \:\ \:\__\                |:/:/  /            |:|__/:/  /            \:\ \:\__\                |:/:/  /           \::/__/               \:\  /:/  /            \:\  /:/  / 
      \:\/:/  /             \:\__\                \:\ \/__/                |::/  /              \::::/__/              \:\ \/__/                |::/  /             \:\__\                \:\/:/  /              \:\/:/  /  
       \::/__/               \/__/                 \:\__\                  /:/  /                ~~~~                   \:\__\                  /:/  /               \/__/                 \::/__/                \::/  /   
        ~~                                          \/__/                  \/__/                                         \/__/                  \/__/                                       ~~                     \/__/    
	 )" << '\n';
	mosCen("Bienvenido al parqueadero El Rayo Mcqueen\n");
	mosCen("Somos el parqueadero que parquea\n");
	cout<<endl;
	mostrarTarifas();
	//Dibujo :DDDD
    mosCen("                                              _____________                    \n");
	mosCen("                                  ..---:::::::-----------. ::::;;.            \n");
	mosCen("                               .'''''''                  ;;   \\  ':.         \n");
	mosCen("                            .''                          ;     \\   '\\__.    \n");
	mosCen("                          .'                            ;;      ;   \\\\';    \n");
	mosCen("                        .'                              ;   _____;   \\\\\\/  \n");
	mosCen("                      .'                               :; ;'     \\ ___:'.    \n");
	mosCen("                    .'--...........................    : =   ____:'    \\\\   \n");
	mosCen("               ..-''                               ''''  o'''     ;     ; :   \n");
	mosCen("          .--''  .----- ..----...    _.-    --.  ..-'     ;       ;     ; ;   \n");
	mosCen("       .''_-     '--''-----'''    _-'        .-''         ;        ;    .-.   \n");
	mosCen("    .'  .'                      .'         .'              ;       ;   /. |   \n");
	mosCen("   /-./'                      .'          /           _..  ;       ;   ;;;|   \n");
	mosCen("  :  ;-.______               /       _________==.    /_  \\ ;       ;   ;;;;  \n");
	mosCen("  ;  / |      '''''''''''.---.'''''''          :    /' '. |;       ; _; ;;;   \n");
	mosCen(" /'-/  |                /   /                  /   /     ;|;      ;-' | ;';   \n");
	mosCen(":-  :   '''----______  /   /              ____.   .  .''. ;;   .-'..T'   .    \n");
	mosCen(" '. '  ___            '':   '''''''''''''''    .   ; ;    ;; ;.' .'   '--'    \n");
	mosCen("  ',   __ '''  ''---... :- - - - - - - - - ' '  ; ;  ;    ;;'  .'             \n");
	mosCen(" /. ;  '''---___                             ;  ; ;     ;|.''                 \n");
	mosCen(" :  ':           '''----.    .-------.       ;   ; ;     ;:                   \n");
	mosCen("  \\  '--__               \\   \\        \\     /    | ;     ;;               \n");
	mosCen("   '-..   ''''---___      :   .______..\\ __/..-''|  ;   ; ;                  \n");
	mosCen("       ''--..       '''--'        * * *         .   '. . ;                    \n");
	mosCen("             ''------...                  ..--''      ' :                     \n");
	mosCen("                        ''''''''''''''''''    \\        /                     \n");
	mosCen("                                               '------'                       \n");
	mosCen("(1)Ingreso Vehículo\n");
	cout<<endl;
	mosCen("(2)Salida vehículo\n");
	cout<<endl;
	mosCen("(3)Salir del Programa\n");
	//Ciclo que verifica el valor ingresado
	do{	
		cout<<endl;
		mosCen("Opción: ");
		getline(cin, input);
		try{
			opc = stoi(input);
			if(opc<1 || opc>3){
				mosCen("Opción inválida\n");
			}
		}catch (const exception& e){
			mosCen( "La entrada no es válida. Debe ingresar un valor entero\n");
		}
	}while(opc<1 || opc>3);
	system("cls");
	if(opc==1){
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	CONSOLE_SCREEN_BUFFER_INFOEX info;
	    info.cbSize = sizeof(info);
	    GetConsoleScreenBufferInfoEx(hConsole, &info);
    	info.ColorTable[0] = RGB(52,22, 78);  // Color de fondo
		SetConsoleScreenBufferInfoEx(hConsole, &info);
		system("cls"); //Screamer jajajaj que divertido es esto
		cargando();
		system("cls");
		ingresarDatos();
		return 1;
	}else if(opc==2){
		salida();
		return 2;
	}else{
		cargando();
		system("cls");
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
	cargando();
	system("cls");
	vector<string> datoslinea;
	string linea;
	int visitas=0;
	cout<<endl;
	mosCen("--------------------------------------------- Salida ---------------------------------------------\n");
	cout<<endl;
	mosCen("Ingrese por favor su número de identificación (sin espacios ni puntos)\n");
	pedCen(10);
	cin>>cli.id;
	cargando();
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
//Funcion que calcula el pago del cliente
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
		if(tiemposali==0){
			cout<<"Descuento: 0"<<endl;
		}
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
	cargando();
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
	cargando();
	system("cls");
	if(opc7==1){
		cout<<endl;
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
	    ifstream archivo("datos.txt");
		int horaint = stoi(hora);
		int minutos = stoi(horareco);
		float minureco=horaint*60+minutos;
		float minuactual=obtenerTiempo();
		vector<string> datoslinea;
		string linea;
		int visitas=0;
		cargando();
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
		archivo.close();
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
void cargando() {
    vector<string> lineasTexto = {
        "                                                                                                                        .------.                 ",
        "                                                                                                                       :|||'''`.`.               ",
        "                                                                                                                       :|||     7.`.             ",
        "                                                                                                    .===+===+===+===+===||`----L7'-`7`---.._     ",
        "                                                                                                    []                  || ==       |       '''-.",
        "                                                                                                    []...._____.........||........../ _____ ____|",
        "                                                                                             ***   *\____/,---.\_       ||_________/ /,---.\_  _/",
        "                                                                                               **    /_,-/ ,-. \ `._____|__________||/ ,-. \ \_[ ",
        "                                                                                                        /\ `-' /                    /\ `-' /     ",
        "                                                                                                          `---'                       `---'      "
    };
    string textoEstatico = "[C A R G A N D O]";
    int espacios = 0;
    int totalEspacios = 20;
    int caracteresImpresos = 0;
    const int limiteCaracteres = 20;
    do {
        system("cls");
        for (const string& linea : lineasTexto) {
            for (int i = 0; i < espacios; i++) {
                cout << " ";
            }
            cout << linea << endl;
        }
        mosCen(textoEstatico);
        espacios++;
        if (espacios > totalEspacios || espacios < 0) {
            espacios = 0;
        }
        caracteresImpresos++;
        if (caracteresImpresos >= limiteCaracteres) {
            break; // Salir del bucle
        }
        Sleep(0);
    } while (true);
}
void screamer(){
	cout << R"( 
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNXKOOKK0kxdox0XWNNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNK0kdl:,'','..   .':ldkkOKNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNX0ko:'.                .'.,lxOKXWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNXXKkxxkO0KNXKKKKXXNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNX0Oo;..    ..',;,....         ..,ccl0WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNOocccc;.  .',:codl:cxkxdxOKKXNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNXXXXOxl'.    .lOXNWWNNNXKOxo:'.      ...lXWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWKOkc.            .  .   .;..';lk0KNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNNNXOc.     .lKXOdoodddxkO0XWWNOo'       .dNWWWWWWWWWWWWWWWWWWWWWWWWWWWKd'..                          ..'cdONWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWKo,.     .xXx,          ..,oONWXo.      .OWWWWWWWWWWWWWWWWWWWWWWWWWWO,            .';;,...             '';0WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWXd;'     .x0:                .,xNWk,      ;KWWWWWWWWWWWWWWWWWWWWWWWNd.         .,lx0XWWNXK0OOxoc;.       ..:0WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNOl,.    .x0;                   .lXWKo.    .oWWWWWWWWWWWWWWWWWWWWWWNo.        ,o0NWWWWWWWWWWWWWWWWXko,      'o0NWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWKol:     oKc                      ;0WW0,    cNWWWWWWWWWWWWWWWWWWWWWk.       'xNWWWWWWWXOkkO0KXXNWWWWWX:     ;dOXWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWKkxc    .kk.                       :KWWO.   ,KWWWWWWWWWWWWWWWWWWWWNc       :KWWWWWWNOl'    ....,:oONWWO.    .,oXWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNk:.     oO,                       ,kWWNd.  '0WWWWWWWWWWNXXNWWWWWMX:      cXWWWWWWKl.              ,kW0'    .;l0WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNk;.     .d0c.                     ;0WWWO.  ,KWWWWWWWWWNOdkNWWWWWWNl     '0WWWWWWO,                 .O0'    .ccOWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWXkc.      .lKx.                  .,kWWWWx. .dWWWWWWWWWKxlco0WWWWWWNl     :XWWWWWk.                  .xO.    ':'dWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNK0o.       ,xOo.               'dKNWWXd.  oNWWWWWWN0l'....;kNWWWWWx,.   ;KMWWWX:                   .xd.    ..,kWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWN0o. .'.     ,xOxl;'.     ..,cxKWWN0o'   ;KWWWWN0l,.       .lXWWWWKx,   .xWWWMK;                   ,x;      :0NWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWXk;.;c,       .:x0KKOxdxk0XWWWXxc,.    'kNNWNO:.            :0WWWWk.    'OWWWNo.                 .oc      .dNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNx:cd:.         .,:lodxkkkdl;.      .:ONWNO:.               ,0WWWd'.    'xNWWNx,.             'co:.    ..:0WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNX0xoo'                         ...;xXWW0:.                  cXWWKx;.    .;kXWWXOxolol:;:cloocc;.      .'oXWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNXkdl.                      .;dxkXNWKo.                    .dWWWNx,.      .:dOXNWWNXK0kdl;.         .';dXWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNWWNK0x'  ..            ...,cx0XXXNWWNx.                      '0WWNOo'          .';;;;'.              'ox0WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNXNWWNXd..l;   ..    .;,;lkNWWWNWWWWWKo.                      .OWWNX0k:...                       ..'. 'ckNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNNNW0;,xl.  .'ld:'cxkKWWWWWWWWWWWWXx;.    .                '0WWWWWWXOoc;'.    ..''.    ..     ...  .cXWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWX0O00KKxx0x'  .;OWXkkKNWWWWWWWWWWWWWNKxlc:lkkxlc;;,..,'..    :KWWWWWWWWN0Oxc.  .cl::. ...;:.  ......,l0WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNKo;;clllcc:'   .':lcckXNWWWWWWWWWWWWWWWNOcOMWWNXKK0xddxxl'..'oKWWWWWWWWWWWNXk' ,O00k:.'oo,..  .,..,lONWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWKx:. ....'.         .,:ccok0KNWWWWWWWWW0xKWWWWWWWWWWWXkl;..:ONWWWWWWWWWWWWWWd.:0WWNKxdl'    ...'ccoXWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNO:..                ...  ..';:oddoooodOKXNNWWWWWWWWWN0o,:kNWWWWWWWWWWWWWWKc;OWWW0o'.    . ....;cOWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNKd:.           ....,;lo',c:,,'.  .... ..',;:clokKXNWXOdxXWWWWWWWWWKkxxkko,'lkd:.      .....,cxKWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW0,          ..'....ld;dXK0KXk';OXKk,  'c;..  .;:clc:cd0XXNNNNKkc.  ....           .'cc;;,;dXWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWN0xl'       .,;' .'l;.lKNXKKd,xWWWWO;lXWX00:.dXK0Okc..,dko;';:,.'..,,'.         .,lkOxdc,l0WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNk,       .,. .:d,  ;kNWK:'OMWWMXkKWWWWWOdXWWWWWNl,xNXk,.;dl'',.:c.       .;:o0NNXKkc:kXWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNx;.          .'.   .';'  'lxxxclKMWWWNkxNWWWWWW0d0WNKx;,col.. ',.      .,dKNWWWWN0doKWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNKx;..                          .cdddo;..ck00000oc0MWNO;,ll;.   .     ..;kXWWWWWWWNdoXWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWKo.  .                                   .....  ;lll,..;'.          .lKWWWWWWWWWWOkNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNd..::..                                                         .,xNWWWWWWWWWWWXXWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWx..oOdl,                                                       .:kNWWWWWWWWWWWNXXNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW0;,OWNKx:.                                                   .;d0NWWWWWWWWWWWWWWNNWWWNWWWWNNNNXXNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWKddXWWN0dc.                                                'oOXWWWWWWWWWWWWWWWNNWWNXXNNNNNXNWNXNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWN0KWWWWXKx;.      ...           .''.    ..               ,xKNWWWWWWWWWWWWWWWNNWWNNNNNWNNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNKkl.  .;x0x'.ldxxd;'lk0NNO, 'xKKx,'lxxl;;.   .cOXWWWWWWWWWWWWWWWWNNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNXOl. .'dd'cNMWWM0o0WWWWWd';OWWW0o0WWXo:.  .dNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNKd,. .'..ldkOOd;dWWWWWd',kWWWNk0WWK0O;  ;OWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWXx'       ...  ,dxxdc.  ;kK0o:xKd,.'. 'xNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNx,.                     ..  ..    ,lONWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNx,..                            ;OWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNX0xo:..                     ....:ONWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNX0dc:'          .;cclc..;:lxxokNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWX0o'..'.';cookXWWWWXxlod00kONWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWN0o:cdkKNWWWWWWWNXOxxKWXKNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWXOdkXWWWWWWWWXKXXXNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNKxdKWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNK0NWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW	
	)" << '\n';
	this_thread::sleep_for(chrono::microseconds(500));	
}
