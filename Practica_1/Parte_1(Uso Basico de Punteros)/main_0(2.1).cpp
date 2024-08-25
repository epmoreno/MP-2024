#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    /**
     * -2.1-
     * 1- Copiar y completar el código para que haga lo que se pide entre comentarios. 
     * 2- Comprobar mediante mensajes por pantalla que se hacen las modificaciones correctamente:
     */

    int entero = 10;
    int *puntero_entero, **puntero_puntero;

    puntero_entero = &entero; // Asignar la dirección de memoria de la variable entero al puntero puntero_entero
    puntero_puntero = &puntero_entero; // Asignar la dirección de memoria de la variable puntero_entero al puntero puntero_puntero

    *puntero_entero = 15; // Modificar el valor de la variable entero a través del puntero puntero_entero
    cout << "Valor de entero modificador por la variable puntero_entero: " << entero << endl;

    **puntero_puntero = 20; // Modificar el valor de la variable entero a través del puntero puntero_puntero
    cout << "Valor de entero modificador por la variable puntero_puntero: " << entero << endl;
    
    return 0;
}