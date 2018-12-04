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
  Diccionario::const_iterator it=findTermino(pal);
  if(it != end())
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
  Diccionario::const_iterator it=findTermino(t);
  if(it != end())
    dicc.erase(it);
}
void Diccionario::eliminarTermino(Diccionario::iterator it){
  dicc.erase(it);
}
Diccionario::const_iterator Diccionario::findTermino(string pal) const{ // dicc.find pero feo
  for(Diccionario::const_iterator it=begin(); it!=end(); ++it){
    if(it->getPalabra() == pal){
      return it;
    }
  }
  return end();
}
Diccionario::const_iterator Diccionario::findTermino(Termino t) const{ // Hay que buscar uno a uno por la palabra
  return findTermino(t.getPalabra());
}

Diccionario Diccionario::filtradoIntervalo(char ini, char fin) const{
  Diccionario res;
  Diccionario::const_iterator it;
  if(ini >= 'A' && ini <= 'Z') // Transformamos a minuscula
    ini+=32;
  if(fin >= 'A' && fin <= 'Z')
    fin+=32;
  if(ini > fin){
    char aux = ini;
    ini = fin;
    fin = aux;
  }
  for(it=begin(); it->getInicial() < ini && it!=end(); ++it){} // Colocamos el iterador en la primera palabra buena
  while( it->getInicial() <= fin && it!=end())
    res.aniadirTermino(*it);
  return res;
}
Diccionario Diccionario::filtradoClave(string clave) const{
  Diccionario res;
  for(Diccionario::const_iterator it=begin(); it!=end(); ++it){ // Itero sobre todos los terminos del diccionario
    Termino t; // Creo un termino vacio
    for(Termino::const_iterator it2 = it->begin(); it2!=it->end(); ++it2){ // Itero sobre las def del termino en el que se encuentra "it"
      if (it2->find(clave) != string::npos) // Busca si aparece la palabra en la definicion en la que se encuentra "it2"
        t.aniadirDefinicion(*it2); // Si sí la encuentra, la guarda, si no, find devuelve un size_t==npos
    }
    if(t.getNumDef()>0){ // Si se guardó alguna definicion, se guarda el término
      t.setPalabra(it->getPalabra()); // Le pongo su palabra
      res.aniadirTermino(t); // Y lo añado al diccionario
    }
  }
  return res;
}

int Diccionario::totalDefininiciones() const{
  int n=0;
  for(Diccionario::const_iterator it=begin(); it!=end(); ++it){
    n+=it->getNumDef();
  }
  return n;
}
int Diccionario::maxDefiniciones() const{
  int max=0;
  for(Diccionario::const_iterator it=begin(); it!=end(); ++it){
    if(it->getNumDef() > max)
      max=it->getNumDef();
  }
  return max;
}
int Diccionario::promedioDefiniciones() const{
  double n=totalDefininiciones();
  return n/getNumTerminos();
}
bool Diccionario::sonletras(const char &c1, const char &c2) const{
  bool res=true;
  if( (c1<'A' || c1>'Z') && (c1<'a' || c1>'z') )
    res=false;
  if( (c2<'A' || c2>'Z') && (c2<'a' || c2>'z') )
    res=false;
  return res;
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
  while(!is.eof()){
    Termino nuevo;
    is >> nuevo;
    Diccionario::iterator it = d.findTermino(nuevo);
    if(it == d.end()){ // Si es un termino nuevo
      if(nuevo.getPalabra()!="")
        d.aniadirTermino(nuevo);
    }
    else{ // Si ese termino ya estaba, se añade la definicion
      Termino antiguo = (*it);
      d.eliminarTermino(it);
      antiguo.aniadirDefinicion(nuevo.getDefinicion());
      d.aniadirTermino(antiguo);
    }
  }
  return is;
}
