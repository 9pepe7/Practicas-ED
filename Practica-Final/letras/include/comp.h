#ifndef COMP_H
#define COMP_H

#include <string>
#include <ctype.h> // tolower
using namespace std;

struct comp{ // Estructura para ordenacion de char y string que funciona con la ñ
  bool menor(const char& c1, const char& c2) const{ // return true si c1 es anterior alfabeticamente a c2
    if( tolower(c1)>='a' && tolower(c1)<='n' ) // c1<ñ
      return ( tolower(c2)>='a' && tolower(c2)<='n' ) ? (c1<c2) : true; // if(c2<ñ) then
    else {
      if( tolower(c1)>='o' && tolower(c1)<='z' ) // c1>ñ
        return ( tolower(c2)>='o' && tolower(c2)<='z') ? (c1<c2) : false; // if(c2>ñ) then
      else // c1==ñ
        return ( tolower(c2)>='a' && tolower(c2)<='n' ) ? false : true; // if(c2<ñ) then
    }
  }
  bool operator() (const string& pal1, const string& pal2) const{
    for(unsigned i=0; i<pal1.length() && i<pal2.length(); ++i){
      if( pal1[i]!=pal2[i] )
        return menor( pal1[i],pal2[i] );
    }
    return ( pal1.length()<pal2.length() );
  }
  bool operator() (const char& c1, const char& c2) const{
    return menor(c1,c2);
  }
};
#endif
