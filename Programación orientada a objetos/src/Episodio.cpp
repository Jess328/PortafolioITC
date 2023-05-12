// A01730560 || Francisco Rocha Juaréz
// A01735227 || Jesús Jiménez Aguilar
//Cpp de clase Episodio
#include "Episodio.h"

//Constructor. Primeros 5 parámetros para constructor de video. 3 parámetros extra: serie,temporada,episodio
Episodio::Episodio(string x,string y,int z,float a,string b,int nr,string c,int m,int n):Video(x,y,z,a,b,nr){
  ser=c;
  temp=m;
  nepsi=n;
}

//Añade información de serie, temporada y episodio al método de imprimir de video
void Episodio::showVideo(){
  cout<<ser<<". Temporada "<<temp<<", Episodio "<<nepsi<<": "<<flush;
  Video::showVideo();
}

////Regresa serie a la que pertence
string Episodio::getSer(){
  return ser;
}
