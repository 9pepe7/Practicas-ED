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
    * @brief Constructor por defecto de la clase.
    * @return Crea el diccionario vacío
    */
  Diccionario();

 /**
   * @brief Constructor por parametros de la clase
   * @param dic El set de Terminos a partir del que crear el nuevo diccionario
   * @return Crea el diccionario con los Terminos contenidos en dic
   */
  Diccionario(const set<Termino> &dic);

  /**
    * @brief Constructor por copia de la clase Diccionario
    * @param original Diccionario a copiar en el nuevo objeto Diccionario
    * @return Crea el diccionario copia de original
    */
  Diccionario(const Diccionario &original);

  typedef set<Termino>::iterator iterator;             /**< Iterador de la clase basado en el tipo set subyacente */
  typedef set<Termino>::const_iterator const_iterator; /**< Iterador constante de la clase basado en el tipo set subyacente */

  /**
    * @brief Busqueda de todas las definiciones asociadas a pal
    * @param pal String con la palabra cuyas definiciones se buscan
    * @return Un vector de definiciones del Termino cuya palabra es pal
    * @details Si la palabra no se encuentra en el dicionario, el vector estará vacío
    */
  vector<string> getDefiniciones(const string &pal) const;

  /**
    * @brief Funcion que retorna todos los terminos del diccionario
    * @return Un set con todos los terminos del diccionario
    */
  set<Termino> getTerminos() const;

  /**
    * @brief Recuento del número de términos del diccionario
    * @return El número de terminos contenidos en el diccionario
    */
  int getNumTerminos() const;

  /**
    * @brief Añade un Termino nuevo t al diccionario
    * @param t Termino a añadir al diccionario
    * @pre El termino debería ser correcto (tener palabra y alguna definición)
    */
  void aniadirTermino(const Termino &t);

  /**
    * @brief Elimina un termino del diccionario
    * @param t El Termino a eliminar en el diccionario
    * @details Si el termino no estuviera contenido en el diccionario, no se borra nada
    */
  void eliminarTermino(const Termino &t);

  /**
    * @brief Elimina un termino del una posición it del diccionario
    * @param it Iterador del termino que se desea eliminar
    * @details Si el termino no estuviera contenido en el diccionario, no se borra nada
    */
  void eliminarTermino(Diccionario::iterator it);

  /**
    * @brief Busca en el diccionario el termino cuya palabra coincide con pal
    * @param pal la palabra que se busca en el Diccionario
    * @return Un iterador con la posición del termino cuya palabra coincide con pal
    * @details Si no se encontrase, se devuelve end()
    */
  Diccionario::const_iterator findTermino(const string &pal) const;

  /**
    * @brief Busca en el diccionario el termino t
    * @param t El termino que se busca en el Diccionario
    * @return Iterador del termino que coincide con t
    * @details Si no se encontrase, se devuelve end()
    */
  Diccionario::const_iterator findTermino(const Termino &t) const;

  /**
    * @brief Subdiccionario contenido entre dos iniciales
    * @param ini Primera inicial
    * @param fin Segunda inicial
    * @return Subdiccionario resultado del filtrado
    * @pre Los argumentos deben ser letras
    * @details El subdiccionatio contendrá todos los terminos (si los hubiera),
    * cuya inicial se encuentre entre las dos dadas como argumentos, ambas inclusive.
    */
  Diccionario filtradoIntervalo(char ini, char fin) const;

  /**
    * @brief Subdiccionario con todas las definiciones que contienen una clave
    * @param clave Palabra a buscar en las definiciones
    * @return Subdiccionario resultado del filtrado
    * @details El subdiccionatio contendrá todos las definiciones (si las hubiera),
    * junto con sus respectivas palabras, que contengan la clave que se busca.
    */
  Diccionario filtradoClave(const string &clave) const;

  /**
    * @brief Estadísticas adicionales del diccionario
    * @param totaldef Entero con el numero total de definiciones guardadas
    * @param maxdef Entero con el maximo de definiciones de una sola palabra almacenada
    * @param maxpal Palabra con el mayor numero de definiciones
    * @pre El diccionario ha de tener al menos 1 término
    * @details Usaremos esta función en lugar de las privadas totalDefininiciones(),
    * maxDefiniciones() y maxPal(), ya qque es más eficiente si se pretende usar las
    * 3 seguidas, hacerlo todo de golpe.
    */
  void estadisticas(int &totaldef, int &maxdef, string &maxpal) const;

  /**
    * @brief El promedio de definiciones por palabra del diccionario
    * @return El valor del promedio de definiciones por palabra del diccionario
    */
  double promedioDefiniciones() const;

  /**
    * @brief Función que determina si dos caracteres c1 y c2 son letras del abecedario
    * @param c1 Primera letra
    * @param c2 Segunda letra
    * @return true si ambos caracteres c1 y c2 son letras
    */
  bool sonletras(const char &c1, const char &c2) const;

  /**
    * @brief Definicion de la funcion begin del iterador de la clase Diccionario
    * @return Iterador que apunta al inicio del set de terminos
    */
  Diccionario::iterator begin();

  /**
    * @brief Definicion de la funcion begin del iterador constante de la clase Diccionario
    * @return Iterador constante que apunta al inicio del set de terminos
    */
  Diccionario::const_iterator begin() const;

  /**
    * @brief Definicion de la funcion end del iterador de la clase Diccionario
    * @return Iterador que apunta al final del set de terminos
    */
  Diccionario::iterator end();

  /**
    * @brief Definicion de la funcion end del iterador constante de la clase Diccionario
    * @return Iterador constante que apunta al final del set de terminos
    */
  Diccionario::const_iterator end() const;


  /**
    * @brief Sobrecarga del operador de escritura
    * @param os flujo de salida
    * @param d Diccionario que se saca por el flujo
    * @return El flujo de salida
    */
  friend ostream& operator<< (ostream & os, const Diccionario & d);

  /**
    * @brief Sobrecarga del operador de lectura
    * @param is flujo de entrada
    * @param d El diccionario que recibe los datos del flujo de entrada
    * @return El flujo de entrada
    */
  friend istream& operator>> (istream & is, Diccionario & d);

private:

  /**
    * @brief Recuento del total de definiciones que tiene el diccionario
    * @return El número de total definiciones que tiene el diccionario
    */
  int totalDefininiciones() const;

  /**
    * @brief El máximo de definiciones que tiene cualquier Termino del diccionario
    * @return El número máximo de definiciones que acumula un único Termino del diccionario
    * @details Puede haber empate entre varios terminos
    */
  int maxDefiniciones() const;

  /**
    * @brief Busqueda de la palabra con más definiciones
    * @param x Cota inferior del numero de definiciones a buscar
    * @return La palabra con un numero de definiciones mayor
    * @details Si hubiera varias palabras que coincidan,
    * se devuelve la primera de ellas alfabéticamente.
    */
  string maxPal(int x = 0) const;

};

#endif
