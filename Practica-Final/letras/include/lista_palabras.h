#ifndef __lista_palabras_h__
#define __lista_palabras_h__

#include <set>
#include <vector>
#include <string>
#include "comp.h"

using namespace std;

class lista_palabras{
private:
  set<string,comp> datos; /** set de strings ordenados según el criterio comp */

public:
/**
  * @brief Construye un lista_palabras vacio
  */
  lista_palabras();

/**
  * @brief Devuelve el numero de palabras en el lista_palabras
  */
  int size() const;

/**
  * @brief Obtiene todas las palabras en el lista_palabras de una longitud dada
  * @param longitud la longitud de las palabras de salida
  * @return un vector con las palabras de longitud especificada en el parámetro de entrada
  */
  vector<string> palabras_longitud(const int &longitud) const;

/**
  * @brief Indica si una palabra está en el lista_palabras o no
  * @param palabra la palabra que se quiere buscar
  * @return true si la palabra esta en el lista_palabras. false en caso contrario
  */
  bool Esta(const string &palabra) const;

/**
  * @brief Lee de un flujo de entrada un lista_palabras
  * @param is flujo de entrada
  * @param D el objeto donde se realiza la lectura.
  * @return el flujo de entrada
  */
  friend istream & operator>>(istream & is, lista_palabras &D);

/**
  * @brief Escribe en un flujo de salida un lista_palabras
  * @param os flujo de salida
  * @param D el objeto lista_palabras que se escribe
  * @return el flujo de salida
  */
  friend ostream & operator<<(ostream & os, const lista_palabras &D);

  class iterator {
  private:
    set<string>::iterator it;

  public:
    /**
      * @brief Constructor de la clase iterator de lista_palabras
      * @return Crea un iterator
      */
    iterator ();

    /**
      * @brief Sobrecarga del operador *
      * @return Devuelve el string de la lista_palabras al que apunta el iterador
      */
    string operator *() const;

    /**
      * @brief Sobrecarga del operador de avance de iteradores
      * @return El valor del siguiente iterador
      */
    iterator & operator ++();

    /**
      * @brief Sobrecarga del operador de igualdad lógica
      * @param i iterador con el que se compara aquél que llama al método, a la izquierda del ==
      * @return Un valor lógico, true si i es igual al iterador que llama al método, false si al contrario
      */
    bool operator ==(const iterator &i) const;

    /**
      * @brief Sobrecarga del operador de desigualdad lógica
      * @param i iterador con el que se compara aquél que llama al método, a la izquierda del !=
      * @return Un valor lógico, true si i es diferente del iterador que llama al método, false si al contrario
      */
    bool operator !=(const iterator &i) const;
    friend class lista_palabras;
  };

  /**
    * @brief Definicion de la funcion begin del iterador de la clase lista_palabras
    * @return Iterador que apunta al inicio del la lista de palabras
    */
  iterator begin() const;

  /**
    * @brief Definicion de la funcion end del iterador de la clase lista_palabras
    * @return Iterador que apunta al final del la lista de palabras
    */
  iterator end() const;
};
#endif
