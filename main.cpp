#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <math.h>
#include "matriz.h"
#include<conio.h>
#include<cstdlib>
#include<cstdio>

using std::cout;
using std::endl;
using std::cin;
using std::setw;

int FILAS;
int COLUMNAS;
int contador=1;
int n;
int opcion;
int opc1;
int m;

int main()
{
     system("color fd"); // Color para la ventana

     cout<<"\t\t '           PROGRAMACION II              ' \n";
     cout<<"\t\t '20172000635  YENCY CAROLINA MATUTE AMAYA' \n";
     cout<<"\t\t '             WENDY VANESSA              ' \n";
     cout<<"\n\t\t  ...CALCULADORA DE MATRICES... \n\n\t\t ";



 do{
 cout<<"Que desea calcular?"<<endl;
 cout<<"\n1.- Operaciones con matrices "<<endl;
 cout<<"\n2.- Solucion de Sistemas "<<endl;
 cout<<"\n3.- Salir "<<endl;
 cout<<"\n OPCION:  ";
 cin>>opcion;

 switch(opcion){ //Swith para crear el menu de lo que el usuario desee calcular
      case 1:

     do{

         cout<<"********************************************************************"<<endl;
         cout<<"========   USTED ELIGIO:   OPERACIONES CON MATRICES   ========"<<endl;
         cout<<"\n1.- Multiplicacion por un escalar "<<endl;
         cout<<"\n2.- Suma de matrices "<< endl;
         cout<<"\n3.- Producto de dos matrices "<<endl;
         cout<<"\n4.- Salir "<<endl;
         cout<<"\n OPCION:  ";
         cin>>opc1;
      switch(opc1){
            case 1 :

          cout<<"********************************************************************"<<endl;
          cout<<"========     USTED ELIGIO:   Multiplicacion por un escalar    ========"<<endl;
           do{
          cout<<"\n Ingrese los valores para filas:  ";
          cin>>FILAS;
          cout<<"";
          cout<<"\n Ingrese los valores para columnas:  ";
          cin>>COLUMNAS;
          cout<<""<<endl;


              Matriz M4(FILAS, COLUMNAS); //Hacemos uso de un ciclo for para cada valor que el usuario digite
              // Hacemos uso de un contador que nos llenara la matriz con los valores ingresado
              cout<<"\n Ingrese los valores: "<<endl;
                     for(int i=0; i<FILAS; i++){
                         for (int j=0; j<COLUMNAS; j++){

                           cin>>contador;
                           M4.llenarElemento(i, j, contador++);
                        }
                     }

                    cout<<"\n         Ingrese el valor del escalar: ";
                    cin>>n;
                    cout<<"--------------------------------------------------------------"<<endl;
                    M4.ver();

                    cout<<"**************************************************************"<<endl;
                    M4.escalar(n);
                    M4.ver();
                    cout<<"**************************************************************"<<endl;
                    cout<<"     Desea multiplicar otra matriz con un escalar? \n "<<endl;
                    cout<<"\n 1.  Realizar otro producto "<<"\n 0.  Salir  "<<endl;
                    cout<<"  OPCION ";
                    cin>>m;
                    if(m==0){
                        return 0;
                  }
          }
          while(m==1);
          break;


              case 2:
           cout<<"********************************************************************"<<endl;
           cout<<"========         USTED ELIGIO:   Suma de dos matrices           ========"<<endl;

                    do{
               cout<<"\n Ingrese los valores para filas:  ";
               cin>>FILAS;
               cout<<"";
               cout<<"\n Ingrese los valores para columnas:  ";
               cin>>COLUMNAS;
               cout<<""<<endl;


              Matriz M1(FILAS,COLUMNAS);

                cout<<"Ingrese los valores: "<<endl;
                for(int i=0; i<FILAS; i++){
                    for (int j=0; j<COLUMNAS; j++){

                        cin>>contador;
                       M1.llenarElemento(i, j, contador++);
                    }
                }



                cout<<"\n Ingrese los valores para filas:  ";
                cin>>FILAS;
                cout<<"";
                cout<<"\n Ingrese los valores para columnas:  ";
                cin>>COLUMNAS;
                cout<<""<<endl;

             Matriz M2(FILAS, COLUMNAS);
             cout<<"\n Ingrese los valores: "<<endl;
                for(int i=0; i<FILAS; i++){
                     for (int j=0; j<COLUMNAS; j++){

                       cin>>contador;
                       M2.llenarElemento(i, j, contador++);
                    }
                }

                cout<<"  La matriz A es: \n"<<endl;

                M1.ver();
                cout<<"*********************************************************"<<endl;
               cout<<"  La matriz B es: \n"<<endl;

                M2.ver();

                cout<<"*********************************************************"<<endl;

          if((M1.columnas()==M2.columnas()) and (M1.filas())==M2.filas()){
              Matriz M3;
              cout<<"  La suma es: \n"<< endl;

               M3 = M1 + M2;
               M3.ver();

            }
             else{
             cout<<"******** El orden de las matrices debe ser n x n para sumar ********"<<endl;
             }
            cout<<"*************************************************************"<<endl;
            cout<<"\nDesea realizar otra suma o salir? \n"<<endl;

            cout<<"\n 1.  Realizar otra suma "<<"\n 0.  Salir  "<<endl;
            cout<<"OPCION";
            cin>>m;
            if(m==0){
                return 0;
            }

          }
          while(m==1);


                break;



      case 3:
          cout<<"********************************************************************"<<endl;
          cout<<"========       USTED ELIGIO:   Multiplicacion de dos matrices     ========"<<endl;

          do{

              cout<<"\n Ingrese los valores para filas:  ";
              cin>>FILAS;
              cout<<"";
              cout<<"\n Ingrese los valores para columnas:  ";
              cin>>COLUMNAS;
              cout<<""<<endl;
              Matriz M1(FILAS,COLUMNAS);

                cout<<"\n Ingrese los valores: "<<endl;
                for(int i=0; i<FILAS; i++){
                      for (int j=0; j<COLUMNAS; j++){

                               cin>>contador;
                           M1.llenarElemento(i, j, contador++);
                              }
                          }

                cout<<"\n Ingrese los valores para filas:  ";
                cin>>FILAS;
                cout<<"";
                cout<<"\n Ingrese los valores para columnas:  ";
                cin>>COLUMNAS;
                cout<<""<<endl;

              Matriz M2(FILAS, COLUMNAS);
              cout<<"\n Ingrese los valores: "<<endl;
                   for(int i=0; i<FILAS; i++){
                         for (int j=0; j<COLUMNAS; j++){

                            cin>>contador;
                            M2.llenarElemento(i, j, contador++);
                              }
                        }
                  cout<<" La matriz A es: \n"<<endl;

                  M1.ver();
                  cout<<"******************************************************************************"<<endl;
                  cout<<" La matriz B es: \n"<<endl;

                  M2.ver();

                 if((M1.columnas()==M2.columnas()) and (M1.filas()==M2.filas())){
                  Matriz M3;
                  cout<<"******************************************************************************"<<endl;
                  cout<<" La Multiplicacion: \n"<< endl;

                   M3 = M1 * M2;
                   M3.ver();

                      }
                  else{
                        cout<<"******** El orden de las matrices debe ser n x n para multiplicar ********"<<endl;
                       }

                     cout<<"\nDesea realizar otra multiplicacion o Salir? \n"<<endl;

                     cout<<"\n 1.  Realizar otra multiplicacion "<<"\n 0.  Salir  "<<endl;
                     cout<<"OPCION";
                     cin>>m;
                     if(m==0){
                     return 0;
                          }

                        }
                     while(m==1);
                     break;


      case 4:
             default:
                  break;

                 }
                        }

            while(opc1!=4);
            cout<<"\t";
            cout<<"USTED HA DECIDIDO SALIR"<<endl;
            cout<<"\t";
            cout<<"ADIOS"<<endl;
            return 0;


 case 2: cout<<"********************************************************************"<<endl;
        cout<<"========       USTED ELIGIO:   GAUSS JORDAN    ========"<<endl;

    do{

            cout<<"\n Ingrese los valores para filas:  ";
            cin>>FILAS;
            cout<<"";
            cout<<"\n Ingrese los valores para columnas:  ";
            cin>>COLUMNAS;
            cout<<""<<endl;
            if(FILAS>1 & COLUMNAS>1){




         Matriz M1(FILAS, COLUMNAS);
         cout<<" Ingrese los valores: "<<endl;
         for(int i=0; i<FILAS; i++){
              for (int j=0; j<COLUMNAS; j++){

                cin>>contador;
                M1.llenarElemento(i, j, contador++);
             }
         }
         M1.ver();
         cout<<"*****************************************************"<<endl;

         M1.GaussJ();

         cout<<"*****************************************************"<<endl;
         M1.ver();
         cout<<"*****************************************************"<<endl;



         cout<<"\nDesea encontrar otra solucion por Gauss Jordan o salir? \n"<<endl;
         cout<<"\n 1.  Realizar otra solucion por Gauss- Jordan "<<"\n 0.  Salir  "<<endl;
         cout<<"OPCION  ";
         cin>>m;
                   if(m==0){
                      return 0;
                              }
            }
            else{  cout<<" \n No es posible \n"<<endl;
     }
                           }


                         while(m==1);
                         break;



                  break;

                     }



                     }

          while(opcion !=3);




             return 0;


         }
