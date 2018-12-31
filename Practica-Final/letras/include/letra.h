#ifndef LETRA_H
#define LETRA_H

#include <set>
#include <vector>
#include <string>

using namespace std;

class letra{
private:
  char caracter;
  int cantidad;
  int puntuacion;
public:
  letra();
  friend istream & operator>>(istream & is, letra &L);
  friend ostream & operator<<(ostream & os, const letra &L);
  bool operator < (const letra &l) const;
};
#endif
