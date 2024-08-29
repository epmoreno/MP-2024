#ifndef C_GUEST_HPP
#define C_GUEST_HPP

#include <string>

enum Genero{FEMALE, MALE};

class Guest{
    private:
        std::string nombre;
        int ID;
        int numero_telefono;
        Genero genero;

    public:
        Guest();
        Guest(std::string nombre, int ID, int numero_telefono, Genero genero);
        Guest(const Guest &guest);
        ~Guest();

        std::string getNombre();
        int getID();
        int getNumeroTelefono();
        Genero getGenero();

        void setNombre(std::string nombre);
        void setID(int ID);
        void setNumeroTelefono(int numero_telefono);
        void setGenero(Genero genero);
};

#endif