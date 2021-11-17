#include "matriz.h"
#include<iostream>
#include<iomanip>
using std::setw;
using std::abs;

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

void Matriz::establecerDimension(int filas, int columnas)
{
    filas_=filas; //Devuelven ese dato
    columnas_=columnas;
    reservaMemoria();
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
    if(resultado->filas()==M.filas()&& resultado->columnas()==M.columnas()){
    for (int i=0; i<filas_; i++){
        for(int j=0; j<columnas_; j++){

            resultado->elementos_[i][j]=elementos_[i][j]+M.elementos_[i][j];
            // *resultado es un objeto matriz, y es un puntero accedemos el operador ->
            //le asignamos los valores que seran los elementos + la matriz M

            }

    }
    cout<<"  La suma es: \n"<< endl;
    return *resultado;
    }
    else{
        cout<<"\nNo se puede realizar la suma ya que son matrices incompatibles"<<endl;
    }
    exit(0);
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
        if(this->columnas()==M.filas()){

        for (int i=0; i<this->filas_; i++){
            for(int j=0; j<M.columnas_; j++){
                resultado->elementos_[i][j]=0; // Llenamos los elementos =0 para la matriz resultado

                for(int k=0; k<this->columnas_; k++){
                // Creamos un for mas para realizar la operacion *
                //Donde los elementos de resultado = a la suma de los elementos de resultado y elementos [i][k] * los elementos de la Matriz M[k][j]

                    resultado->elementos_[i][j]+=this->elementos_[i][k]*M.elementos_[k][j];
                   
                }
                }
            }
        cout<<"******************************************************************************"<<endl;
        cout<<" La Multiplicacion: \n"<< endl;
        return *resultado; //Retornara el valor de la multiplicacion

        }
        else{
            cout<<"\nNo se puede realizar la multiplicacion ya que son matrices incompatibles"<<endl;

        }
        exit(0);
}


void Matriz::escalar(int esc) //El elemento que ingrese el usuario sera el escalar que multiplicara la matriz
{
    for (int i=0; i<filas_; i++){
        for(int j=0; j<columnas_; j++){
            elementos_[i][j]*=esc;  // Para cada elemento en la matriz se multiplicara por un escalar que el usuario ingrese

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
