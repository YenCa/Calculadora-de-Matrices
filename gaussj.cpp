#include "gaussj.h"
#include "matriz.h"
#include<iostream>
#include<iomanip>
using std::setw;
using std::abs;

void GaussJ::reservaMemoria()
{
    elementos_=new double*[filas_];// Se reserva memoria para un arreglo que tiene filas

        for(int i=0; i<filas_; i++){
            elementos_[i]=new double[columnas_]; //Para cada elemento reservamos memoria para la columnas
        }
}

GaussJ::GaussJ()
{

}

GaussJ::GaussJ(int filas, int columnas)
{
    filas_=filas;
    columnas_=columnas;

    reservaMemoria(); //Reservamos memoria para la matriz
}

GaussJ::~GaussJ()
{
    delete []elementos_;//Para eliminar esa memoria dinamica
}

void GaussJ::establecerDimension(int filas, int columnas)
{
    filas_=filas; //Devuelven ese dato
    columnas_=columnas;
    reservaMemoria();
}

int GaussJ::filas()
{
    return filas_;
}

int GaussJ::columnas()
{
    return columnas_;
}

void GaussJ::llenarElemento(int fila, int columna, double valor)
{
    elementos_[fila][columna]=valor; // Llenamos elementos
    //
}

void GaussJ::ver()
{
    //Imprime la matriz
    for (int i=0; i<filas_; i++){
        for(int j=0; j<columnas_; j++){
            cout<< elementos_[i][j]<<"\t";

        }
        cout<<endl;
    }
}

void GaussJ::Gauss()
{
    for(int i=0; i<this->filas_; i++){
        double pivote;
        pivote = elementos_[i][i];
        double aux;
        if(elementos_[i][i] == 0.0)
                  {
         cout<<"\n\n Es una contradiccion y, por tanto, no tiene solucion.\n\n\n";
         exit(0);
        }

        for(int k=0; k<this->columnas_; k++){
            elementos_[i][k]=elementos_[i][k]/pivote;

        }

        for(int j=0; j<this->filas_; j++){
            if(i!=j){
                aux=elementos_[j][i];
                for(int m=0; m<this->columnas_; m++){

                    elementos_[j][m]=elementos_[j][m]-aux*elementos_[i][m];

                }

            }

        }


        cout<<"----------------------------------------------------";
         cout<<"\n";
        for(int i=0; i<this->filas_; i++){

            for(int j=0; j<this->columnas_; j++){

                cout<<elementos_[i][j]<<"\t";
               }

            cout<<endl;
        }

    }
}

void GaussJ::Solucion()
{
    for(int i=0;i<this->filas_;i++){
          cout<<"\n x"<<i+1<<" = "<<elementos_[i][this->columnas_-1]<<endl;
    }
}
