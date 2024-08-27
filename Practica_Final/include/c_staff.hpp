#ifndef C_STAFF_HPP
#define C_STAFF_HPP

#include <string>
#include "c_reservation.hpp"

enum Rol{MANAGER, EMPLOYEE};

class Staff{
    private:
        std::string nombre;
        int numero_ID;
        Rol rol;
        int max_reservas;
        int num_reservas;
        Reservation **reservas;
    public:
        Staff();
        Staff(std::string nombre, int numero_ID, Rol rol);
        ~Staff();

        std::string getNombre();
        int getNumeroID();
        Rol getrol();
        int getMaxReservas();
        int getNumReservas();

        void setNombre(std::string nombre);
        void setNumeroID(int numero_ID);
        void setRol(Rol rol);
        void setMaxReservas(int max_reservas);
        void setNumReservas(int num_reservas);

        bool addReserva(Reservation *reserva);
        bool removeReserva(Reservation *reserva);

};



#endif