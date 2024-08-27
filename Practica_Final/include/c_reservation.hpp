#ifndef C_RESERVATION_HPP
#define C_RESERVATION_HPP

#include "c_room.hpp"
#include "c_guest.hpp"
#include "c_date.hpp"

class Reservation{
    private:
        int numero_reserva;
        Room *room;
        int num_guests;
        Guest **guests;
        Date fecha_entrada;
        Date fecha_salida;
    public:
        Reservation();
        Reservation(Guest **guests, int num_guests, Date fecha_entrada, Date fecha_salida);
        ~Reservation();
        
        int getNumeroReserva();
        Room *getRoom();
        int getNumGuests();
        Guest **getGuests();
        Date getFechaEntrada();
        Date getFechaSalida();

        void setNumeroReserva(int numero_reserva);
        void setRoom(Room *room);
        void setNumGuests(int num_guests);
        void setGuests(Guest **guests);
        void setFechaEntrada(Date fecha_entrada);
        void setFechaSalida(Date fecha_salida);

        bool addGuests(Guest *guests);
        bool removeGuests(Guest *guests);

};

#endif