#pragma once

// @Author: Oisin Wilson
// @Num: C00213826

#include"Entity.h"
#include <vector>
#include <iostream>
#include "HealthComponent.h"

class HealthSystem
{
public:
	void addEntity(Entity* t_e) {
		m_entities.push_back(t_e);
		std::vector<Component*> healthCheck = t_e->getComponents();

		for (int i = 0; i < healthCheck.size(); i++)
		{
			if (healthCheck[i]->getType() == Component::ComponentType::HEALTH)
			{
				m_healthComp.push_back(static_cast<HealthComponent*>(healthCheck[i]));
			}
		}


		for (int i = 0; i < m_entities.size(); i++)
		{
			switch (m_entities[i]->getId())
			{
			case 0:
				m_healthComp[i]->setHealth(200);	//player
				break;
			case 1:
				m_healthComp[i]->setHealth(100);	//alien
				break;
			case 2:
				m_healthComp[i]->setHealth(50);		//dog
				break;
			case 3:
				m_healthComp[i]->setHealth(50);		//cat
				break;
			default:
				std::cout << "Error - addEntity - HealthSystem" << std::endl;
				break;
			}
		}
	}
	
	void update() {
		for (int i = 0; i < m_entities.size(); i++)
		{
			std::cout << "ID : " << m_entities[i]->getId() << "  Health : " << m_healthComp[i]->getHealth() << std::endl;
		}
	}

private:
	std::vector<Entity*> m_entities;
	std::vector<HealthComponent*> m_healthComp;
};