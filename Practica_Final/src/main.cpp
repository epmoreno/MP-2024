#include "../include/c_hotel.hpp"
#include <iostream>

using namespace std;

int main(){
    Hotel trivago = Hotel("Trivago", "Calle Falsa 123", 5);
    cout << trivago.getNombre() << endl;
}
