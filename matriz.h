#ifndef MATRIZ_H
#define MATRIZ_H

#include<iostream>
#include<cmath>

using std::cout;
using std::endl;
using std::cin;
using std::abs;
class Matriz
{


private:
    int filas_;
    int columnas_;

    double ** elementos_;
    void reservaMemoria();

public:

    // Constructores
    Matriz();
    Matriz(int filas, int columnas);

    // Destructores

    ~Matriz();

    // Funciones set - establecer
    void establecerFilas(int filas);
    void establecerColumnas(int columnas);


    //Funciones get -

    int filas();
    int columnas();

    // Otras funciones

    void llenarElemento(int fila, int columna, double valor);
    void ver();
    Matriz &operator+(Matriz &M);
    Matriz &operator=(Matriz &M);
    Matriz &operator*(Matriz &M);
    void escalar(int esc);
    void GaussJ();


};

#endif // MATRIZ_H
