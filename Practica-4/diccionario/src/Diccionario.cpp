#include <iostream>
#include <vector>
#include <string>
#include "Termino.h"
#include "Diccionario.h"

using namespace std;

Diccionario::Diccionario(){} // Costructor por defecto (no tocamos nada)
Diccionario::Diccionario(const set<Termino> &dic){ // Costructor por parametros
  dicc = dic;
}
Diccionario::Diccionario(const Diccionario &original){ // Constructor por copia
  dicc = original.getTerminos();
}

vector<string> Diccionario::getDefiniciones(const string &pal) const{ // Todas las definiciones de 1 palabra
  vector<string> res;
  Diccionario::const_iterator it=findTermino(pal);
  if(it != end()) // Si no encuentra la palabra, res esta vacio
    res=it->getDefiniciones();
  return res;
}
set<Termino> Diccionario::getTerminos() const{ // Todos los terminos del diccionario
  return dicc;
}
int Diccionario::getNumTerminos() const{ // size
  return dicc.size();
}

void Diccionario::aniadirTermino(const Termino &t){ // Añadir 1 termino
  dicc.insert(t);
}
void Diccionario::eliminarTermino(const Termino &t){ // Eliminar el termino dado
  dicc.erase(t); // Si no se encuentra el termino, no se borra nada
}
void Diccionario::eliminarTermino(Diccionario::iterator it){ // Eliminar el termino al que apunta el iterador
  dicc.erase(it);
}
Diccionario::const_iterator Diccionario::findTermino(const string &pal) const{ // dicc.find pero por palabra, menos eficiente, mas general
  for(Diccionario::const_iterator it=begin(); it!=end(); ++it){ // Esto creo que podria hacerse mas eficientemente
    if(it->getPalabra() == pal){ // Iteramos por el diccionario hasta hallar la palabra, o el final
      return it; // Si encontramos la palabra, devolvemos su iterador
    }
  }
  return end(); // Return por defecto es end()
}
Diccionario::const_iterator Diccionario::findTermino(const Termino &t) const{ // Usamos este para busquedas más eficientes
  return dicc.find(t); // Solo sirve para buscar terminos completos, no su palabra
}

Diccionario Diccionario::filtradoIntervalo(char ini, char fin) const{ // Filtra por dos iniciales
  Diccionario res;
  Diccionario::const_iterator it;
  if(ini >= 'A' && ini <= 'Z') // Transformamos a minuscula
    ini+=32;
  if(fin >= 'A' && fin <= 'Z')
    fin+=32;
  if(ini > fin){ // Si las letras se dieron en orden incorrecto, se corrige
    char aux = ini;
    ini = fin;
    fin = aux;
  }
  for(it=begin(); it->getInicial() < ini && it!=end(); ++it){} // Colocamos el iterador en la primera palabra buena
  while(it!=end() && it->getInicial() <= fin){ // Llega hasta que haya palabras que no empiezan por la segunda letra, o el final
    res.aniadirTermino(*it);
    ++it;
  }
  return res;
}
Diccionario Diccionario::filtradoClave(const string &clave) const{ // Filtrado por clave en definicion
  Diccionario res;
  for(Diccionario::const_iterator it=begin(); it!=end(); ++it){ // Itero sobre todos los terminos del diccionario
    Termino t; // Creo un termino vacio
    for(Termino::const_iterator it2 = it->begin(); it2!=it->end(); ++it2){ // Itero ahora sobre las def del termino en el que se encuentra "it" (it2)
      if (contenida(*it2,clave)) // Busca si aparece la palabra en la definicion en la que se encuentra "it2"
        t.aniadirDefinicion(*it2); // Si la encuentra, la guarda
    }
    if(t.getNumDef()>0){ // Si se guardó alguna definicion, se guarda el término entero
      t.setPalabra(it->getPalabra()); // Le pongo su palabra
      res.aniadirTermino(t); // Y lo añado al diccionario
    }
  }
  return res;
}

void Diccionario::estadisticas(int &totaldef, int &maxdef, string &maxpal) const{ // Total de definiciones, y cual es la palabra con más
  totaldef=0; maxdef=0; maxpal="";
  for(Diccionario::const_iterator it=begin(); it!=end(); ++it){
    totaldef+=it->getNumDef(); // Recuento de definiciones
    if(it->getNumDef() > maxdef){ // Búsqueda de la palabra con más def
      maxdef=it->getNumDef();
      maxpal=it->getPalabra();
    }
  }
}
double Diccionario::promedioDefiniciones() const{ // definiciones promedio
  return double(totalDefininiciones())/double(getNumTerminos()); // se transforman a double ambos ints
}
bool Diccionario::sonletras(const char &c1, const char &c2) const{ // comprueba si ambos chars son letras validas
  bool res=true;
  if( (c1<'A' || c1>'Z') && (c1<'a' || c1>'z') )
    res=false;
  if( (c2<'A' || c2>'Z') && (c2<'a' || c2>'z') )
    res=false;
  return res;
}

Diccionario::iterator Diccionario::begin(){
  return dicc.begin();
}
Diccionario::const_iterator Diccionario::begin() const{
  return dicc.begin();
}
Diccionario::iterator Diccionario::end(){
  return dicc.end();
}
Diccionario::const_iterator Diccionario::end() const{
  return dicc.end();
}

ostream& operator<< (ostream & os, const Diccionario & d){ // Esta viene en el pdf
  Diccionario::const_iterator it;
  for(it = d.begin(); it != d.end(); ++it){
    os << *it;
  }
  return os;
}
istream& operator>> (istream & is, Diccionario & d){ // istream basico
  while(!is.eof()){ // recorremos el archivo entero
    Termino nuevo;
    is >> nuevo; // Tomamos 1 palabra con 1 definicion (1 linea de texto)
    Diccionario::iterator it = d.findTermino(nuevo.getPalabra()); // Buscamos si tenemos ya a esa palabra (con otras definiciones)
    if(it == d.end()){ // Si es un termino nuevo
      if(nuevo.getPalabra()!="" && nuevo.getNumDef()>0) // Se guarda si es un termino valido
        d.aniadirTermino(nuevo);
    }
    else{ // Si esa palabra ya estaba, se añade la definicion
      Termino antiguo = (*it); // Primero tomamos el termino que ya teniamos
      d.eliminarTermino(it); // Lo eliminamos del diccionario
      antiguo.aniadirDefinicion(nuevo.getDefinicion()); // Le añadimos la nueva definicion
      d.aniadirTermino(antiguo); // Y se vuelve a guardar
    }
  }
  return is;
}

/* En un principio, para el filtrado por clave decidimos usar string::find, como hicimos en la practica 2.
Sin embargo, nos dimos cuenta de que string::find solo busca cadenas de caracteres, no palabras. Es decir,
que si en la cadena "tomatera", nosotros buscabamos "mate", string::find nos daría un resultado positivo,
ya que, efectivamente, la cadena "mate" se encuentra ahí. Decidimos por tanto, implementar una búsqueda
refinada que distinga palabras, para un mejor filtrado por clave. */
bool Diccionario::contenida (const string &frase, const string &palabra) const{ // Comprueba si una palabra esta en un string
  bool res=false;
  for(string::const_iterator it_frase = frase.begin(); !res && it_frase!=frase.end(); ++it_frase){ // Iteramos caracter a caracter por la definicion
    if( *it_frase == *(palabra.begin()) ){ // Aquí podría comenzar la palabra (coinciden los caracteres)
      string::const_iterator it_ant=it_frase; --it_ant; // Colocamos un iterador temporal en el caracter anterior al comienzo de la palabra
      if( it_frase==frase.begin() || !sonletras(*it_ant) ){ // Comprobamos que sea el principio de la frase o que antes no haya letra
        bool salir = false;
        string::const_iterator it_palabra = palabra.begin();  // Procedemos a recorrer la palabra y la frase (ésta a traves de un aux)
        string::const_iterator it_aux;    // de forma paralela, hasta que acaben una u otra, o hasta que sean distos algún par de caracteres
        for(it_aux = it_frase; it_palabra!=palabra.end() && it_aux!=frase.end() && !salir; ++it_palabra, ++it_aux){
          if(*it_aux != *it_palabra) // Si no coincide algún miembro, salir
            salir = true;
        }
        if(it_palabra==palabra.end() && !salir){ // Si acabó la iteracion de palabra sin fallos, podemos salir del for, si no, éste sigue por donde iba
          if(it_aux==frase.end() || !sonletras(*it_aux) ) // Comprobamos que sea final de la frase o que el caracter siguiente no es letra
            res=true;
        }
      }
    }
  }
  return res;
}

/* Estas funciones al final no se usarán, en favor de Diccionario::Estadisticas() que hará el trabajo de todas
para evitar iterar sobre el diccionario 3 veces (una vez cada una), pudiendo hacerlo solo 1 vez en total.
Dejaremos las funciones en private por si se deseara usarlas en otro momento */
int Diccionario::totalDefininiciones() const{ // numero total de definiciones entre todos los terminos
  int n=0;
  for(Diccionario::const_iterator it=begin(); it!=end(); ++it){ // itero sobre todos los terminos del diccionario
    n+=it->getNumDef();
  }
  return n;
}
int Diccionario::maxDefiniciones() const{ // busco el termino con mas definiciones (solo la cifra)
  int max=0;
  for(Diccionario::const_iterator it=begin(); it!=end(); ++it){
    if(it->getNumDef() > max)
      max=it->getNumDef();
  }
  return max;
}
string Diccionario::maxPal(int x) const{ // busco la (primera) palabra con mas defs (siempre >= x )
  string pal; // x es 0 por defecto, luego puede usarse tambien para ver si hay palabras con mas de x definiciones
  for(Diccionario::const_iterator it=begin(); it!=end(); ++it){
    if(it->getNumDef() > x){
      x=it->getNumDef();
      pal=it->getPalabra();
    }
  }
  return pal;
}
