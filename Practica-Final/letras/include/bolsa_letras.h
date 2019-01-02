#ifndef BOLSA_LETRAS_H
#define BOLSA_LETRAS_H

#include "conjunto_letras.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class bolsa_letras{
private:
  vector<char> letras;
  vector<char> aleatorias;
public:
  bolsa_letras();
  bolsa_letras(const conjunto_letras &C);
  void setAleatorias(const unsigned &tam);
  bool solucion_correcta(string pal) const;
  int PuntuacionP(const string &pal, const conjunto_letras &C) const;
  int PuntuacionL(const string &pal) const;
  void pantallaAleatorias() const;
  friend ostream & operator<<(ostream & os, const bolsa_letras &B);
};
#endif
