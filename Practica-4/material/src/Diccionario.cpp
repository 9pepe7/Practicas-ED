#include <iostream>
#include "Termino.h"
#include "Diccionario.h"

using namespace std;

Diccionario::Diccionario(){}
Diccionario::Diccionario(set<Termino> dic){
  dicc = dic;
}
Diccionario::Diccionario(Diccionario original){
  dicc = original.getTerminos();
}

vector<string> Diccionario::getDefiniciones(string pal) const{ // Completar
  return (findTermino(pal))->getDefiniciones();
}
set<Termino> Diccionario::getTerminos() const{
  return dicc;
}
int Diccionario::getNumTerminos() const{ // Completar
  return 0;
}

void Diccionario::aniadirTermino(Termino t){
  dicc.insert(t);
}
void Diccionario::eliminarTermino(string pal){
  dicc.erase(findTermino(pal));
}
Termino::const_iterator findTermino(string pal) const{ // Completar
  return begin();
}

Diccionario Diccionario::filtradoIntervalo(char ini, char fin) const{ // Completar
  Diccionario res;
  return res;
}
Diccionario Diccionario::filtradoClave(string clave) const{ // Completar
  Diccionario res;
  return res;
}

int Diccionario::totalDefininiciones() const{ // Completar
  return 0;
}
int Diccionario::maxDefiniciones() const{ // Completar
  return 0;
}
int Diccionario::promedioDefiniciones() const{ // Completar
  return 0;
}

Diccionario::iterator Diccionario::begin(){
  return dicc.begin();
}
Diccionario::const_iterator Diccionario::begin() const{
  return dicc.begin();
}
Diccionario::iterator Diccionario::end(){
  return dicc.end();
}
Diccionario::const_iterator Diccionario::end() const{
  return dicc.end();
}

ostream& operator<< (ostream & os, const Diccionario & d){ // Esta viene en el pdf
  Diccionario::const_iterator it;
  for(it = d.begin(); it != d.end(); ++it){
    os << *it;
  }
  return os;
}
istream& operator>> (istream & is, Diccionario & d){
  while(!is.eof())
  {
    Termino t;
    is >> t;
    set<Termino>::iterator it = d.dicc.find(t);
    if(it == d.dicc.end())
      d.aniadirTermino(t);
    else
      it->aniadirDefinicion(t.getDefiniciones[0]);
  }
  return flujo;
}
