#include <iostream>
#include <FString.h>
#include <Object.h>
#include <Integer.h>
#include <Environment.h>
#include <Process.h>
#include <Console.h>
#include <DateTime.h>
#include <BindingFlags.h>
#include <FieldInfo.h>
#include <BoxFile.h>
#include <MethodInfo.h>
#include <ParameterInfo.h>
#include <Enum.h>
#include <Window.h>
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

//class A : public Object
//{
//public:
//    void Test(const FString& msg, const FString& a)
//    {
//        LOG(msg);
//        LOG(a);
//    }
//    REGISTER_METHOD(Test, &A::Test, this, std::vector<ParameterInfo>({ ParameterInfo("msg", "FString", 0), ParameterInfo("a", "FString", 1) }));
//};

ENUM(Test, Giusy = 1, Gabriel = 15, Hugo);
ENUM(Test1, Aymeric = 1, Thibaud = 2, Romain, Benoit = 5, Pierre);

int main()
{
    std::cout << *Test::Giusy << std::endl;
    for (Test1 t : Test1Support::Value())
    {
        std::cout << *t << std::endl;
    }

   /* A a;
    MethodInfo<void, const FString&>* method = a.GetMethod<void, const FString&>("Test");
    if (method == nullptr)
    {
        std::cout << "Function is null !";
        return -4;
    }
    for (ParameterInfo _params : method->Parameters())
    {
        std::cout << "Type: " << _params.TypeName() << ", param name: " << _params.Name() << " position: " << _params.Position();
    }*/

    /*Window window = Window(PrimitiveType::FString("Test"), 900, 800);
    window.Open();*/

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