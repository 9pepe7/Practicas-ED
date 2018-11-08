#include <stack>
#include "PilaMax.h"
using namespace std;
template <typename T>
void PilaMax<T>::push(T x){
  pair<T,T> par (x,x);
  if(!empty()){
    if(par.second<top().second)
      par.second=top().second;
  }
  pila.push(par);
}

template <typename T>
void PilaMax<T>::pop(){
  pila.pop();
}

template <typename T>
pair<T,T> PilaMax<T>::top(){
  return pila.top();
}

template <typename T>
bool PilaMax<T>::empty(){
  return pila.empty();
}

template <typename T>
int PilaMax<T>::size(){
  return pila.size();
}
