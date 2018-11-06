#include "Cola_max_vd.h"
#include <vector>

using namespace std;


template <typename T>
void Cola_max<T>::poner(T x){ // push_back
  principal.push_back(x);
  max.push_back(x);
  for(int i=num_elementos()-1;i>0;--i){ // Comprobamos si se ha introducido un nuevo maximo
    if(max[i] > max[i-1]){ // Si i es mayor que su anterior, se modifica su anterior
      max[i-1]=max[i];
    }
  }
}

template <typename T>
void Cola_max<T>::quitar(){ // pop_front
  principal.erase(principal.begin());;
  max.erase(max.begin());
}

template <typename T>
T Cola_max<T>::frente(){ // front
  return principal.front();
}

template <typename T>
bool Cola_max<T>::vacia(){ // empty
 return (principal.empty()); // si uno esta vacío, el otro debería estarlo también
}

template <typename T>
int Cola_max<T>::num_elementos(){ // size, debería ser el mismo en ambos vectores
 return principal.size();
}

template <typename T>
T Cola_max<T>::maximo(){ // El maximo es el primer miembro del vector max
  return max.front();
}
