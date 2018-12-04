/**
  * @file Termino.h
  * @brief Fichero cabecera del TDA Termino
  *
  */

#ifndef TERMINO_H
#define TERMINO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
  * @brief T.D.A. Termino
  *
  * Una instancia del tipo de datos abstracto Termino es un
  * objeto que contiene una palabra y todas sus definiciones.
  * Está compuesto por un par con la palabra en cuestion por un lado, y
  * un vector que contiene las definiciones por el otro.
  *
  * @author José Manuel Navarro Cuartero
  * @author Emilio Calvo de Mora Mármol
  * @date Diciembre 2018
  */

class Termino {
private:
  pair<string,vector<string>> termino; /**< Par con la palabra y un vector con sus definiciones */

public:
  Termino();
  Termino(string pal, vector<string> def);
  Termino(const Termino &original);

  string getPalabra() const;
  vector<string> getDefiniciones() const;
  int getNumDef() const;
  string getDefinicion() const;
  char getInicial() const;

  void setPalabra(string pal);
  void aniadirDefinicion(string def);

  typedef vector<string>::iterator iterator;
  typedef vector<string>::const_iterator const_iterator;
  Termino::iterator begin();
  Termino::const_iterator begin() const;
  Termino::iterator end();
  Termino::const_iterator end() const;

  friend ostream& operator<< (ostream & os, const Termino & t);
  friend istream& operator>> (istream & is, Termino & t);
  bool operator< (const Termino &t) const;
};

#endif
