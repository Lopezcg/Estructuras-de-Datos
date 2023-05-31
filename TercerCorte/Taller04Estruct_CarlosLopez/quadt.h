#ifndef A_Q_H
#define A_Q_H

#include "nodo.h"
#include <vector>

class Quadtree {
protected:
  Nodo *raiz;

public:
  Quadtree();
  Quadtree(int val);
  ~Quadtree();
  int getValorRaiz();
  Nodo *getRaiz();
  void setRaiz(Nodo *nodo_raiz);
  bool esVacio();
  bool insertar(int val);
  bool insertarNodo(int nval, Nodo *nodo);
  void preOrden();
  void preOrden(Nodo *nodo);
  void inOrden();
  void inOrden(Nodo *nodo);
  void posOrden();
  void posOrden(Nodo *nodo);
  void nivelOrden();
  void llenarMatriz(std::vector<std::vector<int>> &imagen, int tamano);
  void llenarMatriz(Nodo *nodo, std::vector<std::vector<int>> &imagen,
                    int tamano, int inicioI, int inicioJ);
};

#include "quadt.hxx"

#endif