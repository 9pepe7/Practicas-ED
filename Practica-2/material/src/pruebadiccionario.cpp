#include "Diccionario.h"
#include "Termino.h"
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

   cout << "El diccionario esta cargado " << endl;
   cout << "Las definiciones asociadas a la sexta palabra, por ejemplo, son: "<<endl;
   cout << mi_diccionario.getTermino(5)<<endl;

   cout << "Introduzca una palabra valida para encontrar sus definiciones: "<<endl;
   int valido = 0;
   string p;
   cin >> p;
   valido = mi_diccionario.buscarPalabra(p);
   while(valido == -1){
     cout << "Lo sentimos, su palabra no se encuentra en el diccionario. Pruebe con otra:" << endl;
     cin >> p;
     valido = mi_diccionario.buscarPalabra(p);
   }
   cout << "Las definiciones asociadas a su palabra, son: "<<endl;
   cout << mi_diccionario.getTermino(valido)<<endl;

   char l1 = 'c', l2 = 'h';
   cout << "Subdiccionario comprendido entre " << l1 << " y " << l2 << ":" << endl;
   Diccionario sub1 = mi_diccionario.filtrarIntervalo(l1, l2);
   cout << sub1 << endl;

   string str = "community";
   cout << "Subdiccionario asociado a la palaba clave " << str << ":"  << endl;
   Diccionario sub2 = mi_diccionario.filtrarClave(str);
   cout << sub2 << endl;

   cout << "El numero total de definiciones es: " << mi_diccionario.recuentoDefiniciones()<<endl;
   cout << "EL maximo de definiciones asociadas a una unica palabra es: " << mi_diccionario.maximoDefiniciones()<<endl;
   cout << "EL promedio de definiciones por palabra es: " << mi_diccionario.promedioDefiniciones()<<endl;


   /* Exhibir aqui la funcionalidad programada para el TDA Diccionario / TDA Termino
    Algunas sugerencias:
    - Obtener las definiciones asociadas a una palabra
    - Obtener el (sub)diccionario de términos comprendidos en [caracter_inicial, caracter_final]
    - Obtener el (sub)diccionario de términos asociados a una palabra clave. Ejemplo: el diccionario de terminos asociados a "color"
    - Obtener el numero total de definiciones, el maximo de definiciones asociadas a una unica palabra y el promedio de definiciones por palabra
    - Cualquier otra funcionalidad que considereis de interes
   */

}
