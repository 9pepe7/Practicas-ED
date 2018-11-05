#include "Cola_max_vd.h"
#include <vector>
#include <iterator>

using namespace std;


template <typename T>
void poner(T x){
  principal.push_back(x);
  max.push_back(x);
  for(typename vector<T>::iterator it=max.end();it!=max.begin();--it){
  
  }
}

template <typename T>
void quitar(){ // pop
  principal.erase(principal.begin());//pop_front
  max.erase(max.begin());
}

template <typename T>
T frente(){
  return principal.front();
}

template <typename T>
bool vacia(){
 return true;
}

template <typename T>
int num_elementos(){
 return 0;
}

template <typename T>
T maximo(){
  return max.front();
}
