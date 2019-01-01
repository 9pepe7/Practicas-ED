#include "letra.h"
#include "conjunto_letras.h"
#include "bolsa_letras.h"
#include <iostream>
#include <vector>
#include <stdio.h> // NULL
#include <stdlib.h> // srand, rand
#include <time.h> // time

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

void bolsa_letras::pantallaAleatorias(){
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
