#ifndef GAUSSJ_H
#define GAUSSJ_H
#include<iostream>
#include<cmath>
#include "matriz.h"

class GaussJ
{
private:
    // Para crear una matriz necesitamos las dimensiones: filas y columnas.
    int filas_;
    int columnas_; //El orden son las filas y las columnas

    //Arreglo de los elementos, matriz general de arreglo bidimensional
    double ** elementos_;
    void reservaMemoria();


public:
    //Constructores
    GaussJ();
    GaussJ(int filas, int columnas);

   //Destructor
    ~GaussJ();
    //Funciones set - establecer
    void establecerDimension(int filas, int columnas); //Le mandariamos las filas

    //Funciones get
    int filas();
    int columnas();

    // Otras funciones
    void llenarElemento(int fila, int columna, double valor);
    void ver(); // Visualiza la matriz
    void Gauss();
    void Solucion();
};

#endif // GAUSSJ_H
