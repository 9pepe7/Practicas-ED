#include "letra.h"
#include "conjunto_letras.h"
#include "bolsa_letras.h"
#include "lista_palabras.h"
#include <iostream>
#include <vector>
#include <set>
#include <stdio.h> // NULL
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <ctype.h> // toupper

using namespace std;

bolsa_letras::bolsa_letras(){}

bolsa_letras::bolsa_letras(const conjunto_letras &C){
  for(conjunto_letras::iterator it = C.begin(); it!=C.end(); ++it){
    for(int j=0; j<(*it).getCantidad(); ++j){
      letras.push_back((*it).getLetra());
    }
  }
}

void bolsa_letras::setAleatorias(const unsigned &tam){
  this->aleatorias.clear();
  if(tam <= letras.size()){
    vector<char> aux=this->letras;
    srand (time(NULL));
    for(unsigned i=0, random;i<tam;++i){
      random=rand()%aux.size();
      aleatorias.push_back(aux[random]);
      aux.erase(aux.begin()+random);
    }
  }
}

bool bolsa_letras::solucion_correcta(string pal) const{
  multiset<char> aux(this->aleatorias.begin(),this->aleatorias.end());
  for(unsigned i=0; i<pal.size(); ++i){
    pal[i]=toupper(pal[i]);
    multiset<char>::iterator it=aux.find(pal[i]);
    if(it==aux.end())
      return false;
    else
      aux.erase(it);
  }
  return true;
}

int bolsa_letras::PuntuacionP(const string &pal, const conjunto_letras &C) const{
  int res=0;
  for(unsigned i=0; i<pal.length(); ++i)
    res+=C.puntuacion(pal[i]);
  return res;
}

int bolsa_letras::PuntuacionL(const string &pal) const{
  return pal.length();
}

vector<string> bolsa_letras::maxPuntVectorPalabrasP(vector<string> v, const conjunto_letras &C, int &max){
  vector<string> tmp;
  max = 0;
  for(unsigned i = 0; i < v.size(); i++){
    if (C.puntuacion(v[i]) > max){
      max = C.puntuacion(v[i]);
      tmp.clear();
      tmp.push_back(v[i]);

    }
    if (C.puntuacion(v[i]) == max){
      tmp.push_back(v[i]);
    }
  }
  return tmp;
}

vector<string> bolsa_letras::maxPuntVectorPalabrasL(vector<string> v, int &max){
  vector<string> tmp;
  max = 0;
  for(int i = 0; i < v.size(); i++){
    if (v[i].size() > max){
      max = v[i].size();
      tmp.clear();
      tmp.push_back(v[i]);

    }
    if (v[i].size() == max){
      tmp.push_back(v[i]);
    }
  }
  return tmp;
}


vector<string> bolsa_letras::maxPuntListaP(const lista_palabras &lista, const conjunto_letras &C, int &max) const{
  vector<string> v = 0; //no estoy seguro de si inicializarlo así
  for(lista_palabras::iterator it = lista.begin(); it != lista.end(); ++it){
    if(solucion_correcta((*it))){
      v.push_back((*it));
    }
  }
  vector<string> tmp;
  tmp = maxPuntVectorPalabrasP(v, C, max);
  return tmp;
}

vector<string> bolsa_letras::maxPuntListaL(const lista_palabras &lista, int &max) const{
  vector<string> v = 0; //no estoy seguro de si inicializarlo así
  for(lista_palabras::iterator it = lista.begin(); it != lista.end(); ++it){
    if(solucion_correcta((*it))){
      v.push_back((*it));
    }
  }
  vector<string> tmp;
  tmp = maxPuntVectorPalabrasL(v, max);
  return tmp;
}

void bolsa_letras::pantallaAleatorias() const{
  for(unsigned i=0; i<aleatorias.size(); ++i)
    cout << aleatorias[i] << " ";
  cout << endl;
}

ostream & operator<<(ostream & os, const bolsa_letras &B){
  for(unsigned i=0; i<B.letras.size();++i)
    os << B.letras[i] << " ";
  os << endl;
  return os;
}
