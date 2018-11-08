#include <stack>
#include "Cola_max_pila.h"

using namespace std;

/*
Haremos uso de dos pilas que trabajarán en conjunto, una para inserciones y otra para extracciones.
*/
template <typename T>
void Cola_max<T>::poner(T x){ // push
  in.push(x);
}

template <typename T>
void Cola_max<T>::quitar(){ // pop
  if(out.empty()){ // Si la cola de salida está vacía, se descarga en ella la de entrada
    while(!in.empty()){
      out.push(in.top().first);
      in.pop();
    }
  }
  out.pop();
}

template <typename T>
T Cola_max<T>::frente(){ // front
  if(out.empty()){
    while(!in.empty()){
      out.push(in.top().first);
      in.pop();
    }
  }
  return out.top().first;
}

template <typename T>
bool Cola_max<T>::vacia(){ // empty
  return (in.empty()&&out.empty());
}

template <typename T>
int Cola_max<T>::num_elementos(){ // size
  return (in.size()+out.size());
}

template <typename T>
T Cola_max<T>::maximo(){ // maximo elemento
  T max;
  if(!in.empty() && !out.empty()){
    if(in.top().second>out.top().second)
      max = in.top().second;
    else
      max = out.top().second;
  } else if (!in.empty()){
    max = in.top().second;
  } else {
    max = out.top().second;
  }
  return max;
}
