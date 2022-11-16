#include <iostream>
#include <FString.h>
#include <Object.h>
#include <Integer.h>
#include <Environment.h>
#include <Process.h>
#include <iostream>
#include <iomanip>

using namespace Core::PrimitiveType;
using namespace Core;

int main()
{


    const FString _path = "C:\\Users\\GUIL2804\\AppData\\Local\\Programs\\Opera GX\\launcher.exe";
    Core::Diagnostics::Process::Start(_path, "https://www.tusmo.xyz");

    /*std::cout << Environment::SpecialFolder(ESpecialFolder::Desktop) << std::endl;
    std::cout << Environment::SpecialFolder(ESpecialFolder::Programs) << std::endl;
    std::cout << Environment::SpecialFolder(ESpecialFolder::MyDocuments) << std::endl;
    std::cout << Environment::SpecialFolder(ESpecialFolder::MyMusic) << std::endl;
    std::cout << Environment::SpecialFolder(ESpecialFolder::MyVideo) << std::endl;
    std::cout << Environment::SpecialFolder(ESpecialFolder::LocalAppData) << std::endl;
    std::cout << Environment::SpecialFolder(ESpecialFolder::ProgramsFiles) << std::endl;
    std::cout << Environment::SpecialFolder(ESpecialFolder::MyPictures) << std::endl;
    std::cout << Environment::SpecialFolder(ESpecialFolder::Profile) << std::endl;
    std::cout << Environment::SpecialFolder(ESpecialFolder::ProgramFilesx86) << std::endl;*/
}