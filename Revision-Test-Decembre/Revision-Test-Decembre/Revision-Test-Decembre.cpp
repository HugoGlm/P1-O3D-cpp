#include <iostream>
#include "Menu/Home/HomeMenu.h"
#include "LinkedList/List.h"

int main()
{
	List<int> list = List<int>();
	list.AddFirst(10);
	list.AddFirst(15);
	list.Display();
	list.Remove(15);
	list.Display();
	

	/*HomeMenu home = HomeMenu();
	home.Open();
	home.Update();*/
}