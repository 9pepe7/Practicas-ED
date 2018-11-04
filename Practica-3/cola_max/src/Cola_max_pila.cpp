#include <stack>
#include "Cola_max_pila.h"

using namespace std;

/*
Haremos uso de dos pilas que trabajarán en conjunto, una para inserciones y otra para extracciones.
*/
template <typename T>
void Cola_max<T>::poner(T x){ // push
  in.push(x);
  if(x>max)
    max=x;
}

template <typename T>
void Cola_max<T>::quitar(){ // pop
  if(out.empty()){
    while(!in.empty()){
      out.push(in.top());
      in.pop();
    }
  }
  if(out.top()==max){
    out.pop();
    buscaMaximo();
  } else {
    out.pop();
  }
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
  bool res=true;
  if(!in.empty())
    res=false;
  if(!out.empty())
    res=false;
  return res;
}

template <typename T>
int Cola_max<T>::num_elementos(){ // size
  return (in.size()+out.size());
}

template <typename T>
T Cola_max<T>::maximo(){ // maximo elemento
  return max;
}

template <typename T>
void Cola_max<T>::buscaMaximo(){
  stack<T> aux;
  while(!in.empty()){

  }
}
