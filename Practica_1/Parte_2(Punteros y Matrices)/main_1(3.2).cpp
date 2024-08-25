#include <iostream>
using namespace std;

void suma_puntuaciones( int *puntuaciones, int num_puntuaciones){
    /**
     * Se desea realizar una función que aumente en 5 las puntuaciones de las personas de las posiciones impares.
     * La puntuación nunca puede ser mayor que 150. 
     * Recorrer la estructura mediante punteros, no con índices.
     */
    int contador = 1;
    for (; contador <= num_puntuaciones; contador++){
        if (contador%2 != 0){
            if (*puntuaciones >=0 && *puntuaciones <= 145){
               *puntuaciones = *puntuaciones+5;
            }
        }
        puntuaciones++;
    }
    /* --Otra forma de hacerlo--

        while (contador <= num_puntuaciones){
            if (contador%2 != 0){
                if (*puntuaciones >=0 && *puntuaciones <= 145){
                *puntuaciones = *puntuaciones+5;
                }
                puntuaciones++,contador++;
            }
            else{
                puntuaciones++,contador++;
            }
        }
    */
}


int main(){
    int grupo = 10;
    int v_puntuaciones[grupo] = {55,68,49,32,45,18,96,35,150,110};
    int *puntuaciones;
    puntuaciones = v_puntuaciones;

    cout << "Las puntuaciones originales son: ";
    for (; puntuaciones < &v_puntuaciones[grupo]; puntuaciones++){ // &v_puntuaciones[grupo] es la dirección de memoria del último elemento del vector
        cout << *puntuaciones << " ";
    }
    cout << endl;

    puntuaciones = v_puntuaciones;
    
    suma_puntuaciones(puntuaciones, grupo);

    cout << "Las puntuaciones corregidas son: ";
    for (; puntuaciones < &v_puntuaciones[grupo]; puntuaciones++){
        cout << *puntuaciones << " ";
    }
    cout << endl;
}