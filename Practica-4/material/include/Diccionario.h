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

  /**
    * @brief Constructor por defecto de la clase. Crea el diccionario vacío
    */
  Diccionario();

 /**
   * @brief Constructor de la clase
   * @param vec El vector dinámico de Terminos que copiar en el vector de Terminos
   * @return Crea el diccionario con los Terminos de Vector_Dinamico<Termino>
   */
  Diccionario(set<Termino> dic);

  /**
    * @brief Constructor de copias de la clase Diccionario
    * @param original Diccionario a copiar en el nuevo objeto Diccionario
    */
  Diccionario(const Diccionario &original);

  typedef set<Termino>::iterator iterator;             /**< Iterador de la clase basado en el tipo set subyacente */
  typedef set<Termino>::const_iterator const_iterator; /**< Iterador constante de la clase basado en el tipo set subyacente */

  /**
    * @brief Definiciones relacionadas con la palabra pal
    * @param pal String con la palabra cuyas definiciones se buscan
    * @return Devuelve el vector dinámico de definiciones del Termino cuya palabra es p
    */
  vector<string> getDefiniciones(string pal) const;

  /**
    * @brief Todos los terminos del diccionario
    * @return set<Termino> Devuelve un set de tipos Termino con todos los terminos del diccionario
    */
  set<Termino> getTerminos() const;

  /**
    * @brief Número de términos del diccionario
    * @return int Devuelve el número de terminos del diccionario
    */
  int getNumTerminos() const;

  /**
    * @brief Añade un Termino nuevo t al diccionario
    * @param t Termino a añadir al diccionario
    */
  void aniadirTermino(Termino t);

  /**
    * @brief Elimina un termino del diccionario
    * @param t El Termino a eliminar en el diccionario
    */
  void eliminarTermino(Termino t);

  /**
    * @brief Elimina un termino del una posición it del diccionario
    * @param it Iterador del termino que se desea eliminar
    */
  void eliminarTermino(Diccionario::iterator it);

  /**
    * @brief Busca en el diccionario el termino cuya palabra coincide con pal
    * @param string pal la palabra que se busca en el Diccionario
    * @return Diccionario::const_iterator posición del diccionario del termino cuya palabra coincide con pal
    */
  Diccionario::const_iterator findTermino(string pal) const;

  /**
    * @brief Busca en el diccionario el termino t
    * @param Termino t el termino que se busca en el Diccionario
    * @return Diccionario::const_iterator posición del diccionario del termino que coincide con t
    */
  Diccionario::const_iterator findTermino(Termino t) const;

  Diccionario filtradoIntervalo(char ini, char fin) const;
  Diccionario filtradoClave(string clave) const;

  void estadisticas(int &totaldef, int &maxdef, string &maxpal) const;

  /**
    * @brief El promedio de definiciones por cada palabra del diccionario
    * @return double Devuelve el valor del promedio de definiciones por palabra de un solo diccionario
    */
  double promedioDefiniciones() const;

  /**
    * @brief Función que determina si dos caracteres c1 y c2 son letras del abecedario
    *
    * @param char &c1 caracter primero
    *
    * @param char &c2 caracter segundo
    *
    * @return bool Devuelve true si ambos caracteres c1 y c2 son letras
    */
  bool sonletras(const char &c1, const char &c2) const;

  /**
    * @brief Definicion de la funcion begin del iterador de la clase Diccionario
    * @return iterator El iterador que apunta al inicio del set de terminos
    */
  Diccionario::iterator begin();

  /**
    * @brief Definicion de la funcion begin del iterador constante de la clase Diccionario
    * @return iterator El iterador constante que apunta al inicio del set de terminos
    */
  Diccionario::const_iterator begin() const;

  /**
    * @brief Definicion de la funcion end del iterador de la clase Diccionario
    * @return iterator El iterador que apunta al final del set de terminos
    */
  Diccionario::iterator end();

  /**
    * @brief Definicion de la funcion end del iterador constante de la clase Diccionario
    * @return iterator El iterador constante que apunta al final del set de terminos
    */
  Diccionario::const_iterator end() const;


  /**
    * @brief Salida de un diccionario por flujo de salida ostream
    * @param os flujo stream de salida
    * @param d Diccionario que se saca por el flujo
    */
  friend ostream& operator<< (ostream & os, const Diccionario & d);

  /**
    * @brief Entrada de un diccionario desde istream
    * @param is flujo de entrada
    * @param d El diccionario que recibe los datos del flujo de entrada
    * @retval El diccionario recibido por flujo
    */
  friend istream& operator>> (istream & is, Diccionario & d);

private:
  /**
    * @brief Hace un recuento de la cantidad de definiciones que tiene el diccionario
    * @return int El número de total definiciones que tiene el diccionario
    */
  int totalDefininiciones() const;

  /**
    * @brief El máximo de definiciones que tiene un único Termino del diccionario
    * @return int Devuelve el número máximo de definiciones que acumula un único Termino del diccionario
    */
  int maxDefiniciones() const;
  string maxPal(int = 0) const;

};

#endif
