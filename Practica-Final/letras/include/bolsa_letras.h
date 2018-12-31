#ifndef BOLSA_LETRAS_H
#define BOLSA_LETRAS_H

#include "conjunto_letras.h"
#include <iostream>
#include <vector>

using namespace std;

class bolsa_letras{
private:
  vector<char> letras;
public:
  bolsa_letras();
  bolsa_letras(const conjunto_letras &C);
  vector<char> setAleatoria(const int &tam);
  friend ostream & operator<<(ostream & os, const bolsa_letras &B);
};
#endif
