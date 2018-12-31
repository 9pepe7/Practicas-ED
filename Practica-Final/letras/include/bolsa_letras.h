#ifndef BOLSA_LETRAS_H
#define BOLSA_LETRAS_H

#include "letra.h"
#include "conjunto_letras.h"
#include <iostream>
#include <vector>

using namespace std;

class bolsa_letras{
private:
  vector<char> letras;
public:
  bolsa_letras(const conjunto_letras &C){
    for(conjunto_letras::iterator it = C.begin(); it!=C.end(); ++it){
      for(int j=0; j<it->getCantidad();++j){
        letras.push_back(it->getLetra());
      }
    }
  }
  friend istream & operator>>(istream & is, bolsa_letras &B);
  friend ostream & operator<<(ostream & os, const bolsa_letras &B);
};
#endif
