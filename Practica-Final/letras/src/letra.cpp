#include "letra.h"
#include <iostream>

using namespace std;

letra::letra(){}
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
    return this->caracter < l.caracter;
}
