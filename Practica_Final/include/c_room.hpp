#ifndef C_ROOM_HPP
#define C_ROOM_HPP

enum RoomType{INDIVIDUAL, DOBLE, SUITE};

class Room{
    private:
        int num_room;
        RoomType tipo;
        double precio_noche;
    public:
        Room();
        Room(int num_room, RoomType tipo, double precio_noche);

        int getNumRoom();
        RoomType getTipo();
        double getPrecioNoche();

        void setNumRoom(int num_room);
        void setTipo(RoomType tipo);
        void setPrecioNoche(double precio_noche);

        ~Room();
};

#endif