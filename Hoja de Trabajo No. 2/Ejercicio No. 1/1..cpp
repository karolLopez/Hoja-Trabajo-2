 /*
  Se dispone de un archivo STOCK correspondiente a la existencia de artículos de un almacén y se 
  desea señalar aquellos artículos cuyo nivel está por debajo del mínimo y que visualicen un mensaje 
  “hacer pedido”. Cada artículo contiene un registro con los siguientes campos: número del código del 
  artículo, nivel mínimo, nivel actual, proveedor, precio.

  El programa debe tener un menu que se especifiquen las siguientes opciones:
  1) Agregar productos (Grabar datos a un archivo)
  2) Leer archivo y mostrar en pantalla que productos tiene nivel minimo. 

  *if (nivel actual==nivel mínimo)
      cout<<"Nivel Minimo";
  */
  
  #include <fstream>
  #include <iostream>
  #include <string>
  #include <cstdlib>
  #include<ctime> 
  #include <stdio.h>
  #include <vector>
  
  using namespace std;

  struct Productos{
    string codigo;
    int minimo;
    int actual;
    string proveedor;
    float precio;
  };

  // Hacemos el vector
  std::vector<Productos> producto;

  void agregar_producto(){
    Productos x;
    cout << "Ingrese código de producto"<< "\n";
    cin >> x.codigo;
    cout << "Ingrese el minimo del producto"<< "\n";
    cin >> x.minimo;
    cout << "Ingrese cantidad actual del producto"<< "\n";
    cin >> x.actual;
    cout << "Ingrese el proveedor del producto"<< "\n";
    cin >> x.proveedor;
    cout << "Ingrese precio del producto"<< "\n";
    cin >> x.precio;

      // grabamos producto en el archivo.
      ofstream miarchivo("stock.txt", std::ios_base::app);
      miarchivo << x.codigo << "\t" << x.minimo << "\t" << x.actual << "\t" << x.proveedor << "\t" << x.precio << endl;
      //Cerramos la escritura del archivo.
      miarchivo.close();
  }

  void mostrar_informacion(){
    
  cout << "Los siguientes productos necesitan mas stock" << endl;
  cout << "---------------------------------------------" << endl;
  cout << "COD"<< "\t" << "MIN" << "\t" << "EXI" << "\t" << "PROVEEDOR" << "\t" << "PRE" << endl;
  cout << "---------------------------------------------" << endl; 

  for (int i=0; i< producto.size(); i++){
    if (producto[i].minimo>=producto[i].actual){
        cout << producto[i].codigo << "\t" << producto[i] .minimo << "\t" << producto[i].actual << "\t" <<   producto[i].proveedor << "\t" << producto[i].precio <<  "\t" << endl;
    }
  }
    string empty;
      cin >> empty;
      return;
  }

  void leer_archivo(){
      //declaramos la variable para leer archivo
      ifstream miarchivo;

      //Limpiamos el vector
      producto.clear();
      
      // creamos la variable con la estructura
      Productos prod;

      //abrimos archivo 
      miarchivo.open("stock.txt",ios::in);
      
    //Obtenemos las columnas del archivo por linea
      while(miarchivo >> prod.codigo >> prod.minimo >> prod.actual >> prod.proveedor >> prod.precio)
      {
          // Grabamos en memoria, con vectores
          producto.push_back(prod);
      }

      //Cerramos el archivo
      miarchivo.close();
      mostrar_informacion();
      return;
  }

  int main() {
    char tecla;
    string empty;
    bool bandera=false;
    
    do
      {
          system("clear");
          cin.clear();
          cout << "Productos" << endl;
          cout << "-----------" << endl << endl;
          cout << "\t1 .- Agregar Producto" <<endl;
          cout << "\t2 .- Leer archivo y mostrar minimos" <<endl;
          cout << "\t3 .- Salir" << endl << endl;
          cout << "Elije una opcion: ";
  
          cin >> tecla;
  
      switch(tecla)
          {
        case '1':
          system("clear");
          agregar_producto();
          break;
  
        case '2':
          system("clear");
          leer_archivo();
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
