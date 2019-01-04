#ifndef LETRA_H
#define LETRA_H

#include <set>
#include <vector>
#include <string>

using namespace std;

/**
  * @brief T.D.A. LETRA
  *
  * Una instancia del TDA letra es un objeto que contiene un carácter,
  * una cantidad entera asociada, y la puntuación de dicho carácter
  *
  * @author José Manuel Navarro Cuartero
  * @author Emilio Calvo de Mora Mármol
  * @date Enero 2019
  */

class letra{
private:
  /**
   * @page repLetra Rep del TDA letra
   *
   * @section invLetra Invariante de la representación
   *
   * El invariante de representación dicta que cada carácter tendrá siempre
   * una cantidad mayor que 0.
   *
   * @section funcLetra  Funcion de Abstracción
   *
   * Un objeto del TDA letra representa un carácter, la cantidad de veces que se repite, y la puntuación asociada al mismo
   *
   */
  char caracter;/**< char con el carácter que identifica la letra */
  int cantidad;/**< int con la cantidad asociada al carácter */
  int puntuacion;/**< int con la puntuación asociada al carácter */

public:

  /**
    * @brief Constructor por defecto de la clase.
    * @details Crea una letra vacía
    */
  letra();

  /**
    * @brief Devuelve el carácter del tipo letra
    * @return El carácter identificativo
    */
  char getLetra() const;

  /**
    * @brief Devuelve la cantidad del tipo letra
    * @return La cantidad de la letra
    */
  int getCantidad() const;

    /**
      * @brief Devuelve la puntuación del tipo letra
      * @return La puntuación de la letra
      */
  int getPuntuacion() const;

  /**
    * @brief Sobrecarga del operador de lectura
    * @param is flujo de entrada
    * @param L Letra que recibe el flujo de datos
    * @return El flujo de entrada
    */
  friend istream & operator>>(istream & is, letra &L);

  /**
    * @brief Sobrecarga del operador de escritura
    * @param os flujo de salida
    * @param L Letra a escribir por pantalla
    * @return El flujo de salida
    */
  friend ostream & operator<<(ostream & os, const letra &L);

  /**
    * @brief Sobrecarga del operador <
    * @param l la letra que se compara con la que llama al método
    * @return bool True, si la letra que llama al método se encuentra alfabéticamente antes que l, false si al contrario
    */
  bool operator < (const letra &l) const;
};
#endif
