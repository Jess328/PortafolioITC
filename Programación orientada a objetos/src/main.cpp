// A01735227 || Jesús Jiménez Aguilar
// A01730560 || Francisco Rocha Juaréz

#include <iostream>
#include<sstream>
#include <fstream>
#include<vector>
using namespace std;
#include "Video.cpp"
#include "Pelicula.cpp"
#include "Episodio.cpp"
#include "Info.cpp"

//Ejecución del programa
int main() {
  int men=0;
  string us;
  string fil;
  Info dat=Info();
  vector<Video*> fied;
  float min,max,cal;
  Video* busc;

  //mensaje de bienvenida:
  cout<<"\n****************************BIENVENIDX A TU PLATAFORMA***************************\n******************************FAVORITA DE STREAMING******************************"<<endl<<endl;

  //Main menu:
  while (men==0){
    cout<<"*********************************MENU  PRINCIPAL*********************************"<<endl;
    cout<<"1. Cargar archivo de datos\n2. Mostrar los videos en general, con una cierta calificacion o de un cierto genero\n3. Mostrar los episodios de una determinada serie con una calificacion determinada\n4. Mostrar las películas con cierta calificacion\n5. Calificar un video\n0. Salir"<<endl;
    cout<<"*********************************************************************************"<<endl;

    cin>>us;
    cout<<endl;

    //Opción 1: Cargar archivo
    if(us=="1"){
      cout<<"Ingresa el nombre del archivo. (Por favor incluye la terminacion .txt)"<<endl;
      cin>>fil;
      dat.reaF(fil);
    }

    //Opción 1: Mostrar videos
    else if(us=="2"){
      //Submenú
      cout<<"Seleccione una opcion:\n1. Mostrar todos los videos\n2. Filtrar por genero\n3. Filtrar por calificacion\n";
      cin>>us;
      //Submenu op. 1: Mostrar todos los videos
      if(us=="1"){
        if(dat.lenV()>0){
          cout<<"Todos los videos:\n";
          dat.printA();
        }
        else{
          cout<<"No se encontraron datos."<<endl<<endl;
        }
      }
      //Submenu op. 2: Mostrar videos
      else if(us=="2"){
        if(dat.lenV()>0){
          cout<<"Escriba el genero:\n-Drama\n-Accion\n-Misterio "<<endl;
          cin>>us;
          fied=dat.bGen(dat.getA(),us);
          if(fied.size()>0){
            cout<<"\nResultados:"<<endl<<endl;
            dat.printV(fied);
          }
          else{
            cout<<"No se encontraron datos."<<endl<<endl;
          }
        }
        else{
          cout<<"No se encontraron datos."<<endl<<endl;
        }
      }
      //Submenu op. 3: Mostrar videos por rating
      else if(us=="3"){
        if(dat.lenV()>0){
          cout<<"Escriba la calificacion minima (0-5): "<<flush;
          cin>>min;
          cout<<"Escriba la calificacion maxima (0-5): "<<flush;
          cin>>max;
          fied=dat.bCal(dat.getA(),min,max);
          if(fied.size()>0){
            cout<<"\nResultados:"<<endl<<endl;
            dat.printV(fied);
          }
          else{
            cout<<"No se encontraron datos."<<endl<<endl;
          }
        }
        else{
          cout<<"No se encontraron datos."<<endl<<endl;
        }
      }
      else{
        cout<<"Opcion invalida"<<endl<<endl;
      }
    }
    //Opción 3: Filtrar videos de serie por rating
    else if (us=="3"){
      cout<<"Escriba el nombre de la serie que desea filtrar: "<<flush;
      getline(cin,us);
      getline(cin,us);
      cout<<"Escriba la calificacion minima (0-5): "<<flush;
      cin>>min;
      cout<<"Escriba la calificacion maxima (0-5): "<<flush;
      cin>>max;
      if(dat.lenV()>0){
        fied=dat.allSer();
        fied=dat.dSer(fied,us);
        fied=dat.bCal(fied,min,max);
        if(fied.size()>0){
          cout<<"\nResultados:"<<endl<<endl;
          dat.printV(fied);
        }
        else{
          cout<<"No se encontraron datos."<<endl<<endl;
        }
      }
      else{
        cout<<"No se encontraron datos."<<endl<<endl;
      }
    }
    //Opción 4: Filtrar películas por rating
    else if (us=="4"){
      cout<<"Escriba la calificacion minima (0-5): "<<flush;
      cin>>min;
      cout<<"Escriba la calificacion maxima (0-5): "<<flush;
      cin>>max;
      if(dat.lenV()>0){
        fied=dat.allPel();
        fied=dat.bCal(fied,min,max);
        if(fied.size()>0){
          cout<<"\nResultados:"<<endl<<endl;
          dat.printV(fied);
        }
        else{
          cout<<"No se encontraron datos."<<endl<<endl;
        }
      }
      else{
        cout<<"No se encontraron datos."<<endl<<endl;
      }
    }
    //Opción 5: Calificar
    else if(us=="5"){
      cout<<"Escriba el nombre o ID del titulo a calificar: "<<flush;
      getline(cin,us);
      getline(cin,us);
      busc=dat.bus(us);
      if ((busc->getID())!="NE"){
        cout<<"Introduzca calificacion: "<<flush;
        cin>>cal;
        busc->setRat(*busc+cal);
        cout<<"Título calificado con exito."<<endl<<endl;
        cout<<"Nueva calificacion del titulo: "<<busc->getRat()<<endl<<endl;
      }
      else{
        cout<<"No se encontro el titulo."<<endl<<endl;
      }
    }
    //Opción 0: Salir
    else if(us=="0"){
      cout<<"Regresa pronto!"<<endl<<endl;
      break;
    }
    else{
      cout<<"Opcion invalida. Intenta de nuevo."<<endl<<endl;
    }
  }
  return 0;
}
