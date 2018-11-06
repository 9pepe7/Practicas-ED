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
  stack<T> in; /**< Cola para inserciones */
  stack<T> out;/**< Cola para extracciones y consultas*/
  T max; /**< Maximo */

public:
  void poner(T x);
  void quitar();
  T frente();
  bool vacia();
  int num_elementos();
  T maximo();
private:
  void buscaMaximo();
};
#endif
