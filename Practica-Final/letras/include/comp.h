/**
  * @file comp.h
  * @brief Fichero cabecera del struct comp
  *
  */
#ifndef COMP_H
#define COMP_H

#include <string>

using namespace std;

/**
  * @brief struct comp
  *
  * Esta estructura sirve para determinar un orden alfabético entre caracteres añadiendo la ñ,
  * que no existe como tal para el operador de char sin sobrecargar "<"
  *
  * @author José Manuel Navarro Cuartero
  * @author Emilio Calvo de Mora Mármol
  * @date Enero 2019
  */
struct comp{

  /**
    * @page repcomp Rep de la estructura COMP
    */

  /**
    * @brief Compara dos letras con respecto a su orden alfabético
    * @param c1 primer carácter a comparar
    * @param c2 segundo carácter a comparar
    * @return Booleano true si c1 es alfabeticamente anterior a c2, false si al contrario
    * @pre Los caracteres serán letras, mayúsculas o minúsculas
    */
  bool menor(const char& c1, const char& c2) const;

  /**
    * @brief Sobrecarga del operador (), para comparar alfabeticamente dos palabras
    * @param pal1 primera palabra a comparar
    * @param pal2 segunda palabra a comparar
    * @return Booleano true si pal1 es alfabéticamente anterior a pal2, false si al contrario
    * @pre Las palabras estarán solo formadas por letras, sin signos de puntuación o espacios
    */
  bool operator() (const string& pal1, const string& pal2) const;

  /**
    * @brief Sobrecarga del operador (), para comparar alfabeticamente dos letras
    * @param c1 primer carácter a comparar
    * @param c2 segundo carácter a comparar
    * @return Booleano true si c1 es alfabéticamente anterior a c2, false si al contrario
    * @pre Los caracteres serán letras, mayúsculas o minúsculas
    */
  bool operator() (const char& c1, const char& c2) const;
};
#endif
