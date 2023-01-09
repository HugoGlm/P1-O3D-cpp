#pragma once
#include "../GameObject/GameObject.h"
#include "../../Event/Delegate/Delegate.h"

#define BIRD_SCALE 0.15f
#define GRAVITY 0.5f
#define BIRD_SPEED_GRAVITY 350
#define BIRD_JUMP_FORCE 40

class FB_Bird : public GameObject
{
#pragma region f/p
private:
	bool isDead = false;
	sf::Clock lastjumpTimer = sf::Clock();
	sf::Sprite* sprite = nullptr;
	sf::Texture* texture = nullptr;
public:
	Delegate<void> OnDie = nullptr;
#pragma endregion
#pragma region constructor
public:
	FB_Bird();
	virtual ~FB_Bird() override;
#pragma endregion
#pragma region override
public:
	virtual void OnUpdate() override;
	virtual void OnCollisionEnter(GameObject* _other);
	virtual sf::FloatRect GetGlobalBounds() const override;
	virtual sf::Vector2f Position() const override;
#pragma endregion

};

