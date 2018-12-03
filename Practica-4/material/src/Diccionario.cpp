#include <iostream>
#include "Termino.h"
#include "Diccionario.h"

using namespace std;

Diccionario::Diccionario();
Diccionario::Diccionario(set<Termino>);
Diccionario::Diccionario(Diccionario original);

vector<string> Diccionario::getDefiniciones() const;
set<Termino> Diccionario::getTerminos() const;
int Diccionario::getNumTerminos() const;

void Diccionario::aniadirTermino(Termino t);
void Diccionario::eliminarTermino(string pal);

Diccionario Diccionario::filtradoIntervalo(char ini, char fin) const;
Diccionario Diccionario::filtradoClave(string clave) const;

int Diccionario::totalDefininiciones() const;
int Diccionario::maxDefiniciones() const;
int Diccionario::promedioDefiniciones() const;

Diccionario::iterator Diccionario::begin();
Diccionario::const_iterator Diccionario::begin() const;
Diccionario::iterator Diccionario::end();
Diccionario::const_iterator Diccionario::end() const;

ostream& operator<< (ostream & os, const Diccionario & d){ // Esta viene en el pdf
  Diccionario::const_iterator it;
  for(it = d.begin(); it != d.end(); ++it){
    os << *it;
  }
  return os;
}
istream& operator>> (istream & is, Diccionario & d);
