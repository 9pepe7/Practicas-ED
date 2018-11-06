#include "Cola_max_vd.h"
#include <vector>

using namespace std;


template <typename T>
void Cola_max<T>::poner(T x){
  principal.push_back(x);
  max.push_back(x);
  for(typename vector<T>::iterator it=max.end();it!=max.begin()-1;--it){
    if(*it > *(it-1)){
      *(it-1)=*it;
    }
  }
}

template <typename T>
void Cola_max<T>::quitar(){ // pop
  principal.erase(principal.begin());//pop_front
  max.erase(max.begin());
}

template <typename T>
T Cola_max<T>::frente(){ // front
  return principal.front();
}

template <typename T>
bool Cola_max<T>::vacia(){ // empty
 return (principal.empty()&&max.empty());
}

template <typename T> // size
int Cola_max<T>::num_elementos(){
 return principal.size();
}

template <typename T>
T Cola_max<T>::maximo(){
  return max.front();
}
