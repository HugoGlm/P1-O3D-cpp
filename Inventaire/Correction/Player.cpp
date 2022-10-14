#include "Player.h"
#include "CInventory.h"
#include "Utils.h"
#include "Vector2.h"

#pragma region constructor / destructor
Player::Player(const std::string& _name, Map* _currentMap, Vector2* _position, const float _maxLife, const float _maxMana)
	: Entity(_name, _currentMap, _position, _maxLife, _maxMana)
{
	inventory = new CInventory(_name + " Inventory", this);
}
Player::Player(const Player& _copy) : Entity(_copy)
{
	inventory = _copy.inventory;
}
Player::~Player()
{
	delete inventory;
}
#pragma endregion
#pragma region methods
CInventory* Player::GetInventory() const
{
	return inventory;
}
void Player::Move()
{
	char _input = Utils::UserChoice<char>("Move with z, q, s, d : ");
	Vector2 _position = *Position();
	switch (std::tolower(_input))
	{
	case 'z':
		_position.Set(Vector2(_position.X(), _position.Y() - 1));
		break;
	case 'q':
		_position.Set(Vector2(_position.X() - 1, _position.Y()));
		break;
	case 's':
		_position.Set(Vector2(_position.X(), _position.Y() + 1));
		break;
	case 'd':
		_position.Set(Vector2(_position.X() + 1, _position.Y()));
		break;
	default:
		break;
	}
}
#pragma endregion