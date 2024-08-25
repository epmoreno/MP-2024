#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    /**
     * Haya el programa para convertir cada elemento del vector en el resto de dividir dicho elemento entre 3,
     * utilizando únicamente la variable puntero, no se pueden definir más variables.
     */

    const int max_enteros = 6;
    int v_enteros[max_enteros] = {3, 3, 3, 3, 3, 3};
    int *puntero = v_enteros;

    cout << "Los valores del vector son: ";
    while (puntero < &v_enteros[max_enteros]){ // &v_enteros[max_enteros] es la dirección de memoria del último elemento del vector
        cout <<*puntero;
        if(puntero != &v_enteros[max_enteros]-1){cout << "-";}

        *puntero = *puntero%3;// Se modifica el valor del elemento del vector
        
        puntero++;// Se avanza al siguiente elemento del vector
    }
    cout << endl;

    puntero = v_enteros;// Se reinicia el puntero al primer elemento del vector

    cout << "Los restos de dichos valores divididos entre 3 son: ";
    while (puntero < &v_enteros[max_enteros]){
        cout <<*puntero;
        if(puntero != &v_enteros[max_enteros]-1){cout << "-";}
        puntero++;
    }
    cout << endl;
    
    


    
}