/**
  * @file Diccionario.h
  * @brief Fichero cabecera del TDA diccionario
  *
  */

#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <iostream>
#include <vector>
#include <string>
#include "Termino.h"
#include <set>

using namespace std;

/**
  * @brief T.D.A. Diccionario
  *
  * Una instancia del tipo de datos abstracto Diccionario es un objeto
  * que contiene set de la stl de términos del T.D.A. Termino, incluido en
  * este archivo mediante el include "Termino.h".
  * Lo representamos como una lista  ordenada alfabéticamente con todos los Terminos.
  *
  *
  * @author José Manuel Navarro Cuartero
  * @author Emilio Calvo de Mora Mármol
  * @date Diciembre 2018
  */

class Diccionario{
private:
  /**
    * @page repDiccionario Rep del TDA Diccionario
    *
    * @section invDiccionario Invariante de la representación
    *
    * El invariante es que sus terminos, de existir, estarán siempre ordenados, y no podrán existir dos Terminos con la misma palabra.
    *
    * @section funcDiccionario  Funcion de Abstracción
    *
    * Un objeto de nuestro TDA Diccionario representa un conjunto de terminos de tipo Termino ordenados alfabéticamente
    *
    */
  set<Termino> dicc; /**< Set con los terminos ordenados alfabeticamente */

public:
  Diccionario();
  Diccionario(set<Termino> dic);
  Diccionario(const Diccionario &original);

  typedef set<Termino>::iterator iterator; /**< Iterador de la clase basado en el tipo set subyacente */
  typedef set<Termino>::const_iterator const_iterator; /**< Iterador constante de la clase basado en el tipo set subyacente */

  vector<string> getDefiniciones(string pal) const;
  set<Termino> getTerminos() const;
  int getNumTerminos() const;

  void aniadirTermino(Termino t);
  void eliminarTermino(Termino t);
  void eliminarTermino(Diccionario::iterator it);
  Diccionario::const_iterator findTermino(string pal) const;
  Diccionario::const_iterator findTermino(Termino t) const;

  Diccionario filtradoIntervalo(char ini, char fin) const;
  Diccionario filtradoClave(string clave) const;

  int totalDefininiciones() const;
  int maxDefiniciones() const;
  string maxPal(int = 0) const;
  double promedioDefiniciones() const;
  bool sonletras(const char &c1, const char &c2) const;

  Diccionario::iterator begin();
  Diccionario::const_iterator begin() const;
  Diccionario::iterator end();
  Diccionario::const_iterator end() const;

  friend ostream& operator<< (ostream & os, const Diccionario & d);
  friend istream& operator>> (istream & is, Diccionario & d);
};

#endif
