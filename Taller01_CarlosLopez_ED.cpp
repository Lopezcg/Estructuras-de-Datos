#include <iostream>
//Progama hecho por Carlos Gabriel Lopez Medina
//Estructuras de datos 2023-01 PUJ

using namespace std;
void Aleatorio(int vec[]);//Funcion para otorgar numeros aleatorios
void imprimirArray(int *puntero);//Funcion para imprimir el contenido del arreglo
void imprimirdirecciones(int *puntero);//Funcion para imprimir las direcciones del arreglo

int main() {
  int numeros[10],*puntero=nullptr;
  puntero=numeros;
  Aleatorio(numeros);
  
  cout<<"Contenido del arreglo";
  imprimirArray(puntero);
  
  cout<<"\nDirecciones:"<<endl;
  imprimirdirecciones(puntero);
  
  


  
  
  
  
  
}

void Aleatorio(int vec[])
{
    for(int i=0; i<10; i++)
    {
        vec[i] = 1+rand()%(26-0);
      
    }

}
void imprimirArray(int *puntero){
    for(int i=0;i<10;i++)
    {
      cout<<puntero[i]<<"|";
    }
}
void imprimirdirecciones(int *puntero){
  for(int i=0;i<10;i++)
    {
      cout<<&puntero[i]<<"|";
    }
}