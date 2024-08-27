#include "../include/c_hotel.hpp"

Hotel::Hotel(){
    this->nombre = "";
    this->direccion = "";
    this->numero_estrellas = 0;
    this->max_staff = 8;
    this->max_rooms = 8;
    this->num_staff = 0;
    this->num_rooms = 0;
    this->staff_miembros = new Staff*[max_staff];
    this->rooms = new Room*[max_rooms];
};
Hotel::Hotel(std::string nombre, std:: string direccion, int numero_estrellas){
    this->nombre = nombre;
    this->direccion = direccion;
    this->numero_estrellas = numero_estrellas;
    this->max_staff = 8;
    this->max_rooms = 8;
    this->num_staff = 0;
    this->num_rooms = 0;
    this->staff_miembros = new Staff*[max_staff];
    this->rooms = new Room*[max_rooms];
};

std::string Hotel::getNombre(){
    return this->nombre;
};
std::string Hotel::getDireccion(){
    return this->direccion;
};
int Hotel::getNumEstrellas(){
    return this->numero_estrellas;
};
int Hotel::getMaxStaff(){
    return this->max_staff;
};
int Hotel::getMaxRooms(){
    return this->max_rooms;
};
int Hotel::getNumStaff(){
    return this->num_staff;
};
int Hotel::getNumRooms(){
    return this->num_rooms;
};

void Hotel::setNombre(std::string nombre){
    this->nombre =nombre;
};
void Hotel::setDireccion(std::string direccion){
    this->direccion = direccion;
};
void Hotel::setNumEstrellas(int numero_estrellas){
    this->numero_estrellas = numero_estrellas;
};
void Hotel::setMaxStaff(int max_staff){
    this->max_staff = max_staff;
};
void Hotel::setMaxRooms(int max_rooms){
    this->max_rooms = max_rooms;
};
void Hotel::setNumStaff(int num_staff){
    this->num_staff = num_staff;
};
void Hotel::setNumRooms(int num_rooms){
    this->num_rooms = num_rooms;
};

// HACER PRIMERO SUS CLASES CORRESPONDIENTES ANTES DE CONTINUAR.
bool Hotel::addStaff(Staff *new_miembro){};
bool Hotel::addRoom(Room *new_room){};

bool Hotel::removeStaffMember(Staff *miembro_a_eliminar){};
bool Hotel::removeRoom(Room *room_a_eliminar){};

bool Hotel::addReserva(Reservation *reserva){};
bool Hotel::removeReserva(Reservation *reserva){};

Hotel::~Hotel(){
    delete[] staff_miembros;
    delete[] rooms;
};