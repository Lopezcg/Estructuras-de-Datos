#ifndef N_Q_H
#define N_Q_H


#include <iostream>
#include <list>

class  Nodo
{
    protected:
      int valor;
      Nodo* hijo1;
      Nodo* hijo2;
      Nodo* hijo4;
      Nodo* hijo3;

    public:
      Nodo();
      Nodo(int val);
      ~Nodo();
      int getValor();
      void setValor(int val);
      Nodo* getHijo1();
      Nodo* getHijo2();
      Nodo* getHijo3();
      Nodo* getHijo4();
      void setHijo1(Nodo* sizq);
      void setHijo2(Nodo* sder);
      void setHijo4(Nodo* iizq);
      void setHijo3(Nodo* ider);
      bool esHoja();
      bool estaCompleto();
};

#include "nodo.hxx"

#endif