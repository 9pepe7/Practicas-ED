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
  void setAleatorias(const unsigned &tam); // NO SÉ POR QUÉ NO PUEDO HACER const ÉSTA
  bool solucion_correcta(string pal) const;
  unsigned puntuacionP(const string &pal, const conjunto_letras &C) const;
  unsigned puntuacionL(const string &pal) const;
  vector<string> solucionesP(const lista_palabras &L, const conjunto_letras &C) const;
  vector<string> solucionesL(const lista_palabras &L) const;
  void pantallaAleatorias() const;
  friend ostream & operator<<(ostream & os, const bolsa_letras &B);
};
#endif
