#include <iostream>
#include <FString.h>
#include <Object.h>

int main()
{
    Core::Object* o = new Core::Object();
    const Core::PrimitiveType::FString _str = Core::PrimitiveType::FString("tlqs,fksqdnf");
    std::cout << _str;
    delete o;
}