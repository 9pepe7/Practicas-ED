#include <iostream>
#include "Termino.h"

using namespace std;

Termino::Termino(){
  termino.first="";
}

Termino::Termino(string pal, vector<string> def){
  termino.first=pal;
  termino.second=def;
}
Termino::Termino(const Termino &original){
  termino.first=original.getPalabra();
  termino.second=original.getDefiniciones();
}

string Termino::getPalabra() const{
  return termino.first;
}
vector<string> Termino::getDefiniciones() const{
  return termino.second;
}
int Termino::getNumDef() const{
  return termino.second.size();
}

void Termino::setPalabra(string pal){
  termino.first=pal;
}
void Termino::aniadirDefinicion(string def){
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
bool Termino::operator< (const Termino &t) const{
    return termino.first < t.getPalabra();
}
