#include <iostream>

#include "quadt.h"

#include <array>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
Quadtree quadtree;
int tamano;

// Verifica los argumentos que se reciben por la linea de comandos
bool verificaciones(int argc, char *argv[]);

// Realiza la lectura del archivo de texto
bool leerArchivo(string archivo_texto);

// Escribe el archivo PBM
void escribirArchivo(string archivo_pbm);

int main(int argc, char *argv[]) {
  // Se realizan las verificaciones de los argumentos
  if (!verificaciones(argc, argv)) {
    return 1;
  }
  // Variables con el nombre de los archivos
  string archivo_texto = argv[1];
  string archivo_pbm = argv[2];

  // Se realiza la lectura del archivo de texto
  leerArchivo(archivo_texto);

  // Se crea el archivo pbm con la imagen
  escribirArchivo(archivo_pbm);
  cout<<"\nImagen creada con exito";
  return 0;
}

bool verificaciones(int argc, char *argv[]) {
  // Se verifica la cantidad de argumentos
  if (argc != 3) {
    cout << "\nError: No se inserto la cantidad de argumentos correcta.\n Formato correcto: ./programa nombre_archivotexto.txt nombre_imagen.pbm";
    return false;
  }
  // Variables con el nombre de los archivos
  string archivo_texto = argv[1];
  string archivo_pbm = argv[2];

  // Se verifica que los archivos aparte de la extension tengan un nombre
  if (!(archivo_texto.length() >= 3)) {
    cout << "\nError: el archivo de entrada no tiene nombre o la extension es "
            "incorrecta.\n Formato correcto: ./programa nombre_archivotexto.txt nombre_imagen.pbm";
  }
  if (!(archivo_pbm.length() >= 4)) {
    cout << "\nError: el archivo de salida no tiene nombre o la extension es "
            "incorrecta.\n Formato correcto: ./programa nombre_archivotexto.txt nombre_imagen.pbm";
  }

  // Se verifica que el archivo de texto tenga extension .txt o .qt
  if (!(archivo_texto.substr(archivo_texto.length() - 4) == ".txt") &&
      !(archivo_texto.substr(archivo_texto.length() - 3) == ".qt")) {
    cout << "\nError: El archivo de entrada, no tiene extension .txt o .qt.";
    return false;
  }

  // Se verifica que el archivo de texto tenga extension .pbm o .pgm
  if (!(archivo_pbm.substr(archivo_pbm.length() - 4) == ".pgm") &&
      !(archivo_pbm.substr(archivo_pbm.length() - 4) == ".pbm")) {
    cout << "\nError: El archivo de salida no tiene extension .pbm o .pgm.";
    return false;
  }
  return true;
}

bool leerArchivo(string archivo_texto) {

  // Se crea el canal de lectura
  ifstream file(archivo_texto);

  // Se verifica que se pueda abrir el archivo
  if (!file.is_open()) {
    cout << "\nError: No se pudo abrir archivo";
    return false;
  }

  // Se verifica que el archivo no este vacio
  if (sizeof(file) == 0) {
    cout << endl << endl << "Error: El archivo esta vacio";
    return false;
  }

  string linea, alturaS, anchoS, preOrden, valorS;
  int altura, ancho, valor;

  
  getline(file, linea);
  stringstream linea1(linea);
  getline(linea1, anchoS, ' ');
  getline(linea1, alturaS, ' ');

  
  getline(file, linea);
  stringstream linea2(linea);
  getline(linea2, preOrden, ' ');
  try {
    
    altura = stoi(alturaS);
    ancho = stoi(anchoS);
    
    for (int i = 0; i < preOrden.length(); i++) {
      valorS = preOrden.at(i);
      valor = stoi(valorS);
      
      if (!(valor == 0) && !(valor == 1) && !(valor == 2)) {
        cout << "\nError: el preOrden incluye valores no validos";
        return false;
      }
      
      quadtree.insertar(valor);
    }
    tamano = altura;

  } catch (const ::invalid_argument &) {
    cout << "\nError: El archivo contiene caracteres no numericos";
  }

  file.close();
  return true;
}

void escribirArchivo(string archivo_pbm) {
 
  vector<std::vector<int>> imagen(tamano, vector<int>(tamano));

  
  quadtree.llenarMatriz(imagen, tamano);

 
  ofstream file(archivo_pbm);

  
  file << "P1\n";
 
  file << "#Esta es una imagen de prueba\n";
  
  file << tamano << " " << tamano << "\n";


  for (int i = 0; i < tamano; i++) {
    for (int j = 0; j < tamano; j++) {
      file << imagen[i][j] << " ";
    }
    file << "\n";
  }

  file.close();
}