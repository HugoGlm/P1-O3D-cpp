#include <iostream>
#include "Menu/Menu.h"
#include "Reservation/Add/AddReservation.h"

int main()
{
    AddReservation resa = AddReservation();
    Menu menu = Menu();
    //menu.Execute();
    resa.Execute();
}