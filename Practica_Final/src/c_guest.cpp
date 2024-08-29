#include "../include/c_guest.hpp"

Guest::Guest(){
    this->nombre = "";
    this->ID = 0;
    this->numero_telefono = 0;
    this->genero = FEMALE;
};
Guest::Guest(std::string nombre, int ID, int numero_telefono, Genero genero){
    this->nombre = nombre;
    this->ID = ID;
    this->numero_telefono = numero_telefono;
    this->genero = genero;
};
Guest::Guest(const Guest &guest){
    this->nombre = guest.nombre;
    this->ID = guest.ID;
    this->numero_telefono = guest.numero_telefono;
    this->genero = guest.genero;
};

std::string Guest::getNombre(){
    return this->nombre;
};
int Guest::getID(){
    return this->ID;
};
int Guest::getNumeroTelefono(){
    return this->numero_telefono;
};
Genero Guest::getGenero(){
    return this->genero;
};

void Guest::setNombre(std::string nombre){
    this->nombre = nombre;
};
void Guest::setID(int ID){
    this->ID = ID;
};
void Guest::setNumeroTelefono(int numero_telefono){
    this->numero_telefono = numero_telefono;
};
void Guest::setGenero(Genero genero){
    this->genero = genero;
};

Guest::~Guest(){
    //Destructor
};