// A01730560 || Francisco Rocha Juaréz
// A01735227 || Jesús Jiménez Aguilar
//Clase video. ABSTRACTA

class Video{
protected:
  int dur;
  string nom;
  string idV;
  string gen;
  float rat;
  int nrat;
  Video();
  Video(string,string,int,float,string,int);
public:
  virtual void showVideo()=0;//Método virtual, imprime info. del video (Cambia para peli y episodio)
  string getID();
  string getNom();
  string getGen();
  float getRat();
  void setRat(float);
  float operator+(const float&);//Sobrecarga de operador más para obtener nuevo promedio por nueva calificación
  virtual string getSer();
};
