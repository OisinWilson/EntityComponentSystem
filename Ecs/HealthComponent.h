#pragma once

// @Author: Oisin Wilson
// @Num: C00213826

#include "Component.h"

class HealthComponent : public Component
{
public:
	HealthComponent() : Component(ComponentType::HEALTH), m_health(100) {}

	int getHealth() { return m_health; }
	void setHealth(int t_health) { this->m_health = t_health; }

private:
	int m_health;
};