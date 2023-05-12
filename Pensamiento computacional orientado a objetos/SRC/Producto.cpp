#include "Producto.h"
#include <iostream>
using namespace std;

Producto::Producto(){
  categoria = "none";
  articulo = "none";
  precio = 0.0;
  cantidad = 0;
  persona = Cliente();
  metodopago = "none";
  numerorastreo = 0;
}

Producto::Producto(std::string d1, std::string d2, double d3, int d4, Cliente d5, std::string d6, int d7){
  categoria = d1;
  articulo = d2;
  precio = d3;
  cantidad = d4;
  persona = d5;
  metodopago = d6;
  numerorastreo = d7;
}

void Producto::setCategoria(std::string cat){
  categoria = cat;
}

void Producto::setArticulo(std::string art){
  articulo = art;
}

void Producto::setPrecio(double pre){
    precio = pre;
}

void Producto::setCantidad(int can){
  cantidad = can;
}

void Producto::setPersona(Cliente per){
  persona = per;
}

void Producto::setMetodoPago(std::string metpag){
  metodopago = metpag;
}

void Producto::setNumeroRastreo(int numras){
 numerorastreo = numras;
}



std::string Producto::getCategoria(){
  return categoria;
}

std::string Producto::getArticulo(){
  return articulo;
}

double Producto::getPrecio(){
  return precio;
}

int Producto::getCantidad(){
  return cantidad;
}


std::string Producto::getMetodoPago(){
  return metodopago;
}

int Producto::getNumeroRastreo(){
  return numerorastreo;
}
