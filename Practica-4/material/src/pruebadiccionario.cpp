#include "Diccionario.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char * argv[]){
  if (argc!=2){
    cout<<"Dime el nombre del fichero con el diccionario"<<endl;
    return 0;
  }

  ifstream f (argv[1]);
  if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }

  Diccionario mi_diccionario;
  f>>mi_diccionario; //Cargamos en memoria el diccionario
  cout << "El diccionario ha sido cargado" << endl;
  //Usamos un iterador para recorrer los terminos del diccionario e imprimirlos
  //cout << mi_diccionario;

  // Exhibir aqui la funcionalidad programada para el TDA Diccionario / TDA Termino
  //  - Obtener las definiciones asociadas a una palabra
  /*string palabra;
  cout << "Sobre que palabra desea obtener sus definiciones? -> ";
  cin >> palabra;
  vector<string> defs = mi_diccionario.getDefiniciones(palabra);
  while (defs.size() == 0){
    cout << "Lo sentimos, esa palabra no se encuentra en el diccionario." << endl;
    cout << "Pruebe con otra -> ";
    cin >> palabra;
    defs = mi_diccionario.getDefiniciones(palabra);
  }
  cout << "Las definiciones de su palabra " << palabra << " son:" << endl;
  for(vector<string>::iterator it=defs.begin(); it!=defs.end();++it){
    cout << "--> " << *it << endl;
  }*/

  //  - Obtener el (sub)diccionario de términos comprendidos en [caracter_inicial, caracter_final]
  char c1, c2;
  cout << "Que subdiccionario de terminos comprendidos entre dos caracteres desea obtener?" << endl;
  cout << "Primer caracter -> ";
  cin >> c1;
  cout << "Segundo caracter -> ";
  cin >> c2;
  while(!mi_diccionario.sonletras(c1,c2)){
    cout << "Esos no son dos caracteres aceptados. Intentelo de nuevo" << endl;
    cout << "Primer caracter -> ";
    cin >> c1;
    cout << "Segundo caracter -> ";
    cin >> c2;
  }
  Diccionario sub1 = mi_diccionario.filtradoIntervalo(c1,c2);
  cout << "El subdiccionario obtenido es:" << endl;
  cout << sub1;
  //  - Obtener el (sub)diccionario de términos asociados a una palabra clave. Ejemplo: el diccionario de terminos asociados a "color"
  //  - Obtener el numero total de definiciones, el maximo de definiciones asociadas a una unica palabra y el promedio de definiciones por palabra
  //  - Cualquier otra funcionalidad que considereis de interes
}
