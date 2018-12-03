/**
  * @file Diccionario.h
  * @brief Fichero cabecera del TDA diccionario
  *
  */

#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <iostream>
#include "Termino.h"
#include <set>

using namespace std;

/**
  *  @brief T.D.A. Diccionario
  *
  * Una instancia del tipo de datos abstracto Diccionario es un objeto
  * que contiene set de la stl de términos del T.D.A. Termino, incluido en
  * este archivo mediante el include "Termino.h".
  * Lo representamos como una lista  ordenada alfabéticamente con todos los Terminos.
  *
  *
  * @author Jose Manuel Navarro Cuartero
  * @author Emilio Calvo de Mora Mármol
  * @date Diciembre 2018
  */

class Diccionario{
  Diccionario();
  Diccionario(set<Termino>);
  Diccionario(Diccionario original);

  vector<string> getDefiniciones();
  set<Termino> getTerminos();
  int getNumTerminos();

  void aniadirTermino(Termino t);
  void eliminarTermino(string pal);

  Diccionario filtradoIntervalo(char ini, char fin);
  Diccionario filtradoClave(string clave);

  int totalDefininiciones();
  int maxDefiniciones();
  int promedioDefiniciones();

  typedef set<Termino>::iterator iterator;
  typedef set<Termino>::const_iterator const_iterator;
  Diccionario::iterator begin();
  Diccionario::const_iterator begin() const;
  Diccionario::iterator end();
  Diccionario::const_iterator end() const;

  friend ostream& operator<< (ostream & os, const Diccionario & d);
  friend istream& operator>> (istream & is, Diccionario & d);
};

#endif
