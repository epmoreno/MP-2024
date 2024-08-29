#include "../include/c_reservation.hpp"

Reservation::Reservation(){
    this->numero_reserva = 0;
    this->num_guests = 1;

    this->room = new Room();
    this->room->setTipo(INDIVIDUAL);
    this->room->setPrecioNoche(50);

    // Se inicializa con un solo huesped
    this->guests = new Guest*[num_guests];
    this->guests[0] = new Guest();
    
    //LAS FECHAS DE ENTRADA Y SALIDA SE INICIALIZAN CON EL CONSTRUCTOR POR DEFECTO DE LA CLASE DATE
    this->fecha_entrada = Date();
    this->fecha_salida = Date();
};
Reservation::Reservation(Guest **guests, int num_guests, Date fecha_entrada, Date fecha_salida){
    this->numero_reserva = 0;
    this->num_guests = num_guests;

    this->room = new Room();
    if (this->num_guests == 1){
        this->room->setTipo(INDIVIDUAL);
        this->room->setPrecioNoche(50);    
    }else if( this->num_guests == 2){
        this->room->setTipo(DOBLE);
        this->room->setPrecioNoche(100);
    }else if( this->num_guests > 2 && this->num_guests <= 4){
        this->room->setTipo(SUITE);
        this->room->setPrecioNoche(200);
    }else{
        this->room->setTipo(INDIVIDUAL);
        this->room->setPrecioNoche(99);
    }

    this->guests = guests;
    this->fecha_entrada = fecha_entrada;
    this->fecha_salida = fecha_salida;
};

Reservation::Reservation(const Reservation &reserva){
    this->numero_reserva = reserva.numero_reserva;
    this->num_guests = reserva.num_guests;

    this->room = new Room(*reserva.room);
    
    this->guests = new Guest*[num_guests];
    for (int i = 0; i < this->num_guests; i++){
        this->guests[i] = new Guest(*reserva.guests[i]);
    }
    
    this->fecha_entrada = reserva.fecha_entrada;
    this->fecha_salida = reserva.fecha_salida;
};

int Reservation::getNumeroReserva(){
    return this->numero_reserva;
};
Room *Reservation::getRoom(){
    return this->room;
};
int Reservation::getNumGuests(){
    return this->num_guests;
};
Guest **Reservation::getGuests(){
    return this->guests;
};
Date Reservation::getFechaEntrada(){
    return this->fecha_entrada;
};
Date Reservation::getFechaSalida(){
    return this->fecha_salida;
};

void Reservation::setNumeroReserva(int numero_reserva){
    this->numero_reserva = numero_reserva;
};
void Reservation::setRoom(Room *room){
    this->room = room;
};
void Reservation::setNumGuests(int num_guests){
    this->num_guests = num_guests;
};
void Reservation::setGuests(Guest **guests){
    this->guests = guests;
};
void Reservation::setFechaEntrada(Date fecha_entrada){
    this->fecha_entrada = fecha_entrada;
};
void Reservation::setFechaSalida(Date fecha_salida){
    this->fecha_salida = fecha_salida;
};

// HACER PRIMERO QUE FUNCIONE LA CLASE GUEST STAFF Y ROOM ANTES DE CONTINUAR
bool Reservation::addGuests(Guest *guests){return true;};
bool Reservation::removeGuests(Guest *guests){return true;};

Reservation::~Reservation(){
    delete room;
    for (int i = 0; i < this->num_guests; i++){
        delete guests[i];
    }
    delete[] guests;
};