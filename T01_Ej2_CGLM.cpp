#include <iostream>
//Carlos Gabriel Lopez Medina
//Estructuras de datos 2023-01 taller 01 ejercicio 2
using namespace std;
//Estructura cliente
struct cliente{
  string nombre;
  long cedula;
  string direccion;
  string compra;
  string metodopago;
  cliente *sig;
  
};
typedef cliente *LISTA;
void mostrar_lista(LISTA ptr);
void insertar(LISTA &ptr,string nombre, long cedula, string direccion, string compra, string metodopago);
int main() {
  int opcion;
  string nombre,direccion,compra,metodopago;
  long cedula;
  LISTA clientes=NULL;
  do{
    cout<<"\nPara insertar un cliente digite 1, para terminar digite 0: "<<endl;
    cin>>opcion;
    if(opcion==1){
      cout<<"Nombre del cliente: "<<endl;
      cin>>nombre;
      cout<<"Cedula : "<<endl;
      cin>>cedula;
      cout<<"Direccion: "<<endl;
      cin>>direccion;
      cout<<"Compra: "<<endl;
      cin>>compra;
      cout<<"Metodo de pago: "<<endl;
      cin>>metodopago;
      insertar(clientes, nombre,  cedula,  direccion, compra, metodopago);
      
      
    }
  }while(opcion==1);
  cout<<"\nLa lista de clientes es: ";
  mostrar_lista(clientes);
  
  
  
}
void insertar(LISTA &ptr,string nombre, long cedula, string direccion, string compra, string metodopago)  {
  LISTA p1, p2;
  p1 = ptr;
  if (p1 == NULL) // si la Lista esta vacia
   {
    p1 = new cliente;
    p1->nombre = nombre;
     p1->cedula = cedula;
     p1->direccion= direccion;
     p1->compra = compra;
     p1->metodopago = metodopago;
     p1->sig = NULL;
     ptr = p1;
   }
   else
   {
    while(p1->sig != NULL)
    p1 = p1->sig;
    p2 = new cliente;
    p2->nombre = nombre;
     p2->cedula = cedula;
     p2->direccion= direccion;
     p2->compra = compra;
     p2->metodopago = metodopago;
    p2->sig = NULL;
    p1->sig = p2;//se asigna como siguiente del p1 el p2
    }
   

}
void mostrar_lista(LISTA ptr) {
while(ptr != NULL)//Se imprimen los datos siempre y cuando la lista no sea null
{
cout <<"Nombre: "<<ptr->nombre << " "<<"Cedula: "<<ptr->cedula<<" "<<"Direccion: "<<ptr->direccion<<" "<<"Compra: "<<ptr->compra<<" "<<"Metodo de pago: "<<ptr->metodopago<<endl;
  cout<<"******************************************"<<endl;
  
ptr = ptr->sig;
}
cout << endl;
}
