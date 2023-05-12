#include<string>
#include <iostream>
using namespace std;

class Cliente{
private:
  std::string nombre;
  std::string telefono;
  std::string direccion;
public:
  Cliente();
  Cliente(std::string d1, std::string d2, std::string d3);

  void setNombre(std::string);
  void setTelefono(std::string);
  void setDireccion(std::string);

  std::string getNombre();
  std::string getTelefono();
  std::string getDireccion();

  std::string to_string(){
    std::string impresion = "El nombre del cliente es: " + nombre + ", su número de telefono es: " + telefono + " y vive en: " + direccion + " ";
    return impresion;
  }



};
