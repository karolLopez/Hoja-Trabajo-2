/*
Ejercicio # 2:
El director de un colegio desea realizar un programa que procese un archivo de registros correspondiente a los diferentes alumnos del centro a fin de obtener los siguientes datos:

Nota más alta y número de identificación del alumno correspondiente.
Nota media del colegio.
Datos de Estudiantes:

Identificación
Nombre
Nota
*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include<ctime> 
#include <stdio.h>
#include <vector>

using namespace std;

struct Alumnos{
  int idem;
  string nombre;
  string apellido;
  float nota;
};

std::vector<Alumnos> alumno;

void calculo_notas(){
  cout << "Notas mas alta del colegio" << endl;
  cout << "=============================================" << endl;
  cout << "Carne"<< "\t" << "Nombre" << "\t" << "Apellido" << "\t" << "Nota" << endl;
  cout << "---------------------------------------------" << endl; 

  float nota=0.0;
  float nota_media=0.0;

  Alumnos nota_alta;
  for (int i=0; i<alumno.size(); i++){
    if (alumno[i].nota>=nota){
      nota_alta=alumno[i];
      nota=alumno[i].nota;
    }
    nota_media=nota_media+alumno[i].nota;
  }
    // Calculamos la media de las notas del colegio
  nota_media=nota_media/alumno.size();

  cout <<nota_alta.idem << "\t" <<nota_alta.nombre << "\t" <<nota_alta.apellido << "\t" <<nota_alta.nota << endl;
  cout << "--------------------------------------------"<< endl;
  cout << "--------------------------------------------"<< endl;
  cout << "La nota media del colegio es de: " << nota_media << endl;
    
  string empty;
  cin >> empty;
  return;
}

void grabar(){
  Alumnos x;
  cout << "Ingrese Número de Carne del alumno"<< "\n";
  cin >> x.idem;
  cout << "Ingrese 1er Nombre del alumno"<< "\n";
  cin >> x.nombre;
  cout << "Ingrese 1er apellido del alumno"<< "\n";
  cin >> x.apellido;
  cout << "Ingrese Nota del alumno"<< "\n";
  cin >> x.nota;
  // grabamos en el archivo
  ofstream miarchivo("alumnos.txt", std::ios_base::app);
  miarchivo << x.idem << "\t" << x.nombre << "\t" << x.apellido << "\t" << x.nota << endl;
  //Cerramos la escritura del archivo.
  miarchivo.close();
}

void leer(){
    ifstream miarchivo;
    alumno.clear();
    Alumnos alum;
    miarchivo.open("alumnos.txt",ios::in);
    while(miarchivo >> alum.idem >> alum.nombre >> alum.apellido >> alum.nota)
    {
        alumno.push_back(alum);
    }
    miarchivo.close();
    calculo_notas();
    return;
}

int main(){
  char tecla;
  string empty;
  bool bandera=false;
  
  do
    {
        system("clear");
        cin.clear();
        cout << "Control de notas del Cole" << endl;
        cout << "-----------" << endl << endl;
        cout << "\t1 .- Ingresar alumno" <<endl;
        cout << "\t2 .- Leer registros y mostrar reporte" <<endl;
        cout << "\t3 .- Salir" << endl << endl;
        cout << "Elije una opcion: ";
 
        cin >> tecla;
 
		switch(tecla)
    		{
			case '1':
				system("clear");
        grabar();
        break;
 
			case '2':
        system("clear");
        leer();
        break;
      
      case '3':
				bandera=true;
				//exit(1);
				break;
 
			default:
				system("clear");
				cout << "Opcion no valida.\a\n";
				getchar();
        getline(cin, empty);
				break;
		}
    }while(bandera!=true);
    
  return 0;
}
