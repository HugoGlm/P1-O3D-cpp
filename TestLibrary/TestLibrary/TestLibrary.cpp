#include <iostream>
#include <FString.h>
#include <Object.h>
#include <Integer.h>
#include <Environment.h>
#include <Process.h>
#include <Console.h>
#include <DateTime.h>
#include <BoxFile.h>
#include <iostream>
#include <Windows.h> // pour la box
#include <iomanip>

using namespace Core::PrimitiveType;
using namespace Core::IO;
using namespace Core;

int ShowMessageBox()
{
    int msgBoxID = MessageBox(
        NULL,
        L"Alors vous allez bien ?",
        L"Les P1 vous allez bien ?",
        MB_ICONQUESTION | MB_YESNO // MB_ICONMASK = pas de logo
    );
    return msgBoxID;
}

template<typename Base, typename Derived>
static bool InstanceOf(const Derived*)
{
    return std::is_same<Base, Derived>::value;
}

#define instanceof(a, b) InstanceOf<a>(b)

int main()
{
    /*object o = new Object();
    DateTime* time = new DateTime(0, 0, 0);
    if (instanceof(Object, o))
    {
        std::cout << "o is object" << std::endl;
    }

    if (instanceof(Object, time))
    {
        std::cout << "time is object" << std::endl;
    }

    if (instanceof(DateTime, time))
    {
        std::cout << "time is DateTime" << std::endl;
    }*/

    //ShowMessageBox();

    /*BoxFile box = BoxFile("Gabriel path pick");
    box.open();
    LOG(box.Result());*/

    /*DateTime date = DateTime(17, 11, 2022);
    LOG(*date.DayOfWeek());
    LOGWARNING(*date.DayOfWeek());
    LOGERROR(*date.DayOfWeek());*/

    //Console::WriteLine(FString("Hello World"));

    /*const FString _path = "C:\\Users\\GUIL2804\\AppData\\Local\\Programs\\Opera GX\\launcher.exe";
    Core::Diagnostics::Process::Start(_path, "https://www.youtube.com");*/

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