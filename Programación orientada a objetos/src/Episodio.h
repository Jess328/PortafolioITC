// A01730560 || Francisco Rocha Juaréz
// A01735227 || Jesús Jiménez Aguilar

//Clase Episodio
class Episodio:public Video{
private:
  string ser;
  int temp;
  int nepsi;
public:
  Episodio(string,string,int,float,string,int,string,int,int);
  void showVideo();
  string getSer();
};
