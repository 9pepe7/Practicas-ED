/**
  * @file diccionario.h
  * @brief Fichero cabecera del TDA diccionario
  *
  */

#ifndef __DICCIONARIO
#define __DICCIONARIO

#include <iostream>
#include"Termino.h"
using namespace std;

  /**
    *  @brief T.D.A. Diccionario
    *
    * Una instancia del tipo de datos abstracto Diccionario es un objeto
    * que contiene un array variable de Terminos del T.D.A. Termino, incluido en
    * este archivo mediante el #include"Termino.h", y un valor entero llamado tamanio,
    * que indica el número de elementos del vector de Terminos.
    * Lo representamos como una lista con todos los Terminos.
    *
    *
    * @author Emilio Calvo de Mora Mármol
    * @author Pepe Navarro Cuartero
    * @date Octubre 2018
    */

class Diccionario {

 private:

   /**
     * @page repDiccionario Rep del TDA Diccionario
     *
     * @section invDionnario Invariante de la representaci�n
     *
     * El invariante es que no pueden existir dos Terminos con la misma palabra.
     *
     */

   Vector_Dinamico<Termino> dicc;
   int tamanio;
 public:

 /**
   * @brief Constructor por defecto de la clase. Crea el diccionario vacío con tamanio = 0
   */
  Diccionario();

  /**
    * @brief Constructor de la clase
    * @param Vector_Dinamico<Termino> el vector dinámico de Terminos que copiar en el vector de Terminos
    * @return Crea el diccionario con los Terminos de Vector_Dinamico<Termino>
    */
  Diccionario(Vector_Dinamico<Termino>);

/**
  * @brief Constructor de copias de la clase
  * @param d Diccionario a copiar en el nuevo Diccionario
  */
  Diccionario( const Diccionario& d);

/**
  * @brief Tamaño del vector
  * @return Devuelve el tamaño del vector
  */
  int getTam() const;

/**
  * @brief Palabra de un Termino i del vector de Terminos del diccionario
  * @return Devuelve la palabra del Termino i del vector de Terminos del diccionario
  */
  string getPalabra(int i);

/**
  * @brief Método de ordenación
  */
  void ordena();

/**
  * @brief Definiciones relacionadas con la palabra p
  * @param String p como identificador del Termino cuya palabra coincide con p
  * @return Devuelve el vector dinámico de definiciones del Termino cuya palabra es p
  */
  Vector_Dinamico<string> getDefiniciones(string p);

/**
  * @brief Definiciones del Termino i del vector dinamico de Terminos
  * @param int i como índice del termino del vector dinámico
  * @return Devuelve el vector dinámico de definiciones del Termino i del vector dinamico
  */
  Vector_Dinamico<string> getDefiniciones(int i);

/**
  * @brief Terminos del diccionario
  * @return Devuelve un vector dinámico de Terminos con todos los Terminos del diccionario
  */
  Vector_Dinamico<Termino> getTerminos();

/**
  * @brief Termino índice i del diccionario
  * @param int i como índice del Termino que se devuelve
  * @return Devuelve el Termino con índice i del vector de Terminos del diccionario
  */
  Termino getTermino(int i) const;

/**
  * @brief Añade un Termino nuevo al diccionario
  * @param Termino t  el Termino a añadir al diccionario
  */
  void nuevoTermino(Termino t);

/**
  * @brief Busca un Termino en el diccionario
  * @param Termino t como Termino que buscar en el diccionario
  * @return Devuelve el índice del vector de Terminos del
  *         diccionario en el que se encuentra el Termino t
  */
  int buscarTermino(Termino t);

/**
  * @brief Busca una palabra en el diccionario
  * @param string p como palabra que buscar en el diccionario
  * @return Devuelve el índice del vector de Terminos del
  *         diccionario en el que se encuentra la palabra p
  */
  int buscarPalabra(string p);

/**
  * @brief Elimina un Termino del diccionario
  * @details Si el Termino eliminado se encuentra
  *          con más Terminos por delante, todos se moverán una posición a la izquierda
  * @param Termino t como el Termino a eliminar en el diccionario
  * @pos El tamaño del vector de términos se reducirá en uno
  */
  void eliminaTermino(Termino t);

/**
  * @brief Hace un recuento de la cantidad de definiciones que tiene el diccionario
  * @return El número de definiciones que acumula el diccionario
  */
  int recuentoDefiniciones();

/**
  * @brief El máximo de definiciones en un solo Termino del diccionario
  * @return Devuelve el número máximo de definiciones que acumula un único Termino del diccionario
  */
  int maximoDefiniciones();

/**
  * @brief El promedio de definiciones por palabra de un solo diccionario
  * @return Devuelve el valor double del promedio de definiciones por palabra de un solo diccionario
  */
  double promedioDefiniciones();

/**
  * @brief Filtra el diccionario por un intervalo de caracteres
  * @param char ini como carácter inicial del límite del intervalo
  * @param char fin como carácter final del límite del intervalo
  * @return Se devuelve un nuevo diccionario filtrado por los límites puestos por los caracteres
  */
  Diccionario filtrarIntervalo(char ini, char fin);

/**
  * @brief Añade una definición a un Termino ya existente en el diccionario
  * @param int i como entero índice del vector de Terminos cuyo vector de definiciones va a ser ampliado
  * @param string def como cadena de caracteres de la definición a añadir
  * @post El Termino con índice i del diccionario tendrá una nueva definición, string def
  */
  void aniadirDefinicion(int i, string def);

/**
  * @brief Filtra el diccionario por una clave que se debe encontrar en la definición
  * @details filtrarClave solo devuelve en el diccionario las definiciones que contengan la clave dada
  * @param const string clave como cadena que buscar en los strings de definiciones del diccionario
  * @return Se devuelve un nuevo diccionario filtrado por la clave dada por parámetros
  */
  Diccionario filtrarClave(const string clave);

/**
  * @brief Entrada de un diccionario desde istream
  * @param flujo stream de entrada
  * @param Diccionario& d como el diccionario que recibe los datos del flujo de entrada
  * @retval El diccionario recibido por flujo
  */
  friend istream& operator>>(istream & flujo, Diccionario &d);

/**
  * @brief Salida de un diccionario a ostream
  * @param flujo stream de salida
  * @param diccionario a sacar por el flujo
  * @post se obtiene un diccionario en el flujo de salida
  */
  friend ostream& operator<<(ostream & flujo, const Diccionario &d);

};

#endif
