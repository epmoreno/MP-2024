#include "../include/c_hotel.hpp"
#include <iostream>

using namespace std;

int main(){
    Hotel trivago = Hotel("Trivago", "Calle Falsa 123", 5);
    cout << trivago.getNombre() << endl;
    /*Room *room1 = new Room(1, SUITE, 200);*/

    Guest **guestsSuite = new Guest*[3];
    guestsSuite[0] = new Guest("Ana", 10, 333333333, FEMALE);
    guestsSuite[1] = new Guest("Enrique", 11, 444444444, MALE);
    guestsSuite[2] = new Guest("Nala",12,555555555,FEMALE);

    /*for (int i = 0; i < 3; i++){
        cout << guestsSuite[i]->getNombre() << "\n";
    }
    cout<< endl;*/

    Guest **guestsDoble = new Guest*[2];
    guestsDoble[0] = new Guest("Andres", 20, 666666666, MALE);
    guestsDoble[1] = new Guest("Susana",21,777777777,FEMALE);

    /*for (int i = 0; i < 2; i++){
        cout << guestsDoble[i]->getNombre() << "\n";
    }
    cout<< endl;*/

    Guest **guestsIndividual = new Guest*[1];
    guestsIndividual[0] = new Guest("Jorge", 30, 888888,MALE);

    /*cout << guestsIndividual[0]->getNombre() << endl;*/


    Reservation **reservas_0 = new Reservation*[3];
    reservas_0[0] = new Reservation(guestsSuite, 3, Date(1,1,2024), Date(3,1,2024));
    reservas_0[1] = new Reservation(guestsDoble, 2, Date(2,1,2024), Date(3,1,2024));
    reservas_0[2] = new Reservation(guestsIndividual, 1, Date(3,1,2024), Date(3,1,2024));

    /*cout << reservas_0[0]->getRoom()->getTipo() << endl;
    cout << reservas_0[1]->getRoom()->getTipo() << endl;
    cout << reservas_0[2]->getRoom()->getTipo() << endl;*/

    Staff *staff1 = new Staff("Juan", 1, MANAGER);
    Staff *staff2 = new Staff("Pedro", 2, EMPLOYEE);

    cout << staff1->getNombre() << endl;
    cout << staff2->getNombre() << endl;

    staff1->addReserva(reservas_0[0]);
    staff1->addReserva(reservas_0[1]);
    staff1->addReserva(reservas_0[2]);

    cout << staff1->getNumReservas() << endl;
    cout << staff1->getMaxReservas() << endl;

    staff1->removeReserva(reservas_0[0]);
    cout << staff1->getNumReservas() << endl;

    // Borrados de memoria instalabes en sus respectiva clase

    //delete room1;
    //delete room2;
    //delete room3;

    // Una vez que es implementada en una reserva no es necesario borrar la memoria de los huespedes
    /* for (int i = 0; i < 3; i++){
        delete guestsSuite[i];
    }
    delete[] guestsSuite;

   for (int i = 0; i < 2; i++){
        delete guestsDoble[i];
    }
    delete[] guestsDoble;

    for (int i = 0; i < 1; i++){
        delete guestsIndividual[i];
    }
    delete[] guestsIndividual; */
    
    // Borrado de memoria de reservas, lo que produce que se borre los guests de cada reserva.
    /*for (int i = 0; i < 3; i++)
    {
        delete reservas_0[i];
    }*/
    delete[] reservas_0; // Necesario para borrar la memoria de las reservas hasta que se implemente en la clase hotel
    
    delete staff1;
    delete staff2;
    
    return 0;
}
