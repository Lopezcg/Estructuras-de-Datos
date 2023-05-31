#ifndef Q_Arbol_HXX
#define Q_Arbol_HXX

#include "quadt.h"
#include <queue>
#include <vector>

using namespace std;

Quadtree::Quadtree() { this->raiz = NULL; }

Quadtree::Quadtree(int val) {
  Nodo *nodo = new Nodo (val);
  this->raiz = nodo;
}

Quadtree ::~Quadtree() {
  if (this->raiz != NULL) {
    delete this->raiz;
    this->raiz = NULL;
  }
}

int Quadtree ::getValorRaiz() { return (this->raiz)->getValor(); }

Nodo *Quadtree ::getRaiz() { return this->raiz; }

void Quadtree ::setRaiz(Nodo *nodo_raiz) { this->raiz = nodo_raiz; }

bool Quadtree ::esVacio() { return this->raiz == NULL; }

bool Quadtree::insertar(int val) {

  bool estaInsertado = false;

  if (this->raiz == NULL) {
    Nodo *nodo = new Nodo(val);
    this->raiz = nodo;
    estaInsertado = true;
  } else {
    estaInsertado = insertarNodo(val, this->raiz);
  }

  return estaInsertado;
}

bool Quadtree::insertarNodo(int nval, Nodo *nodo) {

  if (nodo==NULL){
    return false;
  }
  
  if (nodo->estaCompleto()) {
    return false;
  }

  bool estaInsertado = false;
  // si es hoja se ingesa
  if (nodo->getHijo1() == NULL) {
    Nodo *nuevo = new Nodo (nval);
    nodo->setHijo1(nuevo);
    estaInsertado = true;
  }
  // si es dos y no esta lleno
  else if (nodo->getHijo1()->getValor() == 2 &&
           !nodo->getHijo1()->estaCompleto()) {
    estaInsertado = insertarNodo(nval, nodo->getHijo1());
  }

  if (!estaInsertado){
    // si es hoja se ingesa
    if (nodo->getHijo2() == NULL) {
      Nodo *nuevo = new Nodo (nval);
      nodo->setHijo2(nuevo);
      estaInsertado = true;
    }
    // si es dos y no esta lleno
    else if (nodo->getHijo2()->getValor() == 2 &&
             !nodo->getHijo2()->estaCompleto()) {
      estaInsertado = insertarNodo(nval, nodo->getHijo2());
    }
  }

  if (!estaInsertado){
    
    if (nodo->getHijo3() == NULL) {
      Nodo *nuevo = new Nodo (nval);
      nodo->setHijo3(nuevo);
      estaInsertado = true;
    } else if (nodo->getHijo3()->getValor() == 2 &&
               !nodo->getHijo3()->estaCompleto()) {
      estaInsertado = insertarNodo(nval, nodo->getHijo3());
    }
  }

  if (!estaInsertado){
    
    if (nodo->getHijo4() == NULL) {
      Nodo *nuevo = new Nodo (nval);
      nodo->setHijo4(nuevo);
      estaInsertado = true;
    } else if (nodo->getHijo4()->getValor() == 2 &&
               !nodo->getHijo4()->estaCompleto()) {
      estaInsertado = insertarNodo(nval, nodo->getHijo4());
    }
  }

  return estaInsertado;
}


void Quadtree ::preOrden() {
  if (!this->esVacio()) {
    this->preOrden(this->getRaiz());
  }
}

void Quadtree::preOrden(Nodo *nodo) {
  if (nodo != NULL) {
    cout << nodo->getValor() << " ";
    this->preOrden(nodo->getHijo1());
    this->preOrden(nodo->getHijo2());
    this->preOrden(nodo->getHijo3());
    this->preOrden(nodo->getHijo4());
  }
}

void Quadtree ::inOrden() {
  if (!this->esVacio()) {
    this->inOrden(this->raiz);
  }
}

void Quadtree ::inOrden(Nodo *nodo) {
  if (nodo != NULL) {
    this->inOrden(nodo->getHijo1());
    this->inOrden(nodo->getHijo2());
    cout << nodo->getValor() << " ";
    this->inOrden(nodo->getHijo3());
    this->inOrden(nodo->getHijo4());
  }
}

void Quadtree ::posOrden() {
  if (!this->esVacio()) {
    this->posOrden(this->raiz);
  }
}

void Quadtree ::posOrden(Nodo *nodo) {

  if (nodo != NULL) {
    this->posOrden(nodo->getHijo1());
    this->posOrden(nodo->getHijo2());
    this->posOrden(nodo->getHijo3());
    this->posOrden(nodo->getHijo4());
    cout << nodo->getValor() << " ";
  }
}

void Quadtree ::nivelOrden() {
  if (!this->esVacio()) {
    queue<Nodo *> aux;

    aux.push(this->getRaiz());

    while (!aux.empty()) {
      cout << aux.front()->getValor() << " ";

      if (aux.front()->getHijo1() != NULL)
        aux.push(aux.front()->getHijo1());

      if (aux.front()->getHijo2() != NULL)
        aux.push(aux.front()->getHijo2());

      if (aux.front()->getHijo3() != NULL)
        aux.push(aux.front()->getHijo3());

      if (aux.front()->getHijo4() != NULL)
        aux.push(aux.front()->getHijo4());

      aux.pop();
    }
  }
}

void Quadtree ::llenarMatriz(vector<vector<int>> &imagen, int tamano) {
  if (!this->esVacio()) {
    this->llenarMatriz(this->getRaiz(), imagen, tamano, 0, 0);
  }
}


void Quadtree::llenarMatriz(Nodo *nodo, vector<vector<int>> &imagen, int tamano,
                         int inicioI, int inicioJ) {
  if (nodo==NULL){
    return;
  }
 
  if (nodo->getValor() == 2){
    this->llenarMatriz(nodo->getHijo1(), imagen, tamano/2, inicioI, inicioJ);
    this->llenarMatriz(nodo->getHijo2(), imagen, tamano/2, inicioI,
                      inicioJ + tamano/2);
    this->llenarMatriz(nodo->getHijo3(), imagen, tamano/2,
                      inicioI + tamano/2, inicioJ + tamano/2);
    this->llenarMatriz(nodo->getHijo4(), imagen, tamano/2,
                      inicioI + tamano/2, inicioJ);
  } else {
    //Se rellena el espacio de la matriz con 1 o 0 dependiendo del valor
    int valor = nodo->getValor();
    for (int i = inicioI; i < inicioI + tamano; i++) {
      for (int j = inicioJ; j < inicioJ + tamano; j++) {
        imagen[i][j] = valor;
      }
    }
  }
}

#endif