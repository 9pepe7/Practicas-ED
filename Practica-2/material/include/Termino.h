#ifndef TERMINO_H
#define TERMINO_H

#include <iostream>
#include "Vector_Dinamico.h"

using namespace std;

class Termino {
private:
  string palabra;
  Vector_Dinamico<string> definiciones;
  int tamanio;
public:
  Termino();
  Termino(string pal, string def);
  Termino(const Termino& original);
  string getPalabra() const;
  Vector_Dinamico<string> getDefiniciones() const;
  string getDefinicion(int i) const;
  int getTamanio() const;
  void setPalabra(string pal);
  void AniadirDefinicion(string pal);

  Termino& operator=(const Termino& ter);

  friend ostream& operator<<(ostream & out, const Termino & ter);
  friend istream& operator>>(istream & in, Termino & ter);

  friend bool operator==( const Termino& t1, const Termino& t2);
  friend bool operator< ( const Termino& t1, const Termino& t2);
  friend bool operator> ( const Termino& t1, const Termino& t2);
};

#endif
