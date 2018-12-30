#include "lista_palabras.h"
#include <set>

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

friend istream & operator>>(istream & is, lista_palabras &D){
  return is;
}

friend ostream & operator<<(ostream & os, const lista_palabras &D){
  return os;
}


  iterator::iterator (){}
  string iterator::operator *() const{
    return *it;
  }
  iterator & iterator::operator ++(){
    ++it;
    return it;
  }
  bool iterator::operator ==(const iterator &i) const{
    return it==i;
  }
  bool iterator::operator !=(const iterator &i) const{
    return it!=i;
  }

iterator lista_palabras::begin(){
  return datos.begin();
}

iterator lista_palabras::end(){
  return datos.end();
}
