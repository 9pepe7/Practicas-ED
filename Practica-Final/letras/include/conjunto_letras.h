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
  class iterator {
  private:
    set<letra>::iterator it;
  public:
    iterator ();
    letra operator *() const;
    iterator & operator ++();
    bool operator ==(const iterator &i) const;
    bool operator !=(const iterator &i) const;
    friend class conjunto_letras;
  };
  iterator begin() const;
  iterator end() const;
};
#endif
