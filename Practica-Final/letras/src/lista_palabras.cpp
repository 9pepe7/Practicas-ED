#include "lista_palabras.h"
#include <set>

using namespace std;

lista_palabras::lista_palabras(){}

int lista_palabras::size() const{
  return datos.size();
}

vector<string> lista_palabras::palabras_longitud(const int &longitud) const{
  vector<string> res;
  return res;
}

bool lista_palabras::Esta(const string &palabra) const{
  set<string>::iterator it = datos.find(palabra);
  if(it==datos.end())
    return false;
  else
    return true;
}

istream & operator>>(istream & is, lista_palabras &D){
  return is;
}

ostream & operator<<(ostream & os, const lista_palabras &D){
  return os;
}


  lista_palabras::iterator::iterator (){}
  string lista_palabras::iterator::operator *() const{
    return *it;
  }
  lista_palabras::iterator & lista_palabras::iterator::operator ++(){
    ++it;
    return *this;
  }
  bool lista_palabras::iterator::operator ==(const lista_palabras::iterator &i) const{
    return *this==i;
  }
  bool lista_palabras::iterator::operator !=(const lista_palabras::iterator &i) const{
    return *this!=i;
  }

lista_palabras::iterator lista_palabras::begin(){
  lista_palabras::iterator res;
  res.it=datos.begin();
  return res;
}

lista_palabras::iterator lista_palabras::end(){
  lista_palabras::iterator res;
  res.it=datos.end();
  return res;
}
