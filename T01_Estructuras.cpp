// Carlos Gabriel Lopez Medina Taller 1 01/02/2023
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <wchar.h> // Soporta muchos tipos de caracteres
#include <locale.h>
#include <fstream>
#include <string.h>
using namespace std;// Soporta diferentes formatos
#define maxrutina 30
#define maxclientes 100
#define maxmeses 12
//definicion de estructuras


struct ubi
{
    char direccion[20];
    char ciudad[20];
};
struct clientess
{
    int cedula;
    char nombre[20];
    int telefono;
    ubi ubicacion;
    char horario[2];
    char sexo;
    char correoel[20];
    char pariente[20];
    float estatura;
    float peso;

    int numeroHijos;
};

struct gym
{
    int cantcli;

};
// Prototipo de las funciones
void leadatos(fstream &DGimnasio,fstream &DAfiliado);
void mostrard(fstream &DAfiliado);
void listaf(fstream &DAfiliado,fstream &DGimnasio);
void listam(fstream &DAfiliado,fstream &DGimnasio);
void lista(fstream &DAfiliado,fstream &DGimnasio);


void agregarnuevo(fstream &DAfiliado,fstream &DGimansio);
void ayudaa(fstream &DAfiliados,int buscar);


int main()
{
    fstream DAfiliado,DGimnasio;
    int opcion;
    bool entro = false;
    int codigo;


    do
    {

        cout<<"\n0.INTRODUCIR LOS DATOS BASICOS DEL GIMNASIO e INTRODUCIR DATOS COMPLETOS DE AFILIADOS ANTIGUOS POR PRIMERA VEZ. " << endl;
        cout <<"1.MOSTRAR DATOS DEL GIMNASIO"<< endl;
        cout<<"2.LISTA DE LOS AFILIADOS."<<endl;
        cout <<"3.LISTA DE AFILIADOS DE SEXO FEMENINO"<< endl ;
        cout<<"4.LISTA DE AFILIADOS DE SEXO MASCULINO"<<endl;
        cout<<"5.INGRESO DE DATOS BASICOS DE UN AFILIADO NUEVO"<<endl;

        cout <<"6. SALIR DEL PROGRAMA"<< endl ;
        cin>>opcion;
        switch (opcion)
        {
        case 0:
            if(entro==false)
            {
                entro=true;

                // Llamada a funcion para leer obras

                DGimnasio.open("DGimnasio.dat",ios::binary|ios::out);
                DAfiliado.open("DAfiliado.dat",ios::binary|ios::out);
                if(!DGimnasio || !DAfiliado)
                    cout<<"No se pudo abrir el archivo"<<endl;
                else
                    leadatos(DGimnasio,DAfiliado);
            }
            else
                cout<<"\nYa ingreso datos."<<endl;

            break;
        case 1:
            // Llamada a función para imprimir
            if(entro==false)
                cout<<"No se han ingresando datos. Seleccione la opcion '0' para ingresar datos.";
            else
            {
                DGimnasio.open("DGimnasio.dat",ios::binary|ios::in);
                if(!DGimnasio)
                    cout<<"No se pudo abrir el archivo"<<endl;
                else
                    mostrard(DGimnasio);
            }

            break;
            case 2:
            DAfiliado.open ("DAfiliado.dat",ios::binary|ios::in);
            DGimnasio.open("DGimnasio.dat",ios::binary|ios::in);
            if(!DAfiliado||!DGimnasio)
                cout<<"No se pudo abrir el archivo"<<endl;
            else
                lista(DAfiliado,DGimnasio);
            break;
        case 3:
            DAfiliado.open ("DAfiliado.dat",ios::binary|ios::in);
            DGimnasio.open("DGimnasio.dat",ios::binary|ios::in);
            if(!DAfiliado||!DGimnasio)
                cout<<"No se pudo abrir el archivo"<<endl;
            else
                listaf(DAfiliado,DGimnasio);
            break;

        case 4:
            DAfiliado.open ("DAfiliado.dat",ios::binary|ios::in);
            DGimnasio.open("DGimnasio.dat",ios::binary|ios::in);
            if(!DAfiliado||!DGimnasio)
                cout<<"No se pudo abrir el archivo"<<endl;
            else
                listam(DAfiliado,DGimnasio);

            break;

        case 5:
            DAfiliado.open ("DAfiliado.dat",ios::binary|ios::in);
            DGimnasio.open ("DGimnasio.dat",ios::binary|ios::in|ios::out);
            if(!DAfiliado)
            {
                cout<<"No se pudo abrir el archivo"<<endl;
            }
            else
            {
                agregarnuevo(DAfiliado,DGimnasio);
            }
            break;






        case 6:
            cout << "\nTermina el programa.";

            break;

        default:
            cout<< "\n Opción invalida ingrese un numero de 0 a 6"<< endl;

            break;
        }

    }
    while(opcion!=6);
}

void leadatos(fstream &DGimnasio,fstream &DAfiliado)
{
    gym elemento;
    clientess cliente;
    int ayuda;


    cout<<"\nIngrese la cantidad de clientes existentes ";
    cin>>elemento.cantcli;
    ayuda=elemento.cantcli;
    DGimnasio.write((char *)&elemento,sizeof(gym));
    for(int j=0; j<ayuda; j++)
    {
        cout<<"Para el cliente  "<<j<<endl;
        cout<<"Ingrese la cedula del afiliado :";
        cin>>cliente.cedula;
        cout<<"Ingrese el nombre del afiliado :";
        cin>>cliente.nombre;
        cout<<"Ingrese el numero de telefono del afiliado :";
        cin>>cliente.telefono;
        cout<<"Ingrese la direccion del afiliado :";
        cin>>cliente.ubicacion.direccion;
        cout<<"Ingrese la ciudad en la que vive :" ;
        cin>>cliente.ubicacion.ciudad;
        cout<<"Ingrese el horario del afiliado (AM O PM) :";
        cin>>cliente.horario;
        cout<<"Ingrese el sexo del afiliado('f' o 'm') :";
        cin>> cliente.sexo;

        cout<<"Ingrese un pariente del cliente :";
        cin>>cliente.pariente;
        cout<<"Ingrese la estatura del afiliado: ";
        cin>>cliente.estatura;
        cout<<"Ingrese el peso del afiliado :";
        cin>>cliente.peso;
        cout<<"Ingrese la cantidad de hijos del afiliado: ";
        cin>>cliente.numeroHijos;
        cout<<"Ingrese el correo electronico del afiliado: ";
        cin>>cliente.correoel;


        DAfiliado.write((char *)&cliente,sizeof(clientess));
    }

    DAfiliado.close();
    DGimnasio.close();
}
void mostrard(fstream &DGimnasio)
{
    int i=0;
    gym elemento;
    cout<<setw(10)<<" DATOS DEL GIMNASIO "<<endl;
    DGimnasio.seekg(0,ios::beg);
    DGimnasio.read((char *)&elemento, sizeof(gym));
    cout<<"CLIENTES EXISTENTES: "<<elemento.cantcli<<endl;

    DGimnasio.close();

}
void listaf(fstream &DAfiliado,fstream &DGimnasio)
{
    gym elemento;
    clientess cliente;
    int pos;
    bool hallado=false;
    cout<<" LISTA DE AFILIADOS DE SEXO FEMENINO "<<endl;
    DAfiliado.seekg(0,ios::beg);
    DAfiliado.read((char *)&cliente, sizeof(clientess));
    DGimnasio.read((char *)&elemento, sizeof(gym));

    while(!DAfiliado.eof())
    {
        if(cliente.sexo=='f')
        {
            hallado=true;
            int k=0;
            cout<<"____________________________________________________________";
            cout<<"CEDULA: "<< cliente.cedula<<endl;
            cout<<"NOMBRE: "<< cliente.nombre<<endl;
            cout<<"TELEFONO:"<<cliente.telefono<<endl;
            cout<<"CIUDAD:"<<cliente.ubicacion.ciudad<<endl;
            cout<<"DIRECCION:"<<cliente.ubicacion.direccion<<endl;
            cout<<"HORARIO:"<<cliente.horario<<endl;
            cout<<"CODIGO DE RUTINAS DEL AFILIADO:"<<endl;

            cout<<"PARIENTE:"<<cliente.pariente<<endl;

            cout<<"ESTATURA:"<<cliente.estatura<<endl;
            cout<<"PESO:"<<cliente.peso<<endl;
            cout<<"CANTIDAD DE HIJOS:"<<cliente.numeroHijos<<endl;
            cout<<"CORREO ELECTRONIC:"<<cliente.correoel<<endl;

            cout<<"____________________________________________________________";



        }
        DAfiliado.read((char *)&cliente, sizeof(clientess));

    }
    if(!hallado)
    {
        cout<<"No hay afiliados de sexo femenino.";
    }
    DAfiliado.close();
    DGimnasio.close();

}
void lista(fstream &DAfiliado,fstream &DGimnasio)
{
    gym elemento;
    clientess cliente;
    int pos;
    bool hallado=false;
    cout<<" LISTA DE AFILIADOS  "<<endl;
    DAfiliado.seekg(0,ios::beg);
    DAfiliado.read((char *)&cliente, sizeof(clientess));
    DGimnasio.read((char *)&elemento, sizeof(gym));

    while(!DAfiliado.eof())
    {

       hallado=true;
            cout<<"____________________________________________________________";
            cout<<"CEDULA: "<< cliente.cedula<<endl;
            cout<<"NOMBRE: "<< cliente.nombre<<endl;
            cout<<"TELEFONO:"<<cliente.telefono<<endl;
            cout<<"CIUDAD:"<<cliente.ubicacion.ciudad<<endl;
            cout<<"DIRECCION:"<<cliente.ubicacion.direccion<<endl;
            cout<<"HORARIO:"<<cliente.horario<<endl;
            cout<<"CODIGO DE RUTINAS DEL AFILIADO:"<<endl;

            cout<<"PARIENTE:"<<cliente.pariente<<endl;

            cout<<"ESTATURA:"<<cliente.estatura<<endl;
            cout<<"PESO:"<<cliente.peso<<endl;

            cout<<"CANTIDAD DE HIJOS :"<<cliente.numeroHijos<<endl;
            cout<<"CORREO ELECTRONICO:"<<cliente.correoel<<endl;

            cout<<"____________________________________________________________";




        DAfiliado.read((char *)&cliente, sizeof(clientess));

    }
    if(!hallado)
    {
        cout<<"No hay afiliados registrados.";
    }
    DAfiliado.close();
    DGimnasio.close();

}
void listam(fstream &DAfiliado,fstream &DGimnasio)
{
    gym elemento;
    clientess cliente;
    int pos;
    bool hallado=false;
    cout<<" LISTA DE AFILIADOS DE SEXO MASCULINO "<<endl;
    DAfiliado.seekg(0,ios::beg);
    DAfiliado.read((char *)&cliente, sizeof(clientess));
    DGimnasio.read((char *)&elemento, sizeof(gym));

    while(!DAfiliado.eof())
    {
        if(cliente.sexo=='m')
        {
            hallado=true;
            int k=0;
            cout<<"____________________________________________________________";
            cout<<"CEDULA: "<< cliente.cedula<<endl;
            cout<<"NOMBRE: "<< cliente.nombre<<endl;
            cout<<"TELEFONO:"<<cliente.telefono<<endl;
            cout<<"CIUDAD:"<<cliente.ubicacion.ciudad<<endl;
            cout<<"DIRECCION:"<<cliente.ubicacion.direccion<<endl;
            cout<<"HORARIO:"<<cliente.horario<<endl;

            cout<<"PARIENTE:"<<cliente.pariente<<endl;

            cout<<"ESTATURA:"<<cliente.estatura<<endl;
            cout<<"PESO:"<<cliente.peso<<endl;
            cout<<"CANTIDAD DE HIJOS:"<<cliente.numeroHijos<<endl;
            cout<<"CORREO ELECTRONICO:"<<cliente.correoel<<endl;
            cout<<"____________________________________________________________";



        }
        DAfiliado.read((char *)&cliente, sizeof(clientess));

    }
    if(!hallado)
    {
        cout<<"No hay afiliados de sexo masculino.";
    }
    DAfiliado.close();
    DGimnasio.close();

}





void agregarnuevo(fstream &DAfiliado,fstream &DGimnasio)
{
    clientess cliente;
    gym elemento;
    bool hallado;
    int buscar,ayuda;
    DAfiliado.seekg(0,ios::beg);
    DGimnasio.seekg(0,ios::beg);
    cout<<"\nIngrese los datos del nuevo cliente:"<<endl;
    cout<<"Ingrese la cedula del afiliado :";
    cin>>buscar;
    hallado = false;
    //Ciclo para leer el archivo y buscar si ya existe
    DGimnasio.read((char *)&elemento, sizeof(gym));
    DAfiliado.read((char *)&cliente, sizeof(clientess));
    while ((!DAfiliado.eof()) && (!hallado))
    {
        //Comparacion
        //Comparacion
        if(cliente.cedula == buscar)
        {
            hallado = true;
        }
        if(!hallado)
            DAfiliado.read((char *)&cliente, sizeof(clientess));
    }
    if (hallado)
    {
        cout<<" El cliente que usted esta tratando de ingresar YA se encuentra dentro de la base de datos :";
    }
    else
    {

        elemento.cantcli=elemento.cantcli+1;
        DGimnasio.seekp(0, ios::beg);
        //Escribimos en la posicion...
        DGimnasio.write((char *)&elemento, sizeof(gym));
        DAfiliado.close();
        DAfiliado.open ("DAfiliado.dat",ios::binary|ios::app);

        ayudaa(DAfiliado,buscar);



    }
    DAfiliado.close();
    DGimnasio.close();//Se cierra el archivo
}








void ayudaa(fstream &DAfiliado,int buscar)
{
    clientess cliente;

    cliente.cedula = buscar;
    cout<<"Ingrese el nombre del afiliado :";
    cin>>cliente.nombre;
    cout<<"Ingrese el numero de telefono del afiliado :";
    cin>>cliente.telefono;
    cout<<"Ingrese la direccion del afiliado :";
    cin>>cliente.ubicacion.direccion;
    cout<<"Ingrese la ciudad en la que vive :" ;
    cin>>cliente.ubicacion.ciudad;
    cout<<"Ingrese el horario del afiliado :";
    cin>>cliente.horario;
    cout<<"Ingrese el sexo del afiliado('f' o 'm') :";
    cin>> cliente.sexo;
    cout<<"Ingrese un pariente del cliente :";
    cin>>cliente.pariente;
    cout<<"Ingrese la estatura del afiliado: ";
    cin>>cliente.estatura;
    cout<<"Ingrese el peso del afiliado :";
    cin>>cliente.peso;
    cout<<"Ingrese la cantidad de hijos del afiliado: ";
    cin>>cliente.numeroHijos;
    cout<<"Ingrese el correo electronico del afiliado: ";
    cin>>cliente.correoel;

    DAfiliado.write((char *)&cliente,sizeof(clientess));




    DAfiliado.close();
}
