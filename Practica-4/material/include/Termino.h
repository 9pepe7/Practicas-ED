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
  /**
   * @page repTermino Rep del TDA Termino
   *
   * @section invTermino Invariante de la representación
   *
   * El invariante es que para cada Termino, existe una palabra y una definición, al menos.
   *
   *
   * @section funcTermino  Funcion de Abstracción
   *
   * Un objeto de nuestro TDA Termino representa una palabra y una o más definiciones asociadas a la misma.
   *
   */
  pair<string,vector<string>> termino; /**< Par con la palabra y un vector con sus definiciones */

public:
  /**
    * @brief Constructor por defecto de la clase.
    * @details Crea un término vacío.
    */
  Termino();

  /**
    * @brief Constructor por parámetros
    * @param pal Palabra
    * @param def Vector de definiciones
    */
  Termino(string pal, vector<string> def);

  /**
    * @brief Constructor por copia
    * @param Original Termino que se copia
    */
  Termino(const Termino &original);

  /**
    * @brief Devuelve la palabra
    * @return string La palabra del termino
    */
  string getPalabra() const;

  /**
    * @brief Devuelve las definiciones de un termino
    * @return Vector con las definiciones del termino
    */
  vector<string> getDefiniciones() const;

  /**
    * @brief Devuelve el numero de definiciones que tiene el termino
    * @return Un entero positivo con el numero de definiciones
    */
  int getNumDef() const;

  /**
    * @brief Devuelve la primera definicion de un termino
    * @return string Dicha definicion
    */
  string getDefinicion() const;

  /**
    * @brief Devuelve la letra inicial de un termino
    * @return char Dicha letra
    */
  char getInicial() const;

  /**
    * @brief Asigna una palabra pal al termino
    * @param pal Palabra que es asignada
    */
  void setPalabra(string pal);

  /**
    * @brief Añade una definicion al termino
    * @param def Definicion que se añade
    */
  void aniadirDefinicion(string def);

  typedef vector<string>::iterator iterator; /**< Iterador de la clase basado en el tipo vector subyacente */
  typedef vector<string>::const_iterator const_iterator; /**< Iterador constante de la clase basado en el tipo vector subyacente */

  /**
    * @brief Definicion de la funcion begin del iterador de la clase Termino
    * @return iterator El iterador que apunta al inicio del vector de definiciones
    */
  Termino::iterator begin();

  /**
    * @brief Definicion de la funcion begin del iterador constante de la clase Termino
    * @return const_iterator El iterador que apunta al inicio del vector de definiciones
    */
  Termino::const_iterator begin() const;

  /**
    * @brief Definicion de la funcion end del iterador de la clase Termino
    * @return iterator El iterador que apunta al final del vector de definiciones
    */
  Termino::iterator end();

  /**
    * @brief Definicion de la funcion endº del iterador constante de la clase Termino
    * @return const_iterator El iterador que apunta al final del vector de definiciones
    */
  Termino::const_iterator end() const;

/**
  * @brief Salida de un termino a ostream
  * @param os flujo de salida
  * @param t Termino a escribir en el flujo
  */
  friend ostream& operator<< (ostream & os, const Termino & t);

/**
  * @brief Entrada de un termino desde istream
  * @param in flujo de salida
  * @param t Termino que recibe los datos desde el flujo
  */
  friend istream& operator>> (istream & is, Termino & t);

/**
  * @brief Sobrecarga del operador <
  * @param t Termino que se compara con el objeto que llama al metodo
  * @return bool true si t es mayor de orden que el objeto que llama al metodo, false si lo contrario
  */
  bool operator< (const Termino &t) const;
};

#endif
