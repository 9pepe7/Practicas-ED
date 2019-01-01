#include "lista_palabras.h"
#include <set>
#include <iostream>

using namespace std;

lista_palabras::lista_palabras(){} // Constructor por defecto

int lista_palabras::size() const{ // size
  return datos.size();
}

vector<string> lista_palabras::palabras_longitud(const int &longitud) const{ // filtro por tamaño de palabra
  vector<string> res;
  if(longitud>0){
    unsigned aux = longitud; // Para evitar el warning de comparar signed y unsigned
    for(lista_palabras::iterator it=begin(); it!=end(); ++it){
      if((*it).length()==aux)
        res.push_back(*it);
    }
  }
  return res;
}

bool lista_palabras::Esta(const string &palabra) const{ // find
  return datos.find(palabra)==datos.end() ? false : true;
}

istream & operator>>(istream & is, lista_palabras &D){ // flujo de entrada
  string pal;
  while(!is.eof()){
    is >> pal;
    D.datos.insert(pal);
  }
  return is;
}

ostream & operator<<(ostream & os, const lista_palabras &D){ // flujo de salida
  for(lista_palabras::iterator it=D.begin(); it!=D.end(); ++it){ // RICO SEGMENTATION FAULT
  //for(set<string>::iterator it=D.datos.begin();it!=D.datos.end();++it){ // ESTE FUNCIONA
    os << *it << " ";
  }
  os << endl;
  return os;
}

lista_palabras::iterator::iterator (){} // constructor del iterador
string lista_palabras::iterator::operator *() const{ // Devuelve el objeto iterado
  return *it;
}

lista_palabras::iterator & lista_palabras::iterator::operator ++(){ // Avanza el iterador
  ++it;
  return *this;
}

bool lista_palabras::iterator::operator ==(const lista_palabras::iterator &i) const{
  return this->it == i.it;
}

bool lista_palabras::iterator::operator !=(const lista_palabras::iterator &i) const{
  return this->it != i.it;
}

lista_palabras::iterator lista_palabras::begin() const{
  lista_palabras::iterator res;
  res.it=datos.begin();
  return res;
}

lista_palabras::iterator lista_palabras::end() const{
  lista_palabras::iterator res;
  res.it=datos.end();
  return res;
}
