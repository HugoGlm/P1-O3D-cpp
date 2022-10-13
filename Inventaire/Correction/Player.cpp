#include "Player.h"
#include "CInventory.h"

#pragma region constructor / destructor
Player::Player(const std::string& _name, const float _maxLife, const float _maxMana)
	: Entity(_name, _maxLife, _maxMana)
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
CInventory* Player::GetInventory() const
{
	return inventory;
}
#pragma endregion
#pragma region methods

#pragma endregion