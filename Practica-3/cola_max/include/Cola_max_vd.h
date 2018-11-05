/**
  * @file Cola_max_pila.h
  * @brief Fichero cabecera del TDA Cola_max en su implementacion a base de dos vectores
  *
  */
#ifndef COLA_MAX_VD_H
#define COLA_MAX_VD_H
#include <vector>

using namespace std;

/**
  * @brief T.D.A. Cola_max
  *
  * Una instancia del TDA Cola_max es, a efectos practicos, una cola de la que además se puede saber el máximo.
  * Esta implementación contiene dos vectores, uno con sus miembros y el otro para el maximo.
  *
  * @author José Manuel Navarro Cuartero
  * @author Emilio Calvo de Mora Mármol
  * @date Noviembre 2018
  */
template <class T>
class Cola_max{
private:
  vector<T> principal; /**< Vector con los elementos*/
  vector<T> max;/**< Vector de maximos*/

public:
  void poner(T x);
  void quitar();
  T frente();
  bool vacia();
  int num_elementos();
  T maximo();
};
#endif
