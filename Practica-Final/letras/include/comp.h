#ifndef COMP_H
#define COMP_H

#include <string>
using namespace std;

struct comp{
  bool menor(const char& c1, const char& c2) const{
    if( (c1>='a'&&c1<='n') || (c1>='A'&&c1<='N') ) //c1 <ñ
      return ( (c2>='a'&&c2<='n') || (c2>='A'&&c2<='N') )?c1<c2:true;
    else {
      if((c1>='o'&&c1<='z') || (c1>='O'&&c1<='Z')) // c1 >ñ
        return ((c2>='o'&&c2<='z') || (c2>='O'&&c2<='Z'))?c1<c2:false;
      else // c1=ñ
        return ((c2>='a'&&c2<='n') || (c2>='A'&&c2<='N'))?false:true;
    }
  }
  bool operator() (const string& s1, const string& s2) const{
    for(unsigned i=0; i<s1.length() && i<s2.length(); ++i){
      if(s1[i]!=s2[i]){
        return menor(s1[i],s2[i]);
      }
    }
    return (s1.length()<s2.length());
  }
  bool operator() (const char& c1, const char& c2) const{
    return menor(c1,c2);
  }
};
#endif
