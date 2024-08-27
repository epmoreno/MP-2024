#ifndef C_HOTEL_HPP
#define C_HOTEL_HPP

#include <string>
#include "c_room.hpp"
#include "c_staff.hpp"

class Hotel{
    private:
        std::string nombre;
        std::string direccion;
        int numero_estrellas;
        int max_staff;
        int max_rooms;
        int num_staff;
        int num_rooms;
        Staff **staff_miembros;
        Room **rooms;
    
    public:
        Hotel();
        Hotel(std::string nombre, std:: string direccion, int numero_estrellas);

        std::string getNombre();
        std::string getDireccion();
        int getNumEstrellas();
        int getMaxStaff();
        int getMaxRooms();
        int getNumStaff();
        int getNumRooms();

        void setNombre(std::string nombre);
        void setDireccion(std::string direccion);
        void setNumEstrellas(int numero_estrellas);
        void setMaxStaff(int max_staff);
        void setMaxRooms(int max_rooms);
        void setNumStaff(int num_staff);
        void setNumRooms(int num_rooms);

        bool addStaff(Staff *new_miembro);
        bool addRoom(Room *new_room);

        bool removeStaffMember(Staff *miembro_a_eliminar);
        bool removeRoom(Room *room_a_eliminar);

        bool addReserva(Reservation *reserva);
        bool removeReserva(Reservation *reserva);

        ~Hotel();
};

#endif