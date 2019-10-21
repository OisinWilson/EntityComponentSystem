#pragma once

// @Author: Oisin Wilson
// @Num: C00213826

#include"Entity.h"
#include"PositionComponent.h"

class AiSystem
{
public:
	void addEntity(Entity* t_e)
	{
		m_entities.push_back(t_e);

		std::vector<Component*> AiCheck = t_e->getComponents();

		for (int i = 0; i < AiCheck.size(); i++)
		{
			if (AiCheck[i]->getType() == Component::ComponentType::POSITION)
			{
				m_AiComp.push_back(static_cast<PositionComponent*>(AiCheck[i]));
			}
		}
	}

	void update()
	{
		for (int i = 0; i < m_entities.size(); i++)
		{
			if (m_AiComp[i]->getPos().x + m_AiComp[i]->getPos().w / 2 > 800)
			{
				m_direction.x *= -1;
			}
			else if (m_AiComp[i]->getPos().x + m_AiComp[i]->getPos().w / 2 < 0)
			{
				m_direction.x *= -1;
			}
			m_AiComp[i]->move(m_direction);
		}
	}

private:
	std::vector<Entity*> m_entities;
	std::vector<PositionComponent*> m_AiComp;
	SDL_Rect m_direction{ 1,0,0,0 };
};