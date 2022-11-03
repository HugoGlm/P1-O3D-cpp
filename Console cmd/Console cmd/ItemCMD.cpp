#include "ItemCMD.h"

#pragma region constructor
ItemCMD::ItemCMD(const std::string _name, const std::string _desc)
{
    name = _name;
    description = _desc;
}
ItemCMD::~ItemCMD()
{
    name = nullptr;
    description = nullptr;
}
#pragma endregion
#pragma region methods
std::string ItemCMD::Name()
{
    return name;
}
std::string ItemCMD::Description()
{
    return description;
}
#pragma endregion