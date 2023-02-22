#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>
using namespace std;
//Programa realizado por Carlos Gabriel Lopez Medina
// Estructuras de datos PUJ TALLER 02

//Definicion estructuras
struct Cancion
{
    string nombre;
    string genero;
};

struct Album
{
    string nombre;
    string ano;
    vector <Cancion> canciones;
};

struct Autor
{
    string nombre;
    vector<Album> albums;


};
vector<Autor> leerarchivo();
void listarautores(vector<Autor> autores);
void cancionesaut(vector<Autor> a, string name);
void listaralbumes(vector<Autor> a);
void listaranombr(vector<Autor> a,string name);
void listarcanciyalb(vector<Autor> a);
int main()
{

    vector<Autor> autores;
    autores=leerarchivo();
    string buscar;
    int opcion;
    do
    {
        cout<<"  MENU "<<endl;
        cout<<"1.Listar todos los autores presentes, ordenados alfabeticamente."<<endl;
        cout<<"2.Dado un autor, listar todas sus canciones ordenadas alfabeticamente."<<endl;
        cout<<"3.Listar todos los albumes presentes, ordenados cronologicamente. " <<endl;
        cout<<"4.Dado un album, listar todas las canciones que componen un album, ordenadas alfabeticamente por el nombre de la cancion."<<endl;
        cout<<"5.Listar todas las canciones y su album, ordenadas alfabeticamente primero por el album y después por el nombre de la cancion."<<endl;
        cout<<"6.salir"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            listarautores(autores);
            break;
        case 2:

            cout<<"Ingrese el nombre del autor: ";
            cin>>buscar;
            cancionesaut(autores, buscar);
            break;
        case 3:
            listaralbumes(autores);

            break;
        case 4:
             cout<<"Ingrese el nombre del Album: ";
            cin>>buscar;
            listaranombr( autores, buscar);
            break;
        case 5:
            listarcanciyalb(autores);
            break;
        case 6:
            exit(1);
            break;
        default:
            cout<<"Opcion no valida,por favor digitela nuevamente" <<endl;
            break;
        }

    }
    while(opcion !=6);



    return 0;
}
//Funcion para leer el archivo
vector<Autor> leerarchivo()
{
    ifstream myfile ("example1.txt");
    vector<Autor> autores;
    string line;
    if (myfile.is_open())
    {

        getline(myfile,line);
        int n= stoi(line);
        for(int i=0; i<n; i++)
        {

            Autor aux;
            Album aux2;
            Cancion aux3;
            bool hallado=false,hallado2=false;
            cout<<"a";

            string cancnom,cancgenero;
            getline(myfile,line);
            stringstream  ss(line);
            getline(ss,aux3.nombre,'|');
            getline(ss,aux.nombre,'|');
            getline(ss,aux3.genero,'|');
            getline(ss,aux2.nombre,'|');
            getline(ss,aux2.ano,'|');
            if(autores.empty())
            {

                aux2.canciones.push_back(aux3);
                aux.albums.push_back(aux2);
                autores.push_back(aux);

            }
            else
            {

                for(int j=0; j<autores.size(); j++)
                    if(aux.nombre==autores[j].nombre)
                    {

                        hallado=true;
                        if(autores[j].albums.empty())
                        {
                            aux2.canciones.push_back(aux3);
                            autores[j].albums.push_back(aux2);
                        }
                        else
                        {
                            for(int a=0; a<autores[j].albums.size(); a++)
                            {
                                if(aux2.nombre==autores[j].albums[a].nombre)
                                {
                                    hallado2=true;
                                    autores[j].albums[a].canciones.push_back(aux3);
                                }
                            }
                            if(!hallado2)
                            {
                                aux2.canciones.push_back(aux3);
                                autores[j].albums.push_back(aux2);
                            }
                        }
                    }

                if (!hallado)
                {
                    aux2.canciones.push_back(aux3);
                    aux.albums.push_back(aux2);
                    autores.push_back(aux);
                }
            }

        }




        myfile.close();
        return  autores;
    }


    else {cout <<"No se puede abrir el archivo";}

    return autores;
}
//Funcion listar autores
void listarautores(vector<Autor> autores){
     sort(autores.begin(),autores.end(), [](const Autor& a, const Autor& b) // Se organiza el vector alfabeticamente mediante la variable nombre
          {
        return a.nombre < b.nombre;
    });

 for(int i=0;i<autores.size();i++){
        cout<<autores[i].nombre<<endl;

 }
}
//Funcion listar canciones de autores
void cancionesaut(vector<Autor> a, string name){
    vector<Cancion> canciones;

  for(int i =0 ;i<a.size();i++){

    if(a[i].nombre==name){
            for(int j=0;j<a[i].albums.size();j++)
            {
                 for(int d=0;d<a[i].albums[j].canciones.size();d++){
                    canciones.push_back(a[i].albums[j].canciones[d]);
                 }

            }
    }

    }
    sort(canciones.begin(),canciones.end(), [](const Cancion& a, const Cancion& b) {
        return a.nombre < b.nombre;
    });



   for (const Cancion& elemento : canciones) {
        std::cout << elemento.nombre<< " "<<elemento.genero<<endl;
    }
  }
  //Funcion listar albumes
  void listaralbumes(vector<Autor> a){
      vector<Album> albums;


  for(int i =0 ;i<a.size();i++){
            for(int j=0;j<a[i].albums.size();j++)
            {
                 albums.push_back(a[i].albums[j]);

            }

    }
    sort(albums.begin(),albums.end(), [](const Album& a, const Album& b) {
        return a.ano< b.ano;
    });



   for (const Album& elemento : albums) {
        std::cout << elemento.nombre<< " "<<elemento.ano<<endl;
    }

  }
  //funcion listar todas las canciones de un album dado
void listaranombr(vector<Autor> a,string name){
 Album album;

  for(int i =0 ;i<a.size();i++){

            for(int j=0;j<a[i].albums.size();j++)
            {
                if(a[i].albums[j].nombre==name){
                        album=a[i].albums[j];
                }

            }


    }
    sort(album.canciones.begin(),album.canciones.end(), [](const Cancion& a, const Cancion& b) {
        return a.nombre < b.nombre;
    });



   for (const Cancion& elemento : album.canciones) {
        std::cout << elemento.nombre<< " "<<elemento.genero<<endl;
    }
}
//funcion listar alfabeticamente albumes y canciones
void listarcanciyalb(vector<Autor> a){
 vector<Album> album;


  for(int i =0 ;i<a.size();i++){
            for(int j=0;j<a[i].albums.size();j++)
            {
                 album.push_back(a[i].albums[j]);

            }

    }
    sort(album.begin(),album.end(), [](const Album& a, const Album& b) //ordena los albumes
         {
        return a.nombre< b.nombre;
    });
    for(int s=0;s<album.size();s++){
        sort(album[s].canciones.begin(),album[s].canciones.end(), [](const Cancion& a, const Cancion& b)//ordena las canciones
             {
        return a.nombre< b.nombre;
    });
    }



   for (int k=0;k<album.size();k++){
    for(int n=0;n<album[k].canciones.size();n++){
        cout<<album[k].nombre<<" "<<album[k].canciones[n].nombre<<" "<<album[k].canciones[n].genero<<endl;
    }
   }
}

