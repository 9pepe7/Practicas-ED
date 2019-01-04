#include "letra.h"
#include "conjunto_letras.h"
#include "bolsa_letras.h"
#include "lista_palabras.h"
#include <iostream>
#include <vector>
#include <set>
#include <stdio.h> // NULL
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <ctype.h> // toupper

using namespace std;

bolsa_letras::bolsa_letras(){}

bolsa_letras::bolsa_letras(const conjunto_letras &C){ // Se crea con los datos de un conjunto
  for(conjunto_letras::iterator it = C.begin(); it!=C.end(); ++it){
    for(int j=0; j<it->getCantidad(); ++j)
      letras.push_back(it->getLetra());
  }
}

void bolsa_letras::setAleatorias(const unsigned &tam){ // Se seleccionan tam letras aleatorias
  this->aleatorias.clear();
  if(tam <= letras.size()){ // Ha de haber suficientes de las que elegir
    vector<char> aux=this->letras; // Lista de letras posibles
    srand (time(NULL)); // Randomizador
    for(unsigned i=0, random;i<tam;++i){
      random=rand()%aux.size();
      aleatorias.push_back(aux[random]);
      aux.erase(aux.begin()+random); // Segun se añade una letra, se borra de la lista de posibles
    }
  }
}

bool bolsa_letras::solucion_correcta(string pal) const{ // Se comprueba si una solucion es correcta con las aleatorias
  multiset<char> aux(this->aleatorias.begin(),this->aleatorias.end());
  for(unsigned i=0; i<pal.size(); ++i){
    pal[i]=toupper(pal[i]);
    multiset<char>::iterator it=aux.find(pal[i]);
    if(it==aux.end())
      return false;
    else
      aux.erase(it);
  }
  return true;
}

unsigned bolsa_letras::puntuacionP(const string &pal, const conjunto_letras &C) const{ // Se calcula la puntuacion (P) de una palabra
  int res=0;
  for(unsigned i=0; i<pal.length(); ++i)
    res+=C.puntuacion(pal[i]);
  return res;
}

unsigned bolsa_letras::puntuacionL(const string &pal) const{ // Se calcula la puntuacion (L) de una palabra
  return pal.length();
}

vector<string> bolsa_letras::solucionesP(const lista_palabras &L, const conjunto_letras &C) const{
  vector<string> res;
  int max=0;
  for(lista_palabras::iterator it=L.begin(); it!=L.end(); ++it){
    if( solucion_correcta(*it) ){
      int p=puntuacionP(*it,C);
      if( p > max ){
        res.clear();
        max=p;
        res.push_back(*it);
      } else if(p == max)
        res.push_back(*it);
    }
  }
  return res;
}

vector<string> bolsa_letras::solucionesL(const lista_palabras &L) const{
  vector<string> res;
  int max=0;
  for(lista_palabras::iterator it=L.begin(); it!=L.end(); ++it){
    if( solucion_correcta(*it) ){
      int l=puntuacionL(*it);
      if( l > max ){
        res.clear();
        max=l;
        res.push_back(*it);
      } else if(l == max)
        res.push_back(*it);
    }
  }
  return res;
}

void bolsa_letras::pantallaAleatorias() const{ // Saca por pantalla las letras aleatorias
  for(unsigned i=0; i<aleatorias.size(); ++i)
    cout << aleatorias[i] << " ";
  cout << endl;
}

ostream & operator<<(ostream & os, const bolsa_letras &B){
  for(unsigned i=0; i<B.letras.size();++i)
    os << B.letras[i] << " ";
  os << endl;
  return os;
}
