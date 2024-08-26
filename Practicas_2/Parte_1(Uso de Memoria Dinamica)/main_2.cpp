#include <iostream>

using namespace std;

void repite_items(int *&valores, int &tamaño){
    int contador = 0;// Contador para saber cuantos elementos se van a agregar
    for (int i = 0; i < tamaño; i++){
        contador += valores[i]%(3+1);
    }
    contador += tamaño;// Sumamos el tamaño original del vector
    int *aux_valores = new int[contador];// Creamos un nuevo vector con el tamaño necesario
    
    int resto = 0;int indice = 0; // Variable para guardar el resto de la division y el indice del nuevo vector auxiliar
    for (int i = 0; i < tamaño; i++){
    
        aux_valores[indice] = valores[i]; indice++; // Agregamos el valor original al nuevo vector y aumentamos el indice
        resto = valores[i]%(3+1);// Hayamos el resto del primer valor

        if (resto != 0){ // Si el resto es diferente de 0
            for (int j = 0; j < resto; j++){// Agregamos el valor las veces que indique el resto
                aux_valores[indice] = valores[i]; indice++;// Agregamos el valor al nuevo vector y aumentamos el indice
            }
        }
    }

    delete[] valores;// Borramos el vector original
    valores = aux_valores;// Igualamos el vector original al nuevo vector
    tamaño = contador;// Igualamos el tamaño al nuevo tamaño
}

int main(){
    /**
     * Se tiene un vector de elementos enteros. Se desea implementar una función que repita cada elemento un
     * número de veces igual al resto de dividir dicho elemento entre 3 + 1 como valor tenga. Por ejemplo, si
     * el vector original contiene los valores {1, 30, 68, 25} el vector final será {1, 1, 30, 68, 68, 68, 25, 25}.
     * Evidentemente, esto supone incrementar la memoria del vector.
     * 
     * void repite_items(int *&values, int &size);
     */

    int tamaño = 4;// Tamaño del vector
    int *valores = new int[tamaño];// Vector dinamico

    valores[0] = 1, valores[1] = 30, valores[2] = 68, valores[3] = 25;
    
    repite_items(valores, tamaño);

    for (int i = 0; i < tamaño; i++){
        cout << valores[i] << " ";
    }
    cout<<endl;

    delete[] valores;// Liberamos la memoria reservada para el vector valores
}