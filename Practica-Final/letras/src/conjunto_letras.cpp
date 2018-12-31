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
  os << "#Letra Cantidad Puntos" << endl;
  for(set<letra>::iterator it=C.letras.begin(); it!=C.letras.end(); ++it)
    os << *it;
  return os;
}

conjunto_letras::iterator::iterator (){}
letra conjunto_letras::iterator::operator *() const{
  return *it;
}
conjunto_letras::iterator & conjunto_letras::iterator::operator ++(){
  ++it;
  return *this;
}
bool conjunto_letras::iterator::operator ==(const conjunto_letras::iterator &i) const{
  return this->it==i.it;
}
bool conjunto_letras::iterator::operator !=(const conjunto_letras::iterator &i) const{
  return this->it!=i.it;
}
conjunto_letras::iterator conjunto_letras::begin() const{
  conjunto_letras::iterator res;
  res.it=letras.begin();
  return res;
}
conjunto_letras::iterator conjunto_letras::end() const{
  conjunto_letras::iterator res;
  res.it=letras.end();
  return res;
}
