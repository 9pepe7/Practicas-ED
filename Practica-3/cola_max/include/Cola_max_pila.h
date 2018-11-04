#include <stack>

using namespace std;

/*
Haremos uso de dos pilas que trabajarán en conjunto, una para inseriones y otra para extracciones.
*/
template <class T>
class Cola_max{
private:
  stack<T> in;
  stack<T> out;
public:
  void poner(T x);
  void quitar();
  T frente();
  bool vacia();
  int num_elementos();
};
