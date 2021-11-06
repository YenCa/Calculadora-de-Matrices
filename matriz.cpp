#include "matriz.h"
#include<iostream>
#include<iomanip>
using std::setw;

void Matriz::reservaMemoria()
{
    elementos_=new double*[filas_];// Se reserva memoria para un arreglo que tiene filas

        for(int i=0; i<filas_; i++){
            elementos_[i]=new double[columnas_]; //Para cada elemento reservamos memoria para la columnas
        }

}
Matriz::Matriz() //Constructor que no hace nada les asignamos valor 0
{
  filas_=0;
  columnas_=0;

}

Matriz::Matriz(int filas, int columnas)
{
    filas_=filas;
    columnas_=columnas;

   reservaMemoria(); //Reservamos memoria para la matriz
}


Matriz::~Matriz()
{
    delete []elementos_;//Para eliminar esa memoria dinamica
}

void Matriz::establecerFilas(int filas)
{
    filas_=filas; //Devuelven ese dato
}

void Matriz::establecerColumnas(int columnas)
{
    columnas_=columnas; // Devuelven ese dato
}

void Matriz::llenarElemento(int fila, int columna, double valor)
{

    elementos_[fila][columna]=valor; // Llenamos elementos
    //

}

void Matriz::ver()
{
    //Imprime la matriz
    for (int i=0; i<filas_; i++){
        for(int j=0; j<columnas_; j++){
            cout<< elementos_[i][j]<<"\t";

        }
        cout<<endl;
    }
}

Matriz &Matriz::operator+(Matriz &M)
{
    Matriz *resultado; // Creamos una matriz que es lo que retornara
    resultado=new Matriz (filas_, columnas_); // Reservamos memoria
    for (int i=0; i<filas_; i++){
        for(int j=0; j<columnas_; j++){
            resultado->elementos_[i][j]=elementos_[i][j]+M.elementos_[i][j];
            // *resultado es un objeto matriz, y es un puntero accedemos el operador ->
            //le asignamos los valores que seran los elementos + la matriz M
        }

    }
    return *resultado;
}

Matriz &Matriz::operator=(Matriz &M)
{
    //No podemos asignar M1= M1 para operadores de asignacion
    //Entonces creamos un if.. else, para hacer la asignacion hacemos uso de this
    // Matriz original lo llamamos this

    if(this !=&M){
        this->filas_=M.filas_;
       this->columnas_=M.columnas_;
     // Reservamos memoria para this matriz
        this ->reservaMemoria();
        // Pasamos todos los datos,
        for(int i=0; i<filas_; i++){
            for(int j=0; j<columnas_; j++ ){
                this ->elementos_[i][j]=M.elementos_[i][j];

            }
        }
    }
    return *this; //Retornamos esa matriz con la direccion
}

Matriz &Matriz::operator*(Matriz &M)
{
    Matriz *resultado;
    resultado=new Matriz (filas_, columnas_);
    for (int i=0; i<filas_; i++){
        for(int j=0; j<columnas_; j++){
            resultado->elementos_[i][j]=0; // Llenamos los elementos =0 para la matriz resultado
            for(int k=0; k<resultado->columnas_; k++){
            // Creamos un for mas para realizar la operacion *
            //Donde los elementos de resultado = a la suma de los elementos de resultado y elementos [i][k] * los elementos de la Matriz M[k][j]
            resultado->elementos_[i][j]=resultado->elementos_[i][j]+ elementos_[i][k]  *M.elementos_[k][j];
         }
        }

    }
    return *resultado; //Retornara el valor de la multiplicacion
}

void Matriz::escalar(int esc) //El elemento que ingrese el usuario sera el escalar que multiplicara la matriz
{
    for (int i=0; i<filas_; i++){
        for(int j=0; j<columnas_; j++){
            elementos_[i][j]*=esc;  // Para cada elemento en la matriz se multiplicara por un escalar que el usuario ingrese

    }
    }

}

void Matriz::GaussJ()
{
   for(int i=0; i<this->filas_; i++){
       double pivote;
       pivote = elementos_[i][i];
       double aux;
       if(elementos_[i][i] == 0.0)
                 {
                      cout<<"Mathematical Error!";
                      exit(0);
       }
       for(int k=0; k<this->columnas_; k++){
           elementos_[i][k]=elementos_[i][k]/pivote;

       }

       for(int j=0; j<this->filas_; j++){
           if(i!=j){
               aux=elementos_[j][i];
               for(int m=0; m<this->filas_; m++){
                   elementos_[j][m]=elementos_[j][m]-aux*elementos_[i][m];

               }

           }

       }

       cout<<"-----------------------------------------------";
        cout<<"\n";
       for(int i=0; i<this->filas_; i++){

           for(int j=0; j<this->columnas_; j++){

               cout<<elementos_[i][j]<<"\t";
              }

           cout<<endl;
       }



}


}




int Matriz::filas()
{
    return filas_;
}

int Matriz::columnas()
{
    return columnas_;
}
