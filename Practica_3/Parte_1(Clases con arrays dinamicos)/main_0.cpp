#include <iostream>

using namespace std;

class Persona{
    private:
        string nombre;
        string apellido;
        int edad;
        int max_amigos;
        int num_amigos;
        Persona **amigos;

    public:
        /**
         * Constructores.
         * 
         * Crea un constructor de la clase Persona que inicialice el nombre, el apellido y la edad. 
         * La persona se creará sin ningún amigo. Se reservará espacio para almacenar hasta 8 amigos de esa persona.
         */
        Persona(){
            this->nombre = "";
            this->apellido = "";
            this->edad = 0;
            this->max_amigos = 8;
            this->num_amigos =0;
            this->amigos = new Persona*[max_amigos]; 
        };

        
        Persona(string nombre, string apellido, int edad){
            this->nombre = nombre;
            this->apellido = apellido;
            this->edad = edad;
            this->max_amigos = 8;
            this->num_amigos = 0;
            this->amigos = new Persona*[max_amigos];
        };

        /**
         * Getters y Setters.
         * 
         * Metodos basicos para poder manejar la clase correctamente.
         */
        string getNombre(){
            return this->nombre;
        };
        string getApellido(){
            return this->apellido;
        };
        int getEdad(){
            return this->edad;
        };
        int getNumAmigos(){
            return this->num_amigos;
        };
        
        void setNombre(string nombre){
            this->nombre = nombre;
        };
        void setApellido(string apellido){
            this->apellido = apellido;
        };
        void setEdad(int edad){
            this->edad = edad;
        };
        void setNumAmigos(int num_amigos){
            this->num_amigos = num_amigos;
        };

        /**
         * Metodo para añadir amigos.
         * 
         * Crea un método de la clase Persona al que se le pasará un puntero a Persona, 
         * añadiendola como amiga si no se ha alcanzado el máximo. 
         * Si se ha añadido con éxito, devolverá verdarero; falso en caso contrario.
         */
        bool add_amigo(Persona *nuevo_amigo){
            if(this->num_amigos != this->max_amigos){
                this->amigos[this->num_amigos] = nuevo_amigo;
                this->num_amigos++;
                return true;
            }else {
                return false;
            }
        };

        /**
         * Metodo para buscar amigos.
         * 
         * Crea un método de la clase Asignatura al que se le pasará el nombre y el primer apellido de otra persona.
         * Dicho método buscará en los amigos de la persona y devolverá un puntero a la persona correspondiente. 
         * Si no se encuentra o no existe, se devolverá un puntero a NULL.
         */
        Persona *buscar_amigo(string nombre, string primer_apellido){
            for (int i = 0; i < this->getNumAmigos(); i++){
                if(this->amigos[i]->getNombre() == nombre && this->amigos[i]->getApellido() == primer_apellido){
                    return this->amigos[i];
                }
            }
            return NULL;
        };

        /**
         * Destructor.
         * 
         * Implementar el destructor de la clase Persona. 
         * Dicho destructor deberá de liberar la memoria reservada para almacenar los amigos de la persona.
         */
        ~Persona(){
            delete[] amigos;
        };    
};

int main(){
    /**
     * Progama Principal.
     * 
     * Crear a tres personas con los siguientes datos:
     * - Enrique Pinazo, 23 años.
     * - Ana Navarro, 24 años.
     * - Nala Moreno, 4 años.
     * Añadir a Nala como amiga de Enrique
     * Enrique como amigo de Ana 
     * Y Enrique y Nala como amigos de Ana.
     */
    Persona p1("Enrique","Pinazo",23);
    Persona p2("Ana","Navarro",24);
    Persona p3("Nala","Moreno",4);

    p1.add_amigo(&p3);
    p2.add_amigo(&p1);
    p2.add_amigo(&p3);

    cout << "Amigos de " << p1.getNombre()<< " : " << "\n" << 
    "   -"<<p1.buscar_amigo("Nala","Moreno")->getNombre() << endl;

    cout << "Amigos de " << p2.getNombre()<< " : " << "\n" << 
    "   -"<<p2.buscar_amigo("Nala","Moreno")->getNombre() << "\n" <<
    "   -"<<p2.buscar_amigo("Enrique","Pinazo")->getNombre() << endl;

    return 0;
}