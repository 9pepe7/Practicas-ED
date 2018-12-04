#include <iostream>
#include "Termino.h"

using namespace std;

Termino::Termino(){ // Constructor por defecto
  termino.first="";
}

Termino::Termino(string pal, vector<string> def){ // Constructor por parametros
  termino.first=pal;
  termino.second=def;
}
Termino::Termino(const Termino &original){ // Constructor por copia
  termino.first=original.getPalabra();
  termino.second=original.getDefiniciones();
}

string Termino::getPalabra() const{
  return termino.first;
}
vector<string> Termino::getDefiniciones() const{
  return termino.second;
}
int Termino::getNumDef() const{ // Numero de definiciones de la palabra
  return termino.second.size();
}
string Termino::getDefinicion() const{ // Primera definicion
  return termino.second[0];
}
char Termino::getInicial() const{ // Letra inicial
  return termino.first[0];
}

void Termino::setPalabra(string pal){
  termino.first=pal;
}
void Termino::aniadirDefinicion(string def){ // Se suma una definicion más
  termino.second.push_back(def);
}

Termino::iterator Termino::begin(){
  return termino.second.begin();
}
Termino::const_iterator Termino::begin() const{
  return termino.second.begin();
}
Termino::iterator Termino::end(){
  return termino.second.end();
}
Termino::const_iterator Termino::end() const{
  return termino.second.end();
}

ostream& operator<< (ostream & os, const Termino & t){ // Esta la da el pdf tal cual
  Termino::const_iterator it;
  for(it = t.begin(); it != t.end(); ++it){
    os << t.termino.first << "-->" << (*it) << endl;
  }
  return os;
}
istream& operator>> (istream & is, Termino & t){ // Pilla una linea entera, palabra y definicion
  string pal;
  getline(is,pal,';');
  t.setPalabra(pal);
  getline(is,pal);
  t.aniadirDefinicion(pal);
  return is;
}
bool Termino::operator< (const Termino &t) const{ // Booleano para poder ordenar los terminos en el set
    return termino.first < t.getPalabra();
}
