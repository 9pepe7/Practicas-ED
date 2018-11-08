#include "Cola_max_vd.h"
#include <vector>

using namespace std;


template <typename T>
void Cola_max<T>::poner(T x){ // push_back
  pair<T,T> par(x,x);
  v.push_back(par);
  for(int i=num_elementos()-1;i>0;--i){ // Comprobamos si se ha introducido un nuevo maximo
    if(v[i].second > v[i-1].second){ // Si i es mayor que su anterior, se modifica su anterior
      v[i-1].second=v[i].second;
    }
  }
}

template <typename T>
void Cola_max<T>::quitar(){ // pop_front
  v.erase(v.begin());
}

template <typename T>
T Cola_max<T>::frente(){ // front
  return v.front().first;
}

template <typename T>
bool Cola_max<T>::vacia(){ // empty
 return (v.empty());
}

template <typename T>
int Cola_max<T>::num_elementos(){ // size
 return v.size();
}

template <typename T>
T Cola_max<T>::maximo(){ // El maximo
  return v.front().second;
}
