#ifndef CONJUNTO_LETRAS_H
#define CONJUNTO_LETRAS_H

#include "letra.h"
#include <iostream>
#include <set>

using namespace std;

class conjunto_letras{
private:
  set<letra> letras;
public:
  conjunto_letras();
  friend istream & operator>>(istream & is, conjunto_letras &C);
  friend ostream & operator<<(ostream & os, const conjunto_letras &C);
};
#endif
