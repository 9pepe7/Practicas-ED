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
    * @param pal Palabra que identifica al termino
    * @param def Vector de definiciones derl termino
    */
  Termino(const string &pal, const vector<string> &def);

  /**
    * @brief Constructor por copia
    * @param original Termino que se copia
    */
  Termino(const Termino &original);

  /**
    * @brief Devuelve la palabra que identifica al termino
    * @return La palabra del termino
    */
  string getPalabra() const;

  /**
    * @brief Devuelve las definiciones de un termino
    * @return Vector con las definiciones del termino
    */
  vector<string> getDefiniciones() const;

  /**
    * @brief Devuelve el numero de definiciones que tiene el termino
    * @return Entero no negativo con el numero de definiciones
    */
  int getNumDef() const;

  /**
    * @brief Devuelve la primera definicion de un termino
    * @return string Dicha definicion
    * @details Si no hubiera definiciones en el termino,
    * devuelve un string vacio
    */
  string getDefinicion() const;

  /**
    * @brief Devuelve la letra inicial de un termino
    * @return Un caracter con la letra
    * @details Si el termino no tuviera palabra que lo
    * identifique todavía, se devuelve el caracter ' '
    */
  char getInicial() const;

  /**
    * @brief Asigna una palabra al termino
    * @param pal Palabra que es asignada
    */
  void setPalabra(const string &pal);

  /**
    * @brief Añade una definicion al termino
    * @param def Definicion que se añade
    * @details A priori no hay límite en cuántas
    * definiciones puede tener un término.
    */
  void aniadirDefinicion(const string &def);

  typedef vector<string>::iterator iterator; /**< Iterador de la clase basado en el tipo vector subyacente */
  typedef vector<string>::const_iterator const_iterator; /**< Iterador constante de la clase basado en el tipo vector subyacente */

  /**
    * @brief Definicion de la funcion begin del iterador de la clase Termino
    * @return Iterador que apunta al inicio del vector de definiciones
    */
  Termino::iterator begin();

  /**
    * @brief Definicion de la funcion begin del iterador constante de la clase Termino
    * @return Iterador constante que apunta al inicio del vector de definiciones
    */
  Termino::const_iterator begin() const;

  /**
    * @brief Definicion de la funcion end del iterador de la clase Termino
    * @return Iterador que apunta al final del vector de definiciones
    */
  Termino::iterator end();

  /**
    * @brief Definicion de la funcion endº del iterador constante de la clase Termino
    * @return Iterador constante que apunta al final del vector de definiciones
    */
  Termino::const_iterator end() const;

/**
  * @brief Sobrecarga del operador de escritura
  * @param os flujo de salida
  * @param t Termino a describir en el flujo
  * @return El flujo de salida
  */
  friend ostream& operator<< (ostream & os, const Termino & t);

/**
  * @brief Sobrecarga del operador de lectura
  * @param is flujo de entrada
  * @param t Termino que recibe los datos desde el flujo
  * @return El flujo de entrada
  */
  friend istream& operator>> (istream & is, Termino & t);

/**
  * @brief Sobrecarga del operador <
  * @param t Termino que se compara con el objeto que llama al metodo
  * @return bool true si el objeto que llama al metodo esta antes alfabeticamente que t, false si no
  * @details A priori no se dará el caso de dos terminos iguales, es decir,
  * que las palabras que los definen sean las mismas.
  */
  bool operator< (const Termino &t) const;
};

#endif
