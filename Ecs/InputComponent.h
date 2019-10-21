#pragma once

// @Author: Oisin Wilson
// @Num: C00213826

#include "Component.h"

class InputComponent : public Component
{
public:
	InputComponent() : Component(ComponentType::INPUT) {}
	void setInput(int t_i) { this->m_input = t_i; }
	int getInput() { return m_input; }

private:
	int m_input;
};