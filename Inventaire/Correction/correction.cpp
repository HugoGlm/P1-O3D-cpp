#include <iostream>
#include "Map.h"
#include "Environment.h"

int main()
{
    Map map = Map("Map");
    if (!map.IsValid())
        return -4;
    map.Display();
}