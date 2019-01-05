#ifndef CONJUNTO_LETRAS_H
#define CONJUNTO_LETRAS_H

#include "letra.h"
#include <iostream>
#include <set>

using namespace std;

/**
  * @brief T.D.A. CONJUNTO_LETRAS
  *
  * Una instancia del TDA conjunto_letras es un objeto que contiene un set de
  * objetos del TDA letra
  *
  * @author José Manuel Navarro Cuartero
  * @author Emilio Calvo de Mora Mármol
  * @date Enero 2019
  */

class conjunto_letras{
private:

  /**
   * @page repConjunto_letras Rep del TDA conjunto_letras
   *
   *
   * @section funcConjunto_letras Funcion de Abstracción
   *
   * Un objeto del TDA conjunto_letras representa una serie de elementos del TDA letras agrupados
   *
   */
  set<letra> letras;  /**< Set de elementos del TDA letra */
public:
  typedef set<letra>::iterator iterator;  /**< Iterador de la clase basado en el tipo set subyacente */
  typedef set<letra>::const_iterator const_iterator;  /**< Iterador constante de la clase basado en el tipo set subyacente */

  /**
    * @brief Constructor por defecto de la clase.
    * @details Crea un conjunto de letras vacío.
    */
  conjunto_letras();

  /**
    * @brief Método para sacar por pantalla las puntuaciones del conjunto de letras
    */
  void pantallaPuntuaciones() const;

  /**
    * @brief Método que da la puntuación de un carácter en específico
    * @param c carácter a consultar por su puntuación
    * @return Entero con la puntuación de dicha letra
    */
  int puntuacion(const char &c) const;

  /**
    * @brief Sobrecarga del operador de lectura
    * @param is flujo de entrada
    * @param C conjunto de letras que recibe el flujo
    * @return El flujo de entrada
    */
  friend istream & operator>>(istream & is, conjunto_letras &C);

  /**
    * @brief Sobrecarga del operador de escritura
    * @param os flujo de salida
    * @param C conjunto de letras cuyo contenido se saca por el flujo
    * @return El flujo de salida
    */
  friend ostream & operator<<(ostream & os, const conjunto_letras &C);

  /**
    * @brief Definicion de la funcion begin del iterador de la clase conjunto_letras
    * @return Iterador que apunta al inicio del set del letras
    */
  conjunto_letras::iterator begin();

  /**
    * @brief Definicion de la funcion begin del iterador constante de la clase conjunto_letras
    * @return Iterador constante que apunta al inicio del set del letras
    */
  conjunto_letras::const_iterator begin() const;

  /**
    * @brief Definicion de la funcion end del iterador de la clase conjunto_letras
    * @return Iterador que apunta al final del set del letras
    */
  conjunto_letras::iterator end();

  /**
    * @brief Definicion de la funcion end del iterador constante de la clase conjunto_letras
    * @return Iterador constante que apunta al final del set del letras
    */
  conjunto_letras::const_iterator end() const;
private:

  /**
    * @brief Método que encuentra un carácter en el conjunto de letras
    * @return Iterador de la posición donde se encuentra la letra cuyo carácter coincide con c
    */
  conjunto_letras::iterator find(const char &c) const;
};
#endif
