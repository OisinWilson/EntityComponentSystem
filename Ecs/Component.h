#pragma once

// @Author: Oisin Wilson
// @Num: C00213826

#include<SDL.h>

class Component
{
public:

	enum class ComponentType {
		HEALTH,
		POSITION,
		INPUT
	};

	Component(ComponentType t_type) : m_compType(t_type) {};
	
	ComponentType getType() { return m_compType; }
	void setType(ComponentType t_type) { m_compType = t_type; }

private:

	ComponentType m_compType;
};