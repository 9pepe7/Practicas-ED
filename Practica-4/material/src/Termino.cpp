Termino::Termino(){
  termino.first="";
}

Termino::Termino(string pal, vector<string> def){
  termino.first=pal;
  termino.second=def;
}
Termino::Termino(Termino original){
  termino.first=original.getPalabra();
  termino.second=original.getDefiniciones();
}

string Termino::getPalabra(){
  return termino.first;
}
vector<string> Termino::getDefiniciones(){
  return termino.second;
}
int Termino::getNumDef(){
  return termino.second.size();
}

void Termino::setPalabra(string pal){
  termino.first=pal;
}
void Termino::aniadirDefinicion(string def){
  termino.second.push_back(def);
}

Termino::iterator begin(){
  return termino.second.begin();
}
Termino::const_iterator begin() const{
  return termino.second.begin();
}
Termino::iterator end(){
  return termino.second.end();
}
Termino::const_iterator end() const{
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
  getline(in,pal);
  ter.AniadirDefinicion(pal);
  return in;
}
