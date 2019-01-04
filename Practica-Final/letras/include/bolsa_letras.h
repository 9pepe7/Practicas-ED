#ifndef BOLSA_LETRAS_H
#define BOLSA_LETRAS_H

#include "letra.h"
#include "conjunto_letras.h"
#include "lista_palabras.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
  * @brief T.D.A. BOLSA_LETRAS
  *
  * Una instancia del TDA bolsa_letras es un objeto que contiene dos vectores de caracteres en los
  * los que uno es un conjunto de caracteres sacado de una serie de elementos del TDA letras,
  * y el otro es la aleatorización del primero
  *
  * @author José Manuel Navarro Cuartero
  * @author Emilio Calvo de Mora Mármol
  * @date Enero 2019
  */
class bolsa_letras{
private:

/**
  * @page repLetra Rep del TDA bolsa_letras
  *
  * @section funcBolsa_letras  Funcion de Abstracción
  *
  * Un objeto del TDA bolsa_letras representa un conjunto de letras y otro de letras aleatorizadas
  *
  */
  vector<char> letras;  /**< Vector de caracteres con las letras de juego */
  vector<char> aleatorias;  /**< Vector de caracteres con las letras aleatorias*/
public:

  /**
    * @brief Constructor por defecto de la clase.
    * @details Crea una bolsa de letras vacía.
    */
  bolsa_letras();

  /**
    * @brief Constructor con parámetros desde un conjunto de letras de la clase.
    * @param C Conjunto de letras del que se sacan las letras con las que se juega
    * @details Solo se copian los caracteres al vector de caracteres letras
    */
  bolsa_letras(const conjunto_letras &C);

  /**
    * @brief Método que permite darle valores al vector de aleatorias
    * @param tam tamaño del vector de aleatorias
    * @details Se eligen tam letras del vector miembro letras y se almacenan en aleatorias
    */
  void setAleatorias(const unsigned &tam);

  /**
    * @brief Método que comprueba si una palabra es solución del vector de aleatorias
    * @param pal palabra que se comprueba si es solución
    * @details Solo se copian los caracteres al vector de caracteres letras
    * @return booleano true si es solución correcta, false si no
    */
  bool solucion_correcta(string pal) const;

  /**
    * @brief Método que devuelve la puntuación en el modo P de una palabra
    * @param C Conjunto de letras del que se sacan las puntuaciones
    * @param pal La palabra cuya puntuación P se desea saber
    * @return entero sin signo con la puntuación P de la palabra
    */
  unsigned puntuacionP(const string &pal, const conjunto_letras &C) const;

  /**
    * @brief Método que devuelve la puntuación en el modo L de una palabra
    * @param pal La palabra cuya puntuación L se desea saber
    * @return entero sin signo con la puntuación L de la palabra
    */
  unsigned puntuacionL(const string &pal) const;

  /**
    * @brief Método que devuelve un vector de string con las palabras de lista_palabras que son solución P
    * @param C Conjunto de letras del que se sacan las puntuaciones
    * @param L La lista de palabras del que se sacan las soluciones P
    * @return vector de strings con las soluciones P
    */
  vector<string> solucionesP(const lista_palabras &L, const conjunto_letras &C) const;

  /**
    * @brief Método que devuelve un vector de string con las palabras de lista_palabras que son solución L
    * @param L La lista de palabras del que se sacan las soluciones L
    * @return vector de strings con las soluciones L
    */
  vector<string> solucionesL(const lista_palabras &L) const;

  /**
    * @brief Método que saca por pantalla el vector de aleatorias
    */
  void pantallaAleatorias() const;

  /**
    * @brief Sobrecarga del operador de escritura
    * @param os flujo de salida
    * @param B Bolsa de letras cuyo contenido se quiere sacar por pantalla
    * @return El flujo de salida
    */
  friend ostream & operator<<(ostream & os, const bolsa_letras &B);
};
#endif
