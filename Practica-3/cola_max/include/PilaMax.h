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
  * Además, se modificará por si sola con las inserciones para llevar constancia de su máximo en todo momento.
  * Esta implementación contiene una pila de pares.

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
  * @brief función que devuelve elemento tope de la pila
  * @return T elemento
  */
  T top();

/**
  * @brief función que devuelve true si está vacía la pila, y false si tiene algún par de elementos
  * @return bool una variable de vacio en la pila
  */
  bool empty();

/**
  * @brief función que devuelve el tamaño de la pila
  * @return int Un entero con el tamaño de la pila actual
  */
  int size();
/**
  * @brief función que devuelve elemento máximo de la pila
  * @return T elemento
  */
  T max();
};
#include "PilaMax.cpp"
#endif
