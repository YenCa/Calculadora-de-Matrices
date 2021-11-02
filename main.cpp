#include <iostream>
#include <math.h>
#include "matriz.h"

using std::cout;
using std::endl;
using std::cin;

int FILAS;
int COLUMNAS;
int contador=1;

int main()
{

  cout<<"Ingrese los valores para filas y columnas respectivamente para la matriz A"<<endl;
  cin>>FILAS;
  cin>>COLUMNAS;


  Matriz M1(FILAS,COLUMNAS);


    for(int i=0; i<FILAS; i++){
        for (int j=0; j<COLUMNAS; j++){
            cout<<"Ingrese los valores: "<<"["<<j+1<<"]"<<endl;
            cin>>contador;
           M1.llenarElemento(i, j, contador++);
        }
    }



  cout<<"Ingrese los valores para filas y columnas respectivamente para la matriz B"<<endl;
  cin>>FILAS;
  cin>>COLUMNAS;
 Matriz M2(FILAS, COLUMNAS);
    for(int i=0; i<FILAS; i++){
         for (int j=0; j<COLUMNAS; j++){
           cout<<"Ingrese los valores: "<<"["<<j<<"]"<<endl;
           cin>>contador;
           M2.llenarElemento(i, j, contador++);
        }
    }
    cout<<"La matriz A es:"<<endl;
    M1.ver();
   cout<<"La matriz B es:"<<endl;
    M2.ver();

if(FILAS==COLUMNAS){
  Matriz M3;
  cout<<"La suma es: "<< endl;
   M3 = M1 + M2;
   M3.ver();


   cout<<"La multiplicacion es: "<< endl;
   M3 = M1 * M2;
   M3.ver();

}
 else{
 cout<<"El orden de las matrices debe ser n x n para realizar cualquier operacion"<<endl;
 }


    return 0;
}
