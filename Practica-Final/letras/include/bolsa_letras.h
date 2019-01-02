#ifndef BOLSA_LETRAS_H
#define BOLSA_LETRAS_H

#include "letra.h"
#include "conjunto_letras.h"
#include "lista_palabras.h"
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
  unsigned PuntuacionP(const string &pal, const conjunto_letras &C) const;
  unsigned PuntuacionL(const string &pal) const;
  vector<string> maxPuntVectorPalabrasP(vector<string> v, const conjunto_letras &C, unsigned &max);
  vector<string> maxPuntVectorPalabrasL(vector<string> v, unsigned &max);
  vector<string> maxPuntListaP(const lista_palabras &lista, const conjunto_letras &C, unsigned &max);
  vector<string> maxPuntListaL(const lista_palabras &lista, unsigned &max);
  void pantallaAleatorias() const;
  friend ostream & operator<<(ostream & os, const bolsa_letras &B);
};
#endif
