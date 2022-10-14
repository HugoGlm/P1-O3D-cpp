#include <iostream>
#include "Map.h"
#include "Environment.h"
#include "Player.h"
#include "Utils.h"
#include "Case.h"
#include "Vector2.h"

int main()
{
    Map map = Map("Map");
    if (!map.IsValid())
        return -4;
    while (!map.GetPlayer()->Position()->Equals(map.Exit()->Position()))
    {
        system("cls");
        map.Display();
        map.GetPlayer()->Move();
    }
    system("cls");
    Utils::Log(map.GetPlayer()->Name() + " find the exit !");
}