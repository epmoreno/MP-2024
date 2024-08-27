#include "../include/c_staff.hpp"

Staff::Staff(){
    this->nombre = "";
    this->numero_ID = 0;
    this->rol = EMPLOYEE;
    this->max_reservas = 128;
    this->num_reservas = 0;
    this->reservas = new Reservation*[max_reservas];
};
Staff::Staff(std::string nombre, int numero_ID, Rol rol){
    this->nombre = nombre;
    this->numero_ID = numero_ID;
    this->rol = rol;
    this->max_reservas = 128;
    this->num_reservas = 0;
    this->reservas = new Reservation*[max_reservas];
};

std::string Staff::getNombre(){
    return this->nombre;
};
int Staff::getNumeroID(){
    return this->numero_ID;
};
Rol Staff::getrol(){
    return this->rol;
};
int Staff::getMaxReservas(){
    return this->max_reservas;
};
int Staff::getNumReservas(){
    return this->num_reservas;
};

void Staff::setNombre(std::string nombre){
    this->nombre = nombre;
};
void Staff::setNumeroID(int numero_ID){
    this->numero_ID = numero_ID;
};
void Staff::setRol(Rol rol){
    this->rol = rol;
};
void Staff::setMaxReservas(int max_reservas){
    this->max_reservas = max_reservas;
};
void Staff::setNumReservas(int num_reservas){
    this->num_reservas = num_reservas;
};

bool Staff::addReserva(Reservation *reserva){return true;};
bool Staff::removeReserva(Reservation *reserva){return true;};
