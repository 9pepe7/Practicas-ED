#include<iostream>
#include<fstream>
#include"Vector_Dinamico.h"
#include"Diccionario.h"
#include"Termino.h"

using namespace std;

  Diccionario::Diccionario()
  {
    tamanio = 0;
  }

  Diccionario::Diccionario(Vector_Dinamico<Termino> vec)
  {
    dicc = vec;
    tamanio = dicc.size();
  }

  Diccionario::Diccionario( const Diccionario& d):dicc(d.getTam())
  {
    for(int i = 0; i<tamanio; i++)
      dicc[i] = d.getTermino(i);
  }

  int Diccionario::getTam() const
  {
    return tamanio;
  }

  string Diccionario::getPalabra(int i)
  {
    return dicc[i].getPalabra();
  }

  void Diccionario::ordena()
  {
    Termino temp;
    for (int i = 0; i < tamanio; i++)
    {
      for (int j = i +1; j < tamanio; j++)
      {
        if( getTermino(j) < getTermino(i) )
        {
          temp = getTermino(j);
          getTermino(j) = getTermino(i);
          getTermino(i) = temp;
        }
      }
    }

  }

  Vector_Dinamico<string> Diccionario::getDefiniciones(string p)
  {
    Vector_Dinamico<string> temp;
    for(int i = 0; i < tamanio; i++)
    {
      if(p == dicc[i].getPalabra())
        temp = dicc[i].getDefiniciones();
    }
    return temp;
  }

  Vector_Dinamico<string> Diccionario::getDefiniciones(int i)
  {
    return dicc[i].getDefiniciones();
  }

  Vector_Dinamico<Termino> Diccionario::getTerminos()
  {
    return dicc;
  }



  Termino Diccionario::getTermino(int i) const
  {
    return dicc[i];
  }

  void Diccionario::nuevoTermino(Termino t)
  {
    tamanio++;
    dicc.resize(tamanio);
    dicc[tamanio - 1] = t;
    //ordena();
  }

  int Diccionario::buscarTermino(Termino t)
  {
    int j = -1;
    for (int i = 0; i < tamanio; i++)
    {
      if ( t == getTermino(i) )
        j = i;
    }
    return j;

  }

  int Diccionario::buscarPalabra(string p)
  {
    int j = -1;
    bool salir = false;
    for (int i = 0; i < tamanio && !salir ; i++)
    {
      if ( p == getTermino(i).getPalabra() )
      {
        j = i;
        salir = true;
      }
    }
    return j;

  }

  void Diccionario::eliminaTermino(Termino t)
  {
    for ( int i = buscarTermino(t); i < tamanio; i++)
    {
      dicc[i] = dicc[i+1];
    }
    tamanio--;
    dicc.resize(tamanio);
  }

  int Diccionario::recuentoDefiniciones()
  {
    int r = 0;
    for (int i=0; i < tamanio; i++)
    {
      r += dicc[i].getTamanio();
    }
    return r;
  }

  int Diccionario:: maximoDefiniciones()
  {
    int r = 0;
    for (int i=0; i < tamanio; i++)
    {
      if (dicc[i].getTamanio() > r)
        r = dicc[i].getTamanio();
    }
    return r;

  }

  double Diccionario::promedioDefiniciones()
  {
    double r = 0;
    for (int i=0; i < tamanio; i++)
    {
        r += dicc[i].getTamanio();
    }
    return r/tamanio;
  }


  Diccionario Diccionario::filtrarIntervalo(char ini, char fin){
    Diccionario d;
    int begin, end, i = 0;

    if(ini >= 'A' && ini <= 'Z')
      ini+=32;
    if(fin >= 'A' && fin <= 'Z')
      fin+=32;

    if(ini > fin){
      char t = ini;
      ini = fin;
      fin = t;
    }

    while(dicc[i].getPalabra()[0] != ini && i < tamanio)
      i++;
    begin = i;

    if(fin != 'z'){
      fin++;
      while(dicc[i].getPalabra()[0] != fin && i < tamanio)
        i++;
      end = i;
    } else{
      end = tamanio-1;
    }

    for(int j = begin; j < end; ++j){
      d.nuevoTermino(dicc[j]);
    }
    return d;
  }

  void Diccionario::aniadirDefinicion(int i, string def)
  {
    dicc[i].AniadirDefinicion(def);
  }



  Diccionario Diccionario::filtrarClave(const string clave)
  {
    Diccionario d;
    for(int i = 0; i < tamanio; ++i){
      Termino ter = dicc[i];
      for(int j=0; j<ter.getTamanio(); ++j){
        size_t premio = ter.getDefinicion(j).find(clave);
        if (premio!=string::npos){
          int x = d.buscarPalabra(ter.getPalabra());
          if(x == -1){
            Termino nuevo (ter.getPalabra(),ter.getDefinicion(j));
            d.nuevoTermino(nuevo);
          } else {
            d.aniadirDefinicion(x, ter.getDefinicion(j));
          }
        }
      }
    }
    return d;
  }


  ostream& operator<<(ostream & flujo, const Diccionario &d)
  {
    for( int i = 0; i < d.getTam(); i++ )
    {
      flujo << d.getTermino(i);
    }
    return flujo;
  }

  istream& operator>>(istream & flujo, Diccionario &d)
  {
    while(!flujo.eof())
    {
      Termino t;
      flujo >> t;
      int x = d.buscarPalabra(t.getPalabra());
      if(x == -1){
        d.nuevoTermino(t);
      } else {
        d.aniadirDefinicion(x, t.getDefinicion(0));
      }
    }
    return flujo;
  }
