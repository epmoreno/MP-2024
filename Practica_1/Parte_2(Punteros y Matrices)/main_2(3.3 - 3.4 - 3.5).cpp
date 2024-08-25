#include <iostream>
using namespace std;

const int MAXCOLUMNS = 4;// Número de columnas de la matriz

void printVector(int *vector, int num_componentes){
    /**
     * -3.3- Tenemos la función siguiente que muestra los valores de un vector
     */
    for (int i = 0; i < num_componentes; i++){ // Recorremos el vector
        cout << vector[i]<<" ";
    }
    cout << endl;
}

void printMatrix(int matrix[][MAXCOLUMNS], int num_filas, int num_columnas){
    /**
     * -3.3- Implementar dicha función llamando a la función anterior, mostrando una fila por línea.
     * Crear el programa principal para mostrar que funciona.
     */
    for (int i = 0; i < num_filas; i++){
        printVector(matrix[i], num_columnas);// Imprimimos cada fila de la matriz
    }
}

void printMatrixReversed(int matrix[][MAXCOLUMNS], int num_filas, int num_columnas){
    /**
     * -3.4- Crear una nueva función printMatrixReversed, usando punteros, similar a la anterior
     */
    for (int i = num_filas-1; i >= 0; i--){// Recorremos la matriz en orden inverso   
        printVector(matrix[i], num_columnas);// Imprimimos cada fila de la matriz en orden inverso
    }
    /* --Otra forma de hacerlo--
        for (int i = num_filas; i > 0; i--){// Recorremos la matriz en orden inverso   
            printVector(matrix[i-1], num_columnas);// Imprimimos cada fila de la matriz en orden inverso
        }
    */
    
}

int main(){
    int num_filas = 4;
    int matriz[num_filas][MAXCOLUMNS] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};// Matriz de 3x3

    printMatrix(matriz, num_filas, MAXCOLUMNS);
    cout <<"-----------"<< endl;
    printMatrixReversed(matriz, num_filas, MAXCOLUMNS);
    cout <<"-----------"<< endl;

    /**
     * -3.5- Haz un programa con una matriz, y muestra cómo puede ser mostrada sin usar la operación de índice.
     */
    int *p = &matriz[0][0];// Inicializamos el puntero a la primera posición de la matriz 
    for (int i = 0; i < num_filas; i++){
        for (int j = 0; j < MAXCOLUMNS; j++){
            // Mostramos la matriz mediante punteros
            cout << *p << " ";
            p++;
        }
        cout << endl;
    }
    

}