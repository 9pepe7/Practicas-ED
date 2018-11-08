#ifndef PILA_MAX_H
#define PILA_MAX_H
#include <stack>
using namespace std;
template <class T>
class PilaMax{
private:
  stack< pair<T,T> > pila;
public:
  void push(T x);
  void pop();
  pair<T,T> top();
  bool empty();
  int size();
};
#include "PilaMax.cpp"
#endif
