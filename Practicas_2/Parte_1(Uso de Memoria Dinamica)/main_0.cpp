#include <iostream>

using namespace std;

int main(){
    /**
     * En este caso vamos a escribir un vector de forma dinámica.
     * Escribir un programa que le pida al usuario un número de palabras a introducir, luego reservar memoria
     * para almacenarlos, e imprimirlos en orden inverso. Dicho vector se reservará de forma dinámica usando
     * la mínima memoria posible.
     */
    int num_palabras;
    string *palabras;

    cout << "Cuantas palabras desea ingresar: ";
    cin>>num_palabras;

    palabras = new string[num_palabras];// Reservamos memoria para el vector de palabras
    for(int i=0; i<num_palabras; i++){
        cout << "Ingrese la palabra " << i+1 << ": ";
        cin >> palabras[i];
    }

    cout << "Las palabras ingresadas son: ";
    for (int i = 0; i < num_palabras; i++){
        cout << palabras[i] << " ";
    }
    cout<<endl;
    
    delete[] palabras;// Liberamos la memoria reservada para el vector de palabras
    return 0;
}