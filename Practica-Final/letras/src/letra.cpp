#include "letra.h"
#include "comp.h"
#include <iostream>

using namespace std;

letra::letra(){}

char letra::getLetra() const{
  return caracter;
}

int letra::getCantidad() const{
  return cantidad;
}

int letra::getPuntuacion() const{
  return puntuacion;
}

istream & operator>>(istream & is, letra &L){
  char c; int i;
  is >> c;
  L.caracter = c;
  is >> i;
  L.cantidad = i;
  is >> i;
  L.puntuacion = i;
  return is;
}

ostream & operator<<(ostream & os, const letra &L){
  os << L.caracter << "\t" << L.cantidad << "\t" << L.puntuacion << endl;
  return os;
}

bool letra::operator < (const letra &l) const{ // Booleano para poder ordenar las letras en el set
  comp c;
  return c.menor(this->caracter,l.caracter); // Se usa una ordenacion especial para incluir las ñ
}
