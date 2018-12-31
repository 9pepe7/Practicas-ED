/* Este programa construye palabras de longitud mayor (o de puntuación mayor) a partir de una
serie de letras seleccionadas de forma aleatoria. El programa letras se deberá ejecutar en la
línea de órdenes de la siguiente manera:
prompt% letras spanish.txt letras.txt 8 L*/
#include <fstream>
#include <iostream>
#include "conjunto_letras.h"
#include "bolsa_letras.h"
#include "lista_palabras.h"

using namespace std;

int main(int argc, char * argv[]){
  if (argc!=5){
    cout<<"Los parametros son:"<<endl;
    cout << "1. El nombre del fichero con lista_palabras." << endl;
    cout << "2. El nombre del fichero con las letras." << endl;
    cout << "3. El número de letras que se deben generar de forma aleatoria." << endl;
    cout << "4. Modalidad de juego:" << endl;
    cout << "Longitud: Si el parámetro es L se buscará la palabra más larga." << endl;
    cout << "Puntuación: Si el parámetro es P se buscará la palabra de mayor puntuación." << endl;
    return 0;
  }
  ifstream f_lista_palabras(argv[1]);
  ifstream f_letras(argv[2]);
  if (!f_lista_palabras){
    cout<<"No puedo abrir el fichero"<<argv[1]<<endl;
    return 0;
  }
  if (!f_letras){
    cout<<"No puedo abrir el fichero"<<argv[2]<<endl;
    return 0;
  }
  if(stoi(argv[3])<1){
    cout << "Debe generarse al menos una letra." << endl;
    return 0;
  }
  if( argv[4][0]!='L' && argv[4][0]!='P' ){
    cout << "Debe seleccionarse una modalidad de juego valida (L o P)." << endl;
    return 0;
  }
  lista_palabras L; f_lista_palabras >> L;
  conjunto_letras C; f_letras >> C;
  bolsa_letras B (C);
  char juega_otra_vez, tipo=argv[4][0];
  int tam=stoi(argv[3]);
  do{
    string solucion;
    if(tipo=='P')
      C.getPuntuaciones();
    vector<char> vec = B.setAleatoria(tam);
    cout << "Las letras son:" << endl;
    for(int i=0; i<vec.size(); ++i)
      cout << vec[i] << " ";
    cout << "Dime tu solucion -> ";
    cin >> solucion;
    cout << "¿Quieres seguir jugando[S/N]? ";
    cin >> juega_otra_vez;
  } while (juega_otra_vez == 'S');
}
