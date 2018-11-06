#include "Cola_max_vd.h"
#include <vector>

using namespace std;


template <typename T>
void Cola_max<T>::poner(T x){ // push_back
  principal.push_back(x);
  max.push_back(x);
  if(num_elementos()>1){
    //typename const vector<T>::iterator it=max.begin();
    for(int i=num_elementos()-1;i>0;--i){
      if(max[i] > max[i-1]){
        max[i-1]=max[i];
      }
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
