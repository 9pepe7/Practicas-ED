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
vector<char> bolsa_letras::setAleatoria(const int &tam){
  vector<char> res;
  if(tam <= letras.size()){
    srand (time(NULL));
    for(int i=0, aux;i<tam;++i){
      aux=rand()%letras.size();
      res.insert(letras[aux]);
    }
  }
  return res;
}
ostream & operator<<(ostream & os, const bolsa_letras &B){
  for(int i=0; i<B.letras.size();++i)
    os << B.letras[i] << " ";
  os << endl;
  return os;
}
