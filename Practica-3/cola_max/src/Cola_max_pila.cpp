#include <stack>
#include "Cola_max_pila.h"

using namespace std;

/*
Haremos uso de dos pilas que trabajarán en conjunto, una para inserciones y otra para extracciones.
*/
template <typename T>
void Cola_max<T>::poner(T x){ // push
  in.push(x);
  if(num_elementos()==1 || x>max)
    max=x;
}

template <typename T>
void Cola_max<T>::quitar(){ // pop
  if(out.empty()){ // Si la cola de salida está vacía, se descarga en ella la de entrada
    while(!in.empty()){
      out.push(in.top());
      in.pop();
    }
  }
  if(out.top()==max){ // Si el elemento que se va a eliminar era el maximo, habra que volverlo a buscar
    out.pop();
    if(!vacia()){ // Se busca si queda algun elemento
      buscaMaximo();
    } else{ // Si no, es null
      max=NULL;
    }
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
void Cola_max<T>::buscaMaximo(){ // Busca el maximo, debe haber al menos 1 elemento
  stack<T> aux;
  if(!in.empty()){  // Comprobamos que la cola no esté vacía antes de entrar
    max=in.top(); // El primero es maximo provisional
    while(!in.empty()){ // Se recorre, usando una cola auxiliar
      if(in.top()>max)
        max=in.top();
      aux.push(in.top());
      in.pop();
    }
    while(!aux.empty()){
      in.push(aux.top());
      aux.pop();
    }
  } else {
    max=out.top();
  }
  while(!out.empty()){
    if(out.top()>max)
      max=out.top();
    aux.push(out.top());
    out.pop();
  }
  while(!aux.empty()){
    out.push(aux.top());
    aux.pop();
  }
}
