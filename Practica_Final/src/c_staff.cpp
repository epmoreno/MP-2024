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

bool Staff::addReserva(Reservation *reserva){
    // Verificamos si esta en el arreglo
    for (int  i = 0; i < this->num_reservas; i++){
        if (this->reservas[i] == reserva){
            return false;
        }
    }
    
    // Si no tenemos espacio en el arreglo, creamos uno nuevo con el doble de espacio
    if(this->num_reservas == this->max_reservas){
        int nuevo_num_reservas = this->max_reservas * 2;
        Reservation **aux_reservas = new Reservation*[nuevo_num_reservas];
        for (int i = 0; i < this->num_reservas; i++){
            aux_reservas[i] = this->reservas[i];
            this->reservas[i] = nullptr;
        }
        this->num_reservas += 1;
        reserva->setNumeroReserva(this->num_reservas);
        aux_reservas[this->num_reservas] = reserva;
        for (int i = 0; i < this->num_reservas; i++){
            delete this->reservas[i];
        }
        delete[] this->reservas;
        
        this->reservas = aux_reservas;
        this->max_reservas = nuevo_num_reservas;
        return true;
    
    }

    // Si hay espacio en el arreglo, lo agregamos
    else{
        reserva->setNumeroReserva(this->num_reservas+1);
        this->reservas[this->num_reservas] = reserva;
        this->num_reservas += 1;
        return true;
    }

    // En el peor de los casos, retornamos false
    return false;
};
bool Staff::removeReserva(Reservation *reserva){
    for (int i = 0; i < this->num_reservas; i++){
        if (reserva->getNumeroReserva() == this->reservas[i]->getNumeroReserva()){
            delete this->reservas[i];
            for (int j = i; j < this->num_reservas; j++){
                this->reservas[j] = this->reservas[j+1];
            }
            this->num_reservas -= 1;
            return true;
        }
    }
    return false;
};

Staff::~Staff(){
    for (int i = 0; i < this->num_reservas; i++){
        delete this->reservas[i];
    }
    delete[] this->reservas;
};
