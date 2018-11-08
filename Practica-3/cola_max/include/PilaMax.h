/**
  * @file PilaMax.h
  * @brief Fichero cabecera del TDA PilaMax
  *
  */
#ifndef PILA_MAX_H
#define PILA_MAX_H
#include <stack>
using namespace std;
/**
  * @brief T.D.A. PilaMax
  *
  * Una instancia del TDA PilaMax es, en efecto, una pila cuyos elementos son pares de tipo T.
  * Esta implementación contiene una pila de parejas.

  * @author José Manuel Navarro Cuartero
  * @author Emilio Calvo de Mora Mármol
  * @date Noviembre 2018
  */
template <class T>
class PilaMax{
private:
/**
  * @page repPilamaxvd Rep del TDA Pilamax
  *
  */
  stack< pair<T,T> > pila; /**< Pila de pares*/
public:

/**
  * @brief función push de una pila, mete un elemento en la misma, por encima del resto
  * @param x Una variable de tipo T
  */
  void push(T x);

/**
  * @brief función pop de una pila, quita el elemento más nuevo de la misma, el de arriba.
  */
  void pop();

/**
  * @brief función que devuelve el tope de la pila de pares
  * @return pair<T,T> una pareja de variables tipo T
  */
  pair<T,T> top();

/**
  * @brief función que devuelve true si está vacía la pila, y false si tiene algún par de elementos
  * @return bool una variable de vacio en la pila
  */
  bool empty();

/**
  * @brief función que devuelve el tamaño de la pila
  * @return int una variable tamaño de la pila actual
  */
  int size();
};
#include "PilaMax.cpp"
#endif
