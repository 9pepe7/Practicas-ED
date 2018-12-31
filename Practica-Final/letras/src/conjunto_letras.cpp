#include "conjunto_letras.h"
#include "letra.h"
#include <iostream>
#include <string>
#include <set>

using namespace std;

conjunto_letras::conjunto_letras(){}
istream & operator>>(istream & is, conjunto_letras &C){
  string aux;
  getline(is,aux);
  while(!is.eof()){
    letra l;
    is >> l;
    C.letras.insert(l);
  }
  return is;
}
ostream & operator<<(ostream & os, const conjunto_letras &C){
  os << "#Letra\tCantidad\tPuntos" << endl;
  for(set<letra>::iterator it=C.letras.begin(); it!=C.letras.end(); ++it)
    os << *it;
  os << endl;
  return os;
}
