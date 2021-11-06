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
    // Para crear una matriz necesitamos las dimensiones: filas y columnas.
    int filas_;
    int columnas_; //El orden son las filas y las columnas

    //Arreglo de los elementos, matriz general de arreglo bidimensional
    double ** elementos_;
    void reservaMemoria();

public:

    // Constructores
    Matriz();
    Matriz(int filas, int columnas); // Constructor que le asignamos filas y columnas

    // Destructores

    ~Matriz();

    // Funciones set - establecer
    void establecerFilas(int filas); //Le mandariamos las filas
    void establecerColumnas(int columnas); // Le mandariamos las columnas


    //Funciones get -

    int filas();
    int columnas();

    // Otras funciones

    void llenarElemento(int fila, int columna, double valor);
    void ver(); // Visualiza la matriz
    //Sobrecarga de operadores
    Matriz &operator+(Matriz &M);
    Matriz &operator=(Matriz &M); // Para imprimir la nueva matriz
    Matriz &operator*(Matriz &M);

    //Otras funciones
    void escalar(int esc);
    void GaussJ();


};

#endif // MATRIZ_H
