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
  typedef set<letra>::iterator iterator;
  typedef set<letra>::const_iterator const_iterator;
  conjunto_letras();
  void pantallaPuntuaciones() const;
  int puntuacion(const char &c) const;
  friend istream & operator>>(istream & is, conjunto_letras &C);
  friend ostream & operator<<(ostream & os, const conjunto_letras &C);
  conjunto_letras::iterator begin();
  conjunto_letras::const_iterator begin() const;
  conjunto_letras::iterator end();
  conjunto_letras::const_iterator end() const;
private:
  conjunto_letras::iterator find(const char &c) const;
};
#endif
