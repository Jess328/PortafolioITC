#include<string>
#include <iostream>
#include "Cliente.cpp"
using namespace std;

class Producto{
  //En esta parte definimos las variables que vamos a utilizar y su tipo de dato
  private:
    std::string categoria;
    std::string articulo;
    double precio;
    int cantidad ;
    Cliente persona;
    std::string metodopago;
    int numerorastreo;

  public:
    //Creamos un constructor vacío y otro con todos los datos que requiere el objeto producto
    Producto();
    Producto(std::string d1, std::string d2, double d3, int d4, Cliente d5, std::string d6, int d7);

    Cliente getPersona(){
          return persona;
        }

void setCategoria(std::string);
void setArticulo(std::string);
void setPrecio(double);
void setCantidad(int);
void setPersona(Cliente);
void setMetodoPago(std::string);
void setNumeroRastreo(int);

std::string getCategoria();
std::string getArticulo();
double getPrecio();
int getCantidad();
std::string getMetodoPago();
int getNumeroRastreo();

std::string to_string(){
      std::string impresion = "Categoria: "+categoria+"\nArtiulo: "+articulo+"\nPrecio: "+std::to_string(precio)+"\nCantidad: "+std::to_string(cantidad)+"\n"+persona.to_string()+"\nMetodo de pago: "+metodopago+"\nNumero de rastreo: "+std::to_string(numerorastreo);
      return impresion;
    }
};
