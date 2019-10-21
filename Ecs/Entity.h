#pragma once

// @Author: Oisin Wilson
// @Num: C00213826

#include<vector>
#include"Component.h"

class Entity
{
public:
	Entity(int t_idNum) : m_id(t_idNum) {};
	void addComponent(Component* t_c) {m_components.push_back(t_c);}
	std::vector<Component*> getComponents() { return m_components; }
	int getId() { return m_id; }

private:
	std::vector<Component*> m_components;
	int m_id;
};