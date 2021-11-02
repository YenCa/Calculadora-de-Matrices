#include "matriz.h"

void Matriz::reservaMemoria()
{
    elementos_=new double*[filas_];

        for(int i=0; i<filas_; i++){
            elementos_[i]=new double[columnas_];
        }

}
Matriz::Matriz()
{
  filas_=0;
  columnas_=0;

}

Matriz::Matriz(int filas, int columnas)
{
    filas_=filas;
    columnas_=columnas;

   reservaMemoria();
}


Matriz::~Matriz()
{
    delete []elementos_;
}

void Matriz::establecerFilas(int filas)
{
    filas_=filas;
}

void Matriz::establecerColumnas(int columnas)
{
    columnas_=columnas;
}

void Matriz::llenarElemento(int fila, int columna, double valor)
{

    elementos_[fila][columna]=valor;

}

void Matriz::ver()
{
    for (int i=0; i<filas_; i++){
        for(int j=0; j<columnas_; j++){
            cout<< elementos_[i][j]<<"\t";

        }
        cout<<endl;
    }
}

Matriz &Matriz::operator+(Matriz &M)
{
    Matriz *resultado;
    resultado=new Matriz (filas_, columnas_);
    for (int i=0; i<filas_; i++){
        for(int j=0; j<columnas_; j++){
            resultado->elementos_[i][j]=elementos_[i][j]+M.elementos_[i][j];

        }

    }
    return *resultado;
}

Matriz &Matriz::operator=(Matriz &M)
{
    if(this !=&M){
        this->filas_=M.filas_;
       this->columnas_=M.columnas_;

        this ->reservaMemoria();
        for(int i=0; i<filas_; i++){
            for(int j=0; j<columnas_; j++ ){
                this ->elementos_[i][j]=M.elementos_[i][j];

            }
        }
    }
    return *this;
}

Matriz &Matriz::operator*(Matriz &M)
{
    Matriz *resultado;
    resultado=new Matriz (filas_, columnas_);
    for (int i=0; i<filas_; i++){
        for(int j=0; j<columnas_; j++){
            resultado->elementos_[i][j]=0;
            for(int k=0; k<resultado->columnas_; k++){

            resultado->elementos_[i][j]=resultado->elementos_[i][j]+ elementos_[i][k]  *M.elementos_[k][j];
         }
        }

    }
    return *resultado;
}

int Matriz::filas()
{
    return filas_;
}

int Matriz::columnas()
{
    return columnas_;
}


