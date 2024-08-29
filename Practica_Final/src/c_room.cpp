#include "../include/c_room.hpp"

Room::Room(){
    this->num_room = 0;
    this->tipo = INDIVIDUAL;
    this->precio_noche = 0;
};

Room::Room(int num_room, RoomType tipo, double precio_noche){
    this->num_room = num_room;
    this->tipo = tipo;
    this->precio_noche = precio_noche;
};

Room::Room(const Room &room){
    this->num_room = room.num_room;
    this->tipo = room.tipo;
    this->precio_noche = room.precio_noche;
};

int Room::getNumRoom(){
    return this->num_room;
};
RoomType Room::getTipo(){
    return this->tipo;
};
double Room::getPrecioNoche(){
    return this->precio_noche;
};

void Room::setNumRoom(int num_room){
    this->num_room = num_room;
};
void Room::setTipo(RoomType tipo){
    this->tipo = tipo;
};
void Room::setPrecioNoche(double precio_noche){
    this->precio_noche = precio_noche;
};

Room::~Room(){
    //Destructor
};
