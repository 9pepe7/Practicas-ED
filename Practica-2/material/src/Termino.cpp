#include <iostream>
#include "Termino.h"
#include "Vector_Dinamico.h"

using namespace std;

// Constructor por defecto
Termino::Termino():tamanio(0){
}

// Constructor por parámetros
Termino::Termino(string pal, string def){
  tamanio = 0;
  palabra=pal;
  AniadirDefinicion(def);
}

//Constructor por copia
Termino::Termino(const Termino& original){
  tamanio=original.getTamanio();
  palabra=original.getPalabra();
  definiciones=original.getDefiniciones();
}
// Obtener la palabra.
string Termino::getPalabra() const{
  return palabra;
}
//Obtener las definiciones asociadas a la palabra
Vector_Dinamico<string> Termino::getDefiniciones() const{
  return definiciones;
}

string Termino::getDefinicion(int i) const{
  return definiciones[i];
}

// Obtener el número de definiciones asociadas a la palabra
int Termino::getTamanio() const{
  return tamanio;
}
// Establecer la palabra.
void Termino::setPalabra(string pal){
  palabra=pal;
}
// Añadir nuevas definiciones asociadas a la palabra.
void Termino::AniadirDefinicion (string def){
  tamanio++;
  definiciones.resize(tamanio);
  definiciones[tamanio-1]=def;
}

Termino& Termino::operator=(const Termino& ter){
  tamanio=ter.getTamanio();
  palabra=ter.getPalabra();
  definiciones=ter.getDefiniciones();
  return *this;
}

ostream & operator<<(ostream & out, const Termino & ter) {
  for(int i=0;i<ter.getTamanio();++i){
    out << ter.getPalabra() << "(" << i+1 << "): " << ter.getDefiniciones()[i] << endl;
  }
  return out;
}

istream & operator>>(istream & in, Termino & ter) {
  string pal;
  getline(in,pal,';');
  ter.setPalabra(pal);
  getline(in,pal);
  ter.AniadirDefinicion(pal);
  return in;
}

bool operator==(const Termino & t1, const Termino & t2){
  return t1.getPalabra().compare(t2.getPalabra()) == 0;
}

bool operator< ( const Termino& t1, const Termino& t2){
  return t1.getPalabra().compare(t2.getPalabra()) < 0;
}

bool operator> ( const Termino& t1, const Termino& t2){
  return t1.getPalabra().compare(t2.getPalabra()) > 0;
}
