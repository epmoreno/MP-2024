#include <iostream>

using namespace std;

class MatrizDinamica{
    private:
        int num_filas;
        int num_columnas;
        int **matriz;
    public:
        /**
         * Contructor.
         * 
         * Crea un constructor de la clase MatrizDinamica con parámetros el número de filas y el número de columnas.
         * El constructor deberá inicializar esos atributos y reservar el espacio justo para almacenar una matriz con
         * ese número de filas y columnas.
         */
        MatrizDinamica(int num_filas, int num_columnas){
            this->num_filas = num_filas;
            this->num_columnas = num_columnas;
            this->matriz = new int*[num_filas];
            for (int i = 0; i < num_filas; i++){
                this->matriz[i] = new int[num_columnas];
            }    
        };
        /**
         * Constructor de copia.
         * 
         * Crea un construtor de copia para copiar debidamente un objeto de la clase MatrizDinamica en otro.
         */
        MatrizDinamica(const MatrizDinamica &matrix){
            this->num_filas = matrix.num_filas;
            this->num_columnas = matrix.num_columnas;
            this->matriz = new int*[this->num_filas];
            for (int i = 0; i < this->num_filas; i++){
                this->matriz[i] = new int[this->num_columnas];
                for (int j = 0; j < this->num_columnas; j++){
                    this->matriz[i][j] = matrix.matriz[i][j];
                }
            }
        };


        /**
         * Getters y Setters.
         * 
         * Metodos basicos para poder manejar la clase correctamente.
         */
        int getNumFilas(){
            return this->num_filas;
        };
        int getNumColumnas(){
            return this->num_columnas;
        };
        int getElemento(int fila, int columna){
            return this->matriz[fila][columna];
        };
        void setElemento(int fila, int columna, int valor){
            this->matriz[fila][columna] = valor;
        };
        void setNumFilas(int n_filas){
            this->num_filas = n_filas;
        };
        void setNumColumnas(int n_columnas){
            this->num_columnas = n_columnas;
        };
        void mostrarMatriz(){
            for (int i = 0; i < this->num_filas; i++){
                for (int j = 0; j < this->num_columnas; j++){
                    cout << this->matriz[i][j] << " ";
                }
                cout << endl;
            }
        };

        /**
         * Metodo para añadir una fila.
         * 
         * Implementa un método aniadirFila que añada una fila a la matriz. 
         * Dicho método tendrá que aunmentar en 1 el número de filas y reservar espacio para la nueva matriz.
         */
        void add_fila(int *fila){
            // Crear una nueva matrizDinamica con una fila adicional.
            int nuevo_tama = this->num_filas + 1;
            int **new_matriz = new int*[nuevo_tama];
            for (int i = 0; i < nuevo_tama; i++){
                new_matriz[i] = new int[this->num_columnas];
            }
            
            // Copiar la matriz original a la nueva matriz si esta posee valores.
            for (int i = 0; i < this->num_filas; i++){
                for (int j = 0; j < this->num_columnas; j++){
                    new_matriz[i][j] = this->matriz[i][j];
                }
            }

            // Agregar la nueva fila a la nueva matriz.
            for (int i = 0; i < this->num_columnas; i++)
            {
                new_matriz[this->num_filas][i] = fila[i];
            }
            
            // Liberar la memoria de la matriz original.
            for (int i = 0; i < this->num_filas; i++) {
                delete[] this->matriz[i];
            }
            delete[] this->matriz;

            // Asignar la nueva matriz a la matriz original y modificamos valor del tamaño.
            this->matriz = new_matriz;
            this->num_filas = nuevo_tama;

            delete[] fila;        
        };
        
        /**
         * Destructor.
         * 
         * Implementar el destructor de la clase MatrizDinamica. 
         * Dicho destructor deberá de liberar la memoria reservada para el objeto de la clase.
         */
        ~MatrizDinamica(){
            for (int i = 0; i < this->num_filas; i++){
                delete[] this->matriz[i];
            }
            delete[] this->matriz;
        }
    

};


int main(){
    int num_filas = 3;
    int num_columnas = 3;
    // Todos vectores deben tener el mismo tamaño que el número de columnas.
    int *f_0 = new int[num_columnas];f_0[0] = 10;f_0[1] = 11;f_0[2] = 12;
    int *f_1 = new int[num_columnas];f_1[0] = 13;f_1[1] = 14;f_1[2] = 15;
    
    // Crear una matriz y Rellenarla.
    MatrizDinamica m_0(num_filas, num_columnas);
    m_0.setElemento(0,0,1);m_0.setElemento(1,0,4);m_0.setElemento(2,0,7);
    m_0.setElemento(0,1,2);m_0.setElemento(1,1,5);m_0.setElemento(2,1,8);
    m_0.setElemento(0,2,3);m_0.setElemento(1,2,6);m_0.setElemento(2,2,9);

    // Copiar la matriz m_0 a m_1.
    MatrizDinamica m_1(m_0);

    cout << " matriz 0: " << endl;
    m_0.mostrarMatriz();
    cout << endl;

    cout << " matriz 1 copiada: " << endl;
    m_1.mostrarMatriz();
    cout << endl;

    // Agregar una fila a la matriz.
    m_0.add_fila(f_0);
    m_1.add_fila(f_1);

    cout << " matriz 0 + fila_0: " << endl;
    m_0.mostrarMatriz();
    cout << endl;

    cout << " matriz 1 + fila_1: " << endl;
    m_1.mostrarMatriz();
    cout << endl;

    return 0;
}   