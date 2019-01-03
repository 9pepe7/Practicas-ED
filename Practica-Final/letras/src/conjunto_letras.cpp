#include "conjunto_letras.h"
#include "letra.h"
#include <iostream>
#include <string>
#include <set>
#include <ctype.h> // toupper

using namespace std;

conjunto_letras::conjunto_letras(){}

void conjunto_letras::pantallaPuntuaciones(){ // Saca por pantalla las puntuaciones del objeto conjunto
  cout << "******Puntuaciones Letras*******" << endl;
  for(conjunto_letras::iterator it = begin(); it!=end(); ++it)
    cout << (*it).getLetra() << "\t" << (*it).getPuntuacion() << endl;
}

int conjunto_letras::puntuacion(const char &c) const{ // Devuelve la puntuacion de un caracter
  conjunto_letras::iterator it = this->find(c);
  if(it != end())
    return (*it).getPuntuacion();
  return 0;
}

conjunto_letras::iterator conjunto_letras::find(const char &c) const { // Busca un caracter
  for(conjunto_letras::iterator it=this->begin(); it!=this->end(); ++it){
    if((*it).getLetra() == toupper(c))
      return it; // Devuelve puntero al objeto letra
  }
  return end(); // Si no se encuentra, se devuelve end
}

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

conjunto_letras::iterator conjunto_letras::begin(){
  return this->letras.begin();
}
conjunto_letras::const_iterator conjunto_letras::begin() const{
  return this->letras.begin();
}
conjunto_letras::iterator conjunto_letras::end(){
  return this->letras.end();
}
conjunto_letras::const_iterator conjunto_letras::end() const{
  return this->letras.end();
}
