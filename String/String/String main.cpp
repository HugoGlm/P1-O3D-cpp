#include <iostream>
#include "String.h"

int main()
{
    String s = String("Ok");

    std::cout << s.ToLower() << std::endl;
    std::cout << s.ToUpper() << std::endl;
}