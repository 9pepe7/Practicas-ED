#include "letra.h"
#include "conjunto_letras.h"
#include "bolsa_letras.h"
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
