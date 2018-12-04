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
int Diccionario::getNumTerminos() const{
  return dicc.size();
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

Diccionario Diccionario::filtradoIntervalo(char ini, char fin) const{
  Diccionario res;
  set<Termino>::const_iterator it;
  if(ini >= 'A' && ini <= 'Z') // Transformamos a minuscula
    ini+=32;
  if(fin >= 'A' && fin <= 'Z')
    fin+=32;
  if(ini > fin){
    char aux = ini;
    ini = fin;
    fin = aux;
  }
  for(it=dicc.begin(); it->getPalabra()[0] < ini; ++it){} // Colocamos el iterador en la primera palabra buena
  while( it->getPalabra()[0] < (fin+1) && it!=dicc.end() )
    res.aniadirTermino(*it);
  return res;
}
Diccionario Diccionario::filtradoClave(string clave) const{
  Diccionario res;
  for(set<Termino>::const_iterator it=dicc.begin(); it!=dicc.end(); ++it){
    Termino t;
    t.setPalabra(it->getPalabra());
    for(Termino::const_iterator it2 = it->begin(); it2!=it->end(); ++it2){
      std::size_t encontrada = it2->find(clave); // Busca la palabra en la definicion
      if (encontrada != string::npos) // Si sí la encuentra, la guarda
        t.aniadirDefinicion(*it2);
    }
    if(t.getNumDef()>0) // Si se guardó alguna definicion, se guarda el término
      res.aniadirTermino(t);
  }
  return res;
}

int Diccionario::totalDefininiciones() const{
  int n=0;
  for(set<Termino>::const_iterator it=dicc.begin(); it!=dicc.end(); ++it){
    n+=it->getNumDef();
  }
  return n;
}
int Diccionario::maxDefiniciones() const{
  int max=0;
  for(set<Termino>::const_iterator it=dicc.begin(); it!=dicc.end(); ++it){
    if(it->getNumDef() > max)
      max=it->getNumDef();
  }
  return max;
}
int Diccionario::promedioDefiniciones() const{
  double n=totalDefininiciones();
  return n/getNumTerminos();
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
