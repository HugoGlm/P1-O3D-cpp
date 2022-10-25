#include <iostream>
#include "Launcher.h"
#include "LauncherItem.h"
#include "FlappyBirdGame.h"
#include "MorpionGame.h"
#include <Windows.h>

int main()
{
    SetConsoleTitle(L"Launcher");
    Launcher _launcher = Launcher({
        new LauncherItem(new MorpionGame()),
        new LauncherItem(new FlappyBirdGame()),
        });
    _launcher.Open();
}