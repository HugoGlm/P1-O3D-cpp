#include <iostream>
#include <string>
#include "CInventory.h"
#include "HealPotion.h"
#include "Player.h"
#include "Utils.h"
#include "CItem.h"
#include "Weapon.h"

int main()
{
    std::string _name = Utils::UserChoice<std::string>("choose your username : ");
    Player player = Player(_name);
    player.GetInventory()->AddItem(new HealPotion(50.0f));
    player.GetInventory()->AddItem(new HealPotion(50.0f));
    player.GetInventory()->AddItem(new HealPotion(25.0f));
    player.GetInventory()->AddItem(new Weapon("Bada-boom", 95.0f));

    int _choice = 0;

    while (!player.IsDead())
    {
        system("CLS");
        player.GetInventory()->DisplayInventory();
        std::cout << "choose your item : ";
        std::cin >> _choice;
        player.GetInventory()->UseItem(_choice);
        system("pause");
    }
    system("cls");
    std::cout << player.Name() << " is dead !";
    return 0;
}