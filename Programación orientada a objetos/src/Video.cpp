// A01730560 || Francisco Rocha Juaréz
// A01735227 || Jesús Jiménez Aguilar
//Cpp de clase Video
#include "Video.h"

//Constructor con todos los atributos. Parámetros: id,nombre,duracion,rating,genero,no. de personas que han calificado
Video::Video(string x,string y,int z,float a,string b,int nr){
  idV=x;
  nom=y;
  dur=z;
  rat=a;
  //Convierte genero a minúsculas
  for (int i = 0; i < b.length(); i++) {
    b[i]=tolower(b[i]);
  }
  gen=b;
  nrat=nr;
}

//Constructor vacío. Parámetros con "NE" para indicar no existe. Se utiliza para buscador, para indicar que no se encontró un título
Video::Video(){
  idV="NE";
  nom="NE";
  dur=0;
  rat=0;
  gen="NE";
  nrat=0;
}

//Muestra información del video
void Video::showVideo(){
  cout<<"''"<<nom<<"''\n"<<"ID: "<<idV<<" Duracion: "<<dur<<" min. Rating: "<<rat<<" Genero: "<<gen<<endl;
}

string Video::getID(){
  return idV;
}

string Video::getNom(){
  return nom;
}

string Video::getGen(){
  return gen;
}

float Video::getRat(){
  return rat;
}

void Video::setRat(float r){
  rat=r;
}

//Sobrecarga de operador +. Se suma nueva calificación, regresa nuevo promedio
float Video::operator+(const float& cal){
  float prom=((rat*nrat)+cal)/(nrat+1);
  nrat++;
  return prom;
}

string Video::getSer(){
  return 0;
}//Solo hace algo con episodios
