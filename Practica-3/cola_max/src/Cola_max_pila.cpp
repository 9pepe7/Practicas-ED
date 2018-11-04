#include <stack>

using namespace std;

/*
Haremos uso de dos pilas que trabajarán en conjunto, una para inseriones y otra para extracciones.
*/
template <typename T>
void Cola_max::poner(T x){ // push
  in.push(x);
}
void Cola_max::quitar(){ // pop
  if(out.empty()){
    while(!in.empty()){
      out.push(in.top());
      in.pop();
    }
  }
  out.pop();
}
T Cola_max::frente(){ // front
  if(out.empty()){
    while(!in.empty()){
      out.push(in.top());
      in.pop();
    }
  }
  return out.top();
}
bool Cola_max::vacia(){ // empty
  bool res=true;
  if(!in.empty())
    res=false;
  if(!out.empty())
    res=false;
  return res;
}
int Cola_max::num_elementos(){ // size
  return (in.size()+out.size());
}
