#include <iostream>

using namespace std;

int main(){
    /**
     * Diseñar un programa que asigne memoria dinámica a una matriz de N × M (con N y M pasado por
     * parámetro). Sumar las filas e imprimir la fila que tuvo la suma mínima.
     */

    int N, M;
    cout << "Ingrese el numero e filas:";
    cin>>N;
    cout << "Ingrese el numero de columnas:";
    cin>>M;

    int **matrix = new int*[N];// Creamos la matriz y reservamso memoria para las filas
    for(int i=0; i<N; i++){
        matrix[i] = new int[M];// Reservamos memoria para las columnas
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << "Ingrese el valor de la fila " << i+1 << " y columna " << j+1 << ": ";
            cin >> matrix[i][j];
        }
    }

    int comp = (9*10^10), fila = 0, suma = 0; // Variable para comparar la suma de las filas, fila a imprimir y suma de la fila actual
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            suma += matrix[i][j];
        }
        if (suma < comp){
            comp = suma;
            fila = i;
        }
        suma = 0;
    }
    cout << "La fila con la suma minima es la fila " << fila+1 << endl;

    for (int i = 0; i < N; i++)
    {
        delete[] matrix[i];// Liberamos la memoria reservada para las columnas
    }
    delete[] matrix;// Liberamos la memoria reservada para las filas
    

}