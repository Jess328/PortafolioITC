// A01735227 || Jesús Jiménez Aguilar
// A01730560 || Francisco Rocha Juaréz

//Clase Info. Administrador de vector con todos los vídeos

class Info{
private:
  vector<Video*> allVid;//Vector que contiene TODOS los videos

public:
  Info();//Constructor
  vector<Video*> getA();
  void reaF(string);
  void reaPel(string);
  void reaEp(string);
  void printA();
  void printV(vector<Video*>);
  vector<Video*> bCal(vector<Video*>,float,float);
  vector<Video*> bGen(vector<Video*>,string);
  vector<Video*> allSer();
  vector<Video*> allPel();
  vector<Video*> dSer(vector<Video*>,string);
  Video* bus(string);
  int lenV();
};
