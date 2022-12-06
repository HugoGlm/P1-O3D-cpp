#include <iostream>
#include "Menu/Menu.h"
#include "Reservation/Add/AddReservation.h"
#include "Reservation/View/ViewReservation.h"

int main()
{
    AddReservation resa = AddReservation();
    ViewReservation view = ViewReservation();
    Menu menu = Menu();
    //menu.Execute();
    resa.Execute();
    //view.Execute();
}

// probleme je ne peux pas lancer une window sans commenter les autres