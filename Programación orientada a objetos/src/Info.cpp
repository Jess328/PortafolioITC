// A01735227 || Jesús Jiménez Aguilar
// A01730560 || Francisco Rocha Juaréz

//Cpp de clase Info

#include "Info.h"

//Inicia objeto vacío. (Se llena hasta que se carga archivo)
Info::Info(){}

//Regresa vector con todos los vídeos
vector<Video*> Info::getA(){
  return allVid;
}

//Regesa tamaño del vector con todos los vídeos
int Info::lenV(){
  return allVid.size();
}

//Lector de archivos
void Info::reaF(string arch){
  ifstream rea;
  string lie;
  rea.open(arch);
  if (rea.is_open()){
    allVid.clear();
    while (getline(rea,lie)){
      if (lie[0]=='M'){
        reaPel(lie);
      }
      if (lie[0]=='S'){
        reaEp(lie);
      }
    }
    rea.close();
    cout<<"Los datos se han cargado correctamente."<<endl<<endl;
  }
  else{
    cout<<"No se encontro ningun archivo."<<endl<<endl;
  }
}

//Lector de película
void Info::reaPel(string lie){
  string id="";
  string nom="";
  string tie="";
  string cat="";
  string pun="";
  string npun="";
  int cont=1;
  for (int i = 0; i < lie.length(); i++) {
        if (lie[i]==';'){
          cont+=1;
        }
        else if (cont==1){
          id+=lie[i];
        }
        else if (cont==2){
          nom+=lie[i];
        }
        else if (cont==3){
          tie+=lie[i];
        }
        else if (cont==4){
          cat+=lie[i];
        }
        else if (cont==5){
          pun+=lie[i];
        }
        else if (cont==6){
          npun+=lie[i];
        }
  }
  allVid.push_back(new Pelicula(id,nom,stoi(tie),stof(pun),cat,stoi(npun)));
}

//Lector de episodio
void Info::reaEp(string lie){
  int cont=1;
  string id="";
  string nom="";
  string tie="";
  string cat="";
  string pun="";
  string noms="";
  string temp="";
  string epsi="";
  string npun="";

  for (int i = 0; i < lie.length(); i++) {
        if (lie[i]==';'){
          cont+=1;
        }
        else if (cont==1){
          id+=lie[i];
        }
        else if (cont==2){
          noms+=lie[i];
        }
        else if (cont==3){
          nom+=lie[i];
        }
        else if (cont==4){
          tie+=lie[i];
        }
        else if (cont==5){
          cat+=lie[i];
        }
        else if (cont==6){
          pun+=lie[i];
        }
        else if (cont==7){
          npun+=lie[i];
        }
  }
  temp=id.substr(8,2);
  epsi=id.substr(10,2);
  allVid.push_back(new Episodio(id,nom,stoi(tie),stof(pun),cat,stoi(npun),noms,stoi(temp),stoi(epsi)));
}

//Imprime todos los vídeos
void Info::printA(){
  for (int i = 0; i < allVid.size(); i++) {
    cout<<i+1<<". "<<flush;
    allVid[i]->showVideo();
    cout<<endl;
  }
}

//Filtra las películas
vector<Video*> Info::allPel(){
  vector<Video*> rVector;
  string id;
  string iden;
  for(int i=0;i<allVid.size();i++){
    id=allVid[i]->getID();
    iden=id.substr(0,1);
    if(iden=="M"){
      rVector.push_back(allVid[i]);
    }
  }
  ;
  return rVector;
}

//Filtra todos los episodios
vector<Video*> Info::allSer(){
  vector<Video*> rVector;
  string id;
  string iden;
  for(int i=0;i<allVid.size();i++){
    id=allVid[i]->getID();
    iden=id.substr(0,1);
    if(iden=="S"){
      rVector.push_back(allVid[i]);
    }
  }

  return rVector;
}

//Filtra los episodios de una serie en específico. Se tiene que dar como argumento vector de solo series y string con búsqueda
vector<Video*> Info::dSer(vector<Video*> sers,string ns){
  vector<Video*> rVector;
  string nss;
  //Convierte a minúsculas la búsqueda
  for (int i = 0; i < ns.length(); i++) {
    ns[i]=tolower(ns[i]);
  }
  for(int i=0;i<sers.size();i++){
    nss=sers[i]->getSer();
    //Convierte nombre de serie a minúscula
    for (int j = 0; j < nss.length(); j++) {
      nss[j]=tolower(nss[j]);
    }
    if(ns==nss){
      rVector.push_back(sers[i]);
    }
  }
  return rVector;
}

//Imprime vector en específico. Como argumento el vector a imprimir
void Info:: printV(const vector<Video*> toPrint){
  for (int i = 0; i < toPrint.size(); i++) {
    cout<<i+1<<". "<<flush;
    toPrint[i]->showVideo();
    cout<<endl;
  }
}

//Filtra por género. Argumentos: vector a filtrar y género buscado
vector<Video*> Info::bGen(const vector<Video*> toSort, string gen){
  vector<Video*> toReturn;
  string gVector;
  //Convierte a minúsculas la búsqueda
  for (int i = 0; i < gen.length(); i++) {
    gen[i]=tolower(gen[i]);
  }
  for(int i=0;i<toSort.size();i++){
    gVector=toSort[i]->getGen();
    if(gVector==gen){
      toReturn.push_back(toSort[i]);
    }
  }
  return toReturn;
}

//Filtra vector por calificación. Argumentos: vector, cal. mínima y cal. máxima
vector<Video*> Info::bCal(vector<Video*> toSort, float min,float max){
  vector<Video*> toReturn;
  float ratVector;
  for(int i=0;i<toSort.size();i++){
    ratVector=toSort[i]->getRat();
    if((ratVector>=min)&&(ratVector<=max)){
      toReturn.push_back(toSort[i]);
    }
  }
  return toReturn;
}

//Buscar video en específico por id o nombre
Video* Info::bus(string bus){
  Video* toReturn;
  string nom;
  string id;
  int check=0;
  //Convierte a minúsculas la búsqyeda
  for (int i = 0; i < bus.length(); i++) {
    bus[i]=tolower(bus[i]);
  }
  for(int i=0;i<allVid.size();i++){
    nom=allVid[i]->getNom();
    id=allVid[i]->getID();
    //Convierte a minusculas el nombre
    for (int j = 0; j < nom.length(); j++) {
      nom[j]=tolower(nom[j]);
    }
    //Convierte a minusculas el id
    for (int j = 0; j < id.length(); j++) {
      id[j]=tolower(id[j]);
    }
    if(bus==nom||bus==id){
      toReturn=allVid[i];
      check=1;
      break;
    }
  }
  //Si no se encuentra video, se crea una película con constructor vación (se indica que no existe en const. vacío)
  if (check==0){
    toReturn=new Pelicula();
  }
  return toReturn;
}
