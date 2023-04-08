#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class avl {
public:
  int valor, altura;
  avl *derecha;
  avl *izquierda;
  avl(int v) {
    valor = v;
    altura = 1;
    derecha = nullptr;
    izquierda = nullptr;
  }
  int factorbalanceo() { return izquierda->altura - derecha->altura; }

  void actalt() { altura = max(izquierda->altura, derecha->altura); }
  avl *rotarizq() {
    avl *pivot = derecha;
    derecha = pivot->izquierda;
    pivot->izquierda = this;
    actalt();
    pivot->actalt();
    return pivot;
  }
  avl *rotarder() {
    avl *pivot = izquierda;
    izquierda = pivot->derecha;
    pivot->derecha = this;
    actalt();
    pivot->actalt();
    return pivot;
  }
  bool balanceo() {
    if(izquierda==nullptr || derecha==nullptr){
      return false;
    }
    if (factorbalanceo() > 1) {
      if (izquierda->factorbalanceo() < 0) {
        izquierda = izquierda->rotarizq();
      }
      return rotarder();
    }
    if (factorbalanceo() < -1) {
      if (derecha->factorbalanceo() > 0) {
        derecha = derecha->rotarder();
      }
      return rotarizq();
    }
    return true;
  }

  bool insertar(int v) {
    
    avl* nodo = new avl(v);
    if (nodo->valor >valor) {
      if (derecha != nullptr) {
        return derecha->insertar(v);

      } else{
        
        derecha = nodo;
          return true;
      }
      
    }
    if (nodo->valor < valor) {
      if (izquierda != nullptr) {
        return izquierda->insertar(v);

      } else{
        izquierda = nodo;
          return true;
      }
    }
    balanceo();
    return true;
  }

    avl *eliminar(int v) {
        if (valor == v) {
            if (izquierda == nullptr && derecha == nullptr) {
                delete this;
                return nullptr;
            }
            if (izquierda == nullptr) {
                avl *temp = derecha;
                delete this;
                return temp;
            }
            if (derecha == nullptr) {
                avl *temp = izquierda;
                delete this;
                return temp;
            }
            avl *temp = derecha;
            while (temp->izquierda != nullptr) {
                temp = temp->izquierda;
            }
            valor = temp->valor;
            derecha = derecha->eliminar(temp->valor);
        } else if (valor < v) {
            if (derecha != nullptr) {
                derecha = derecha->eliminar(v);
            }
        } else {
            if (izquierda != nullptr) {
                izquierda = izquierda->eliminar(v);
            }
        }
        balanceo();
        return this;
    }
  void imprimirOrden(avl *nodo) {
    if (nodo != nullptr) {
      imprimirOrden(nodo->izquierda);
      cout << nodo->valor << " ";
      imprimirOrden(nodo->derecha);
    }
  }
int tamano(avl* nodo){
if (nodo == nullptr) {
        return 0;
    }
    return 1 + tamano(nodo->izquierda) + tamano(nodo->derecha);
}
avl* nth_node(avl* nodo, int n) {
    int tam = tamano(nodo->izquierda) + 1;
    if (n < tam) {
        return nth_node(nodo->izquierda, n);
    }
    else if (n > tam) {
        return nth_node(nodo->derecha, n - tam);
    }
    else {
        return nodo;
    }
}

double mediana() {
    int tam = tamano(this);
    if (tam % 2 == 0) { // tamaño par
        avl* n1 = nth_node(this, tam / 2);
        avl* n2 = nth_node(this, tam / 2 + 1);
        return (n1->valor + n2->valor) / 2.0;
    }
    else { // tamaño impar
        avl* n = nth_node(this, tam / 2 + 1);
        return n->valor;
    }
}






};
int main() {
  avl *root = new avl(5000);
  ifstream archivo("entrada.txt");
  string line,word;
  char delimitador=' ';
  int contador=1;
  
  int valor;
  if(!archivo){
    cout<<"No se pudo abrir el archivo";
  }else{
  while(getline(archivo,line)){
    stringstream str(line);
    
    getline(str, word, delimitador);
    if(word=="A"){
      contador+=1;
      
      getline(str, word, delimitador);
      valor=stoi(word);
      root->insertar(valor);
    }
    if(word=="E"){
      contador-=1;
      getline(str, word, delimitador);
      valor=stoi(word);
      root->eliminar(valor);
      contador-=1;
    }
  }
  }
  cout<<"\nMediana:"<<root->mediana();
  if(root->tamano(root)%2==0)
  {
   cout<<"\nValores Medios:"<<root->nth_node(root, root->tamano(root)/2)->valor<<" y "<<root->nth_node(root,(root->tamano(root)/2)+1)->valor;}
  else{
   cout<<"\nValor Medio:"<<root->nth_node(root, root->tamano(root)/2)->valor;
  }
  
  cout<<"\nTamano:"<<root->tamano(root);
  
 
 
  
  
  
  
  
}