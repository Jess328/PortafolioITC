//Act 1.3 - Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales

//A01734879 Alejandro Armenta Arellano
//A01735227 Jesús Jiménez Aguilar
//A01735346 Daniela Berenice Hernandez de Vicente

//Fecha de creación: 13 de septiembre de 2021
//Fecha de modificación: 26 de septiembre de 2021

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;
//Clase Bitacora, aqui se colocaran los datos del arreglo por separado (mes,dia,hora,ip,razon y su orden)
class Bitacora{
	public:
		Bitacora(); // Constructor Default
		~Bitacora();// Destructor
		Bitacora(string mes, int dia, string hora, string ip, string razon, int orden);// Constructor con Parametros
    //Variables
		string mes;
		int dia;
		string hora;
		string ip;
		string razon;
		int orden;
		string hora_tem;
		//Funciones
		void imprimirBitacora(){
			cout<<mes<<" "<<dia<<" "<<hora<<" "<<ip<<" "<<razon<<endl;
		};

		bool operator>(Bitacora bitacora){return orden > bitacora.orden;};

		int reg_orden(){
			this->hora_tem = hora;
			this->hora_tem.erase(remove(this->hora_tem.begin(), this->hora_tem.end(), ':'), this->hora_tem.end());
			return (stoi(hora_tem));
		}
		//Esta funcion nos da el orden
		void casos();
};

//Constructores
Bitacora::Bitacora(){
	this->mes = " ";
	this->dia = 0;
	this->hora = " ";
	this->ip = " ";
	this->razon = " ";
	this->orden = 0;
}

Bitacora::Bitacora(string m, int d, string h, string i, string r, int o){
	this->mes = m;
	this->dia = d;
	this->hora = h;
	this->ip = i;
	this->razon = r;
	casos();
}

//Funciones
void Bitacora::casos()
{
	this->hora_tem = hora;
	this->hora_tem.erase(remove(this->hora_tem.begin(), this->hora_tem.end(), ':'), this->hora_tem.end());
	if(mes == "Jan")
	{
		orden = 1*100000000;
		orden += dia*1000000;
		orden += stoi(hora_tem);
	}
	if( mes == "Feb")
	{
		orden = 2*100000000;
		orden += dia*1000000;
		orden += stoi(hora_tem);
	}
	if(mes == "Mar")
	{
		orden = 3*100000000;
		orden += dia*1000000;
		orden += stoi(hora_tem);
	}
	if(mes == "Apr")
	{
		orden = 4*100000000;
		orden += dia*1000000;
		orden += stoi(hora_tem);
	}
	if(mes == "May")
	{
		orden = 5*100000000;
		orden += dia*1000000;
		orden += stoi(hora_tem);
	}
	if(mes == "Jun")
	{
		orden = 6*100000000;
		orden += dia*1000000;
		orden += stoi(hora_tem);
	}
	if(mes == "Jul")
	{
		orden = 7*100000000;
		orden += dia*1000000;
		orden += stoi(hora_tem);
	}
	if(mes == "Aug")
	{
		orden = 8*100000000;
		orden += dia*1000000;
		orden += stoi(hora_tem);
	}
	if(mes == "Sep")
	{
		orden = 9*100000000;
		orden += dia*1000000;
		orden += stoi(hora_tem);
	}
	if(mes == "Oct")
	{
		orden = 10*100000000;
		orden += dia*1000000;
		orden += stoi(hora_tem);
	}
	if(mes == "Nov")
	{
		orden = 11*100000000;
		orden += dia*1000000;
		orden += stoi(hora_tem);
	}
	if(mes == "Dec")
	{
		orden = 12*100000000;
		orden += dia*1000000;
		orden += stoi(hora_tem);
	}
}

Bitacora::~Bitacora()
{
}

template <class T>
//Complejidad: O(1)
void ordenaIntercambio(vector<T>& a, int i, int j){
	T aux = a[i];
	a[i] = a[j];
	a[j] = aux;
}

//Metodo con el cual se ordenara el arreglo
template <class T>
//Complejidad: O(n^2)
void ordenaInsercion(vector<T>& a, int n){
	for(int i = 1; i < n; i++){
		int j = i;
		while(j>0){
			if((a[j-1] > a[j]) == 1){
				ordenaIntercambio(a,j,j-1);
				j--;
			}
			else{
				j = 0;
			}
		}
	}
}

//Metodo de busqueda de valores dentro de un arreglo
template <class T>
//Complejidad: O(log2(n))
int busquedaBinaria(vector<T>& a, int min, int max, int dato){
	int key = (min + max)/2;
	if(dato == (a[key].orden - a[key].reg_orden())){
		return key;
	}
	else if(dato < (a[key].orden - a[key].reg_orden())){
		return busquedaBinaria(a,min,key-1,dato);
	}
	else{
		return busquedaBinaria(a,key + 1,max,dato);
	}
	return -1;
}

int main(){
  //Leer Archivo
	ifstream in("bitacora.txt");
	//Declaracion arreglo y variables
	vector<Bitacora> arreglo;
	string linea,mes,hora,ip,razon;
	int dia,orden = 0, i = 0;
	//Se lee cada linea del archivo y se divide en las variables de la clase Bitacora
	if(!in != true ){
		while(in >> mes){
			in>>dia>>hora>>ip;
			getline(in, razon);
			arreglo.push_back(Bitacora(mes,dia,hora,ip,razon,orden));
			i++;
		}
	}
	int fin = arreglo.size();
  //Se ordena el arreglo con la funcion ordenaInsercion
	ordenaInsercion(arreglo,fin);

  //Declaracion Variables
	string mesA,mesB;
	int diaA,diaB,mesC,mesD;
	//Se le pide al usuario que nos proporcione las fechas de inicio y fin del lapso
	cin>>mesC;
	cin>>diaA;

	cin>>mesD;
	cin>>diaB;

	//Desarrollamos una variable string para modificar el significado de cada mes por un valor textual
	string mesNumberMeaning1;
	if (mesC == 1){
			mesNumberMeaning1 = "Jan";
	}
	else if (mesC == 2){
			mesNumberMeaning1 = "Feb";
	}
	else if (mesC == 3){
			mesNumberMeaning1 = "Mar";
	}
	else if (mesC == 4){
			mesNumberMeaning1 = "Apr";
	}
	else if (mesC == 5){
			mesNumberMeaning1 = "May";
	}
	else if (mesC == 6){
			mesNumberMeaning1 = "Jun";
	}
	else if (mesC == 7){
			mesNumberMeaning1 = "Jul";
	}
	else if (mesC == 8){
			mesNumberMeaning1 = "Aug";
	}
	else if (mesC == 9){
			mesNumberMeaning1 = "Sep";
	}
	else if (mesC == 10){
			mesNumberMeaning1 = "Oct";
	}
	else if (mesC == 11){
			mesNumberMeaning1 = "Nov";
	}
	else if (mesC == 12){
			mesNumberMeaning1 = "Dec";
	}
	mesA=mesNumberMeaning1;

	//Desarrollamos una variable string para modificar el significado de cada mes por un valor textual
	string mesNumberMeaning2;
	if (mesD == 1){
			mesNumberMeaning2 = "Jan";
	}
	else if (mesD == 2){
			mesNumberMeaning2 = "Feb";
	}
	else if (mesD == 3){
			mesNumberMeaning2 = "Mar";
	}
	else if (mesD == 4){
			mesNumberMeaning2 = "Apr";
	}
	else if (mesD == 5){
			mesNumberMeaning2 = "May";
	}
	else if (mesD == 6){
			mesNumberMeaning2 = "Jun";
	}
	else if (mesD == 7){
			mesNumberMeaning2 = "Jul";
	}
	else if (mesD == 8){
			mesNumberMeaning2 = "Aug";
	}
	else if (mesD == 9){
			mesNumberMeaning2 = "Sep";
	}
	else if (mesD == 10){
			mesNumberMeaning2 = "Oct";
	}
	else if (mesD == 11){
			mesNumberMeaning2 = "Nov";
	}
	else if (mesD == 12){
			mesNumberMeaning2 = "Dec";
	}
	mesB=mesNumberMeaning2;

	//Se crea una Bitacora que tenga los valores deseados
	Bitacora busquedaInicio = Bitacora(mesA, diaA, "0", "0", "0", 0);
	Bitacora busquedaFinal = Bitacora(mesB, diaB, "0", "0", "0", 0);
	//Se obtiene la posicion de las lineas que tengan la fecha deseada
	int indexA = busquedaBinaria(arreglo,0,fin,busquedaInicio.orden);
	int indexB = busquedaBinaria(arreglo,0,fin,busquedaFinal.orden);
	//Impresion de todos los registros dentro del lapso de tiempo introducido
	for(int i = indexA; i <= indexB; i++){
		arreglo[i].imprimirBitacora();
	}
	//Se cierra el archivo
	in.close();
  //Creacion archivo de texto con los registros dentro del lapso solicitado
	ofstream out ("sorted.txt");
	for(int i = indexA; i <= indexB; i++){
		out<<arreglo[i].mes<<" "<<arreglo[i].dia<<" "<<arreglo[i].hora<<" "<<arreglo[i].ip<<" "<<arreglo[i].razon<<endl;
	}
	out.close();
	//Creacion archivo de texto con el arreglo ordenado
	ofstream outOrdenado ("ordenado.txt");
	for(int i = 0; i <= fin; i++){
		outOrdenado<<arreglo[i].mes<<" "<<arreglo[i].dia<<" "<<arreglo[i].hora<<" "<<arreglo[i].ip<<" "<<arreglo[i].razon<<endl;
	}
	outOrdenado.close();
};
