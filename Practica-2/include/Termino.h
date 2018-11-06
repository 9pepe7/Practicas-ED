/**
  * @file Termino.h
  * @brief Fichero cabecera del TDA Termino
  *
  */
#ifndef TERMINO_H
#define TERMINO_H

#include <iostream>
#include "Vector_Dinamico.h"

using namespace std;

/**
  * @brief T.D.A. Termino
  *
  * Una instancia del tipo de datos abstracto Termino es un
  * objeto que contiene una palabra y todas sus definiciones.
  * Está compuesto por un string de la palabra en cuestion,
  * un vector que contiene las definiciones, y un entero
  * con el numero de definiciones.
  *
  * @author José Manuel Navarro Cuartero
  * @author Emilio Calvo de Mora Mármol
  * @date Octubre 2018
  */

class Termino {
private:
  string palabra; /**< La palabra que se define */
  Vector_Dinamico<string> definiciones; /**< Vector con sus definiciones */
  int tamanio; /**< Numero de definiciones alojadas en el termino */

public:

  /**
    * @brief Constructor por defecto de la clase.
    * @details Crea un término vacío, de tamaño 0.
    */
  Termino();

  /**
    * @brief Constructor por parámetros
    * @param pal Palabra
    * @param def Una definicion de la misma
    */
  Termino(string pal, string def);

  /**
    * @brief Constructor por parámetros
    * @param pal Palabra
    * @param vec Vector que contiene las definiciones
    */
  Termino(string pal, Vector_Dinamico<string> vec);

  /**
    * @brief Constructor por copia
    * @param original Termino del que se copia
    */
  Termino(const Termino& original);

  /**
    * @brief Devuelve la palabra
    * @return string con la palabra del objeto
    */
  string getPalabra() const;

  /**
    * @brief Devuelve las definiciones
    * @return Vector con todas las definiciones del termino
    */
  Vector_Dinamico<string> getDefiniciones() const;

  /**
    * @brief Devuelve una definicion indicada
    * @param i Indice de la definicion que se desea
    * @return La definicion
    * @pre El indice deberá ser válido, en caso contrario, se devuelve un string vacío
    */
  string getDefinicion(int i) const;

  /**
    * @brief Devuelve el numero de definiciones del termino
    * @return Un entero positivo con el nº de definiciones
    */
  int getTamanio() const;

  /**
    * @brief Asigna la palabra al termino
    * @param pal Palabra que se asigna
    */
  void setPalabra(string pal);

  /**
    * @brief Añade una definicion mas al termino
    * @param def Definicion que se añade
    */
  void AniadirDefinicion(string def);

  /**
    * @brief Operador de asignacion
    * @param ter El término al que se iguala
    * @return El término original modificado
    */
  Termino& operator=(const Termino& ter);

  /**
    * @brief Salida de un termino a ostream
    * @param out flujo de salida
    * @param ter Termino a escribir
    * @post Se envia al flujo la palabra, seguida de el índice de la definicion,
    *       y todas sus definiciones
    */
  friend ostream& operator<<(ostream & out, const Termino & ter);

  /**
    * @brief Entrada de un Termino desde istream
    * @param in Flujo de entrada
    * @param ter Termino que recibe los datos
    * @pre La entrada ha de usar un formato "palabra;definicion\n"
    * @details Se mofidica la palabra del termino, y se añade una definicion, que no
    *          tiene por qué ser su primera (aunque lo es en el uso que le damos)
    */
  friend istream& operator>>(istream & in, Termino & ter);

  /**
    * @brief Sobrecarga del operador ==
    * @param t1 Primer termino que se comparara
    * @param t2 Segundo termino que se compara
    * @return true si las palabras son iguales, false si no.
    * @details Solo compara las palabras de los terminos, no sus definiciones,
    *          y es sensible a mayusculas
    */
  friend bool operator==( const Termino& t1, const Termino& t2);

  /**
    * @brief Sobrecarga del operador <
    * @param t1 Primer termino que se comparara
    * @param t2 Segundo termino que se compara
    * @return true si la primera va antes alfabéticamente
    * @details Solo compara las palabras de los terminos, no sus definiciones,
    *          y es sensible a mayusculas
    */
  friend bool operator< ( const Termino& t1, const Termino& t2);

  /**
    * @brief Sobrecarga del operador >
    * @param t1 Primer termino que se comparara
    * @param t2 Segundo termino que se compara
    * @return true si la primera va despues alfabéticamente
    * @details Solo compara las palabras de los terminos, no sus definiciones,
    *          y es sensible a mayusculas
    */
  friend bool operator> ( const Termino& t1, const Termino& t2);
};

#endif
