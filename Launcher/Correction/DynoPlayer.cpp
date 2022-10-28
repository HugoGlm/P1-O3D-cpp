#include "DynoPlayer.h"
#include "Utils.h"

int DynoPlayer::Position() const
{
    return position;
}
bool DynoPlayer::IsDead() const
{
    return isDead;
}
void DynoPlayer::SetPosition(const int _position)
{
    position = _position;
}
void DynoPlayer::SetDead(const bool _status)
{
    isDead = _status;
}
void DynoPlayer::Jump()
{
    if (position > 3)
        position -= 3;
}
bool DynoPlayer::IsCollide(const DynoPipe* _pipe)
{
    return false;
}
void DynoPlayer::Draw()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            Utils::SetCursorPosition(j + 2, i + position);
            std::cout << Dyno[i][j];
        }
    }
}
void DynoPlayer::Erase()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            Utils::SetCursorPosition(j + 2, i + position);
            std::cout << " ";
        }
    }
}
void DynoPlayer::Update()
{
}
