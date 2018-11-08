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
      out.push(in.top());
      in.pop();
    }
  }
  out.pop();
}

template <typename T>
T Cola_max<T>::frente(){ // front
  if(out.empty()){
    while(!in.empty()){
      out.push(in.top());
      in.pop();
    }
  }
  return out.top();
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
    if(in.max()>out.max())
      max = in.max();
    else
      max = out.max();
  } else if (!in.empty()){
    max = in.max();
  } else {
    max = out.max();
  }
  return max;
}
