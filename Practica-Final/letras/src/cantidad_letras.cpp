/* El programa se deberá ejecutar en la línea de órdenes de la siguiente manera:
prompt% cantidad_letras spanish letras.txt salida.txt */
#include <fstream>
#include <iostream>
#include "conjunto_letras.h"
#include <ctype.h> // toupper
#include <map>
#include <iomanip>

using namespace std;

int main(int argc, char * argv[]){
  if (argc!=4){
    cout << "Los parámetros de entrada son los siguientes:" << endl;
    cout << "1. El nombre del fichero con lista_palabras" << endl;
    cout << "2. El nombre del fichero con las letras" << endl;
    cout << "3. El fichero donde escribir el conjunto de letras con la cantidad de apariciones calculada." << endl;
    return 0;
  }
  ifstream f_lista_palabras(argv[1]);
  ifstream f_letras(argv[2]);
  ofstream f_salida(argv[3]);
  if (!f_lista_palabras){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }
  if (!f_letras){
    cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
    return 0;
  }
  if (!f_salida){
    cout<<"No puedo abrir el fichero "<<argv[3]<<endl;
    return 0;
  }

  conjunto_letras C; f_letras >> C;
  map<char,int> recuento;
  for(conjunto_letras::iterator it=C.begin(); it!=C.end(); ++it)
    recuento[(*it).getLetra()]=0;

  char c; map<char,int>::iterator it;
  while(!f_lista_palabras.eof()){
    f_lista_palabras >> c;
    it=recuento.find(toupper(c));
    if(it!=recuento.end())
      it->second++;
  }

  double total=0.0;
  for(it=recuento.begin(); it!=recuento.end(); ++it)
    total+=it->second;

  map<char,double> frecuencias;
  for(it=recuento.begin(); it!=recuento.end(); ++it)
    frecuencias[it->first]=(it->second/total*100);

  f_salida << "#Letra\tCantidad" << endl;
  f_salida << setprecision(2) << fixed;
  for(map<char,double>::iterator ite=frecuencias.begin(); ite!=frecuencias.end(); ++ite)
    f_salida << ite->first << "\t" << ite->second << "%" << endl;
}
