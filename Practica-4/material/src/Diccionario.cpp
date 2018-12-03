#include <iostream>
#include <vector>
#include <string>
#include "Termino.h"
#include "Diccionario.h"

using namespace std;

Diccionario::Diccionario(){}
Diccionario::Diccionario(set<Termino> dic){
  dicc = dic;
}
Diccionario::Diccionario(const Diccionario &original){
  dicc = original.getTerminos();
}

vector<string> Diccionario::getDefiniciones(string pal) const{
  vector<string> res;
  set<Termino>::const_iterator it=findTermino(pal);
  if(it != dicc.end())
    res=it->getDefiniciones();
  return res;
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
void Diccionario::eliminarTermino(Termino t){
  set<Termino>::const_iterator it=findTermino(t);
  if(it != dicc.end())
    dicc.erase(it);
}
set<Termino>::const_iterator Diccionario::findTermino(string pal) const{ // dicc.find pero feo
  set<Termino>::const_iterator it=dicc.begin();
  for(bool salir=false; it!=dicc.end()&&!salir; ++it){
    if(it->getPalabra() == pal)
      salir=true;
  }
  return it;
}
set<Termino>::const_iterator Diccionario::findTermino(Termino t) const{ // Hay que buscar uno a uno por la palabra
  return findTermino(t.getPalabra());
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
    Termino aux;
    is >> aux;
    set<Termino>::iterator it = d.findTermino(aux);
    if(it == d.dicc.end()){ // Si es un termino nuevo
      d.aniadirTermino(aux);
    }
    else{ // Si ese termino ya estaba, se añade la definicion
      Termino t = (*it);
      t.aniadirDefinicion(aux.getDefiniciones()[0]);
      d.eliminarTermino(aux);
      d.aniadirTermino(t);
    }
  }
  return is;
}
