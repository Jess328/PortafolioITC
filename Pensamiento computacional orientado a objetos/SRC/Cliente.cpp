#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente(){
  nombre = "none";
  telefono = "none";
  direccion = "none";
}

Cliente::Cliente(std::string d1, std::string d2, std::string d3){
  nombre = d1;
  telefono = d1;
  direccion = d1;
}

void Cliente::setNombre(std::string nom){
  nombre = nom;
}

void Cliente::setTelefono(std::string tel){
  telefono = tel;
}

void Cliente::setDireccion(std::string dir){
    direccion = dir;
}

std::string Cliente::getNombre(){
  return nombre;
}

std::string Cliente::getTelefono(){
  return telefono;
}

std::string Cliente::getDireccion(){
  return direccion;
}
