#include <iostream>
#include "Environment.h"
#include "Utils.h"
#include "StringUtils.h"
#include "Path.h"
#include "Directory.h"

int main()
{
    /*if (Directory::Exist(Environment::CurrentDirectory()))
        Utils::log("Exist !");
    Directory::Create(Path::GetPath("C:\\Test"));
    if (!Directory::Exist("C:\\Test"))
        Utils::log("Test doesn't exist !");
    else
        Utils::log("Test exist !");

    if (Directory::Delete("C:\\Test"))
        Utils::log("Test deleted!");*/

    Directory d = Directory(Environment::CurrentDirectory());
}