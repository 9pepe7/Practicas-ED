#ifndef COMP_H
#define COMP_H

#include <string>
using namespace std;

struct comp{ // Estructura para ordenacion de char y string que funciona con la ñ
  bool menor(const char& c1, const char& c2) const;
  bool operator() (const string& pal1, const string& pal2) const;
  bool operator() (const char& c1, const char& c2) const;
};
#endif
