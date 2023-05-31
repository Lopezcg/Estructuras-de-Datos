#ifndef Q_NODO_HXX
#define Q_NODO_HXX

#include "nodo.h"

  Nodo::Nodo()
  {
     this->valor =0;
     this->hijo1=NULL;
     this->hijo2=NULL;
     this->hijo3=NULL;
     this->hijo4=NULL;
  }

  Nodo::Nodo(int val)
  {
    this->setValor(val);
    this->hijo1=NULL;
     this->hijo2=NULL;
     this->hijo3=NULL;
     this->hijo4=NULL;
  }

  //mirar
  Nodo::~Nodo()
  {
     this->hijo1=NULL;
     this->hijo2=NULL;
     this->hijo3=NULL;
     this->hijo4=NULL;
  }

  void Nodo::setValor(int val)
  {
    this->valor= val;
  }

  int Nodo::getValor()
  {
    return this->valor;
  }

  Nodo* Nodo::getHijo1()
  {
     return this->hijo1;
  }
  
  Nodo* Nodo::getHijo2()
  {
     return this->hijo2;  
  }

  Nodo* Nodo::getHijo3()
  {
     return this->hijo3;    
  }

  Nodo* Nodo::getHijo4()
  {
     return this->hijo4;    
  }

  void Nodo::setHijo1(Nodo* sizq)
  {
     this->hijo1=sizq;
  }

  void Nodo::setHijo2(Nodo* sder)
  {
     this->hijo2=sder;  
  }

  void Nodo::setHijo3(Nodo* ider)
  {
     this->hijo3=ider;    
  }

  void Nodo::setHijo4(Nodo* iizq)
  {
     this->hijo4=iizq;
  }

  bool Nodo::esHoja()
  {
     return this->hijo3==NULL && this->hijo4==NULL && this->hijo2==NULL && this->hijo1==NULL;
  }

 bool Nodo::estaCompleto()
  {
    if(this->hijo1!=NULL && this->hijo2!=NULL && this->hijo3!=NULL && this->hijo4!=NULL) {
      if (this->hijo1->valor!=2 && this->hijo2->valor!=2 && this->hijo3->valor!=2 && this->hijo4->valor!=2){
        return true;
      }
        return false;
    }
    return false;
      
      
      
  }


#endif