/**
  * @file Cola_max_pila.h
  * @brief Fichero cabecera del TDA Cola_max en su implementacion a base de dos pilas
  *
  */
#ifndef COLA_MAX_PILA_H
#define COLA_MAX_PILA_H
#include <stack>
using namespace std;

/**
  * @brief T.D.A. Cola_max
  *
  * Una instancia del TDA Cola_max es, a efectos practicos, una cola (FIFO) de la
  * que además se puede saber el máximo. Esta implementación contiene dos pilas con
  * sus miembros repartidos entre ambas, y una variable que contiene dicho máximo,
  * que se modificará cuando se añada un maximo nuevo, o cuando se elimine dicho maximo.
  *
  * @author José Manuel Navarro Cuartero
  * @author Emilio Calvo de Mora Mármol
  * @date Noviembre 2018
  */
template <class T>
class Cola_max{
private:

/**
  * @page repColamaxpila Rep del TDA Colamax
  *
  */

  stack<T> in; /**< Cola para inserciones */
  stack<T> out;/**< Cola para extracciones y consultas*/
  T max; /**< Maximo */

public:
/**
  * @brief función push de una cola, mete un elemento en la cola, por detrás de la misma
  * @param x Una variable de tipo T
  */
  void poner(T x);

/**
  * @brief función pop de una cola, quita el elemento más antiguo de la misma, el de delante
  */
  void quitar();

/**
  * @brief función front de una cola, devuelve el que primero entró en la cola
  * @return el elemento de tipo T que está en el frente de la cola
  */
  T frente();

/**
  * @brief función que comprueba si está vacía una cola
  * @return una variable booleana que devuelve verdadero si está vacía la cola
  */
  bool vacia();

/**
  * @brief función que comprueba el número de elementos actuales de la cola
  * @return variable entera con el número de elementos de la cola
  */
  int num_elementos();

/**
  * @brief función que devuelve el máximo de la cola
  * @return devuelve una variable de tipo T con el valor máximo de la cola
  */
  T maximo();

private:
/**
  * @brief función que encuentra el máximo de la cola y modifica su miembro "max"
  */
  void buscaMaximo();

};
#endif
