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
  * Una instancia del TDA Cola_max es, a efectos prácticos, una cola (FIFO) de la que además se puede saber el máximo.
  * Esta implementación contiene dos vectores, uno con sus miembros y el otro para el máximo.
  * El primero actuará como un queue simple con sus miembros en orden.
  * El segundo irá añadiendo los nuevos elementos también, pero además, será modificado si se añade un nuevo máximo.
  *
  * @author José Manuel Navarro Cuartero
  * @author Emilio Calvo de Mora Mármol
  * @date Noviembre 2018
  */

template <class T>
class Cola_max{

private:

/**
  * @page repColamaxvd Rep del TDA Colamax
  *
  */
  vector<T> principal; /**< Vector con los elementos*/

  vector<T> max;/**< Vector de maximos*/

public:

/**
  * @brief función push de una cola, mete un elemento en la cola, por detrás de la misma
  * @param Una variable de tipo T
  */
  void poner(T x);

/**
  * @brief función pop de una cola, quita el elemento que primero entró en la misma, el de delante
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

};
#endif
