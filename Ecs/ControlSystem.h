#pragma once

// @Author: Oisin Wilson
// @Num: C00213826

#include"Entity.h"
#include"InputComponent.h"
#include"PositionComponent.h"

class ControlSystem
{
public:
	void addEntity(Entity* t_e)
	{
		m_entities.push_back(t_e);

		std::vector<Component*> InputCheck = t_e->getComponents();

		for (int i = 0; i < InputCheck.size(); i++)
		{
			if (InputCheck[i]->getType() == Component::ComponentType::POSITION )
			{
				m_posComp.push_back(static_cast<PositionComponent*>(InputCheck[i]));
			}
		}
	}

	void update()
	{
		for (int i = 0; i < m_entities.size(); i++)
		{
			SDL_Rect m_direction{ 0,0,0,0 };


				SDL_Event event;

				while (SDL_PollEvent(&event))
				{
					switch (event.type)
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym)
					{
					case SDLK_UP:
						m_direction.y -= 5;
						break;
					case SDLK_DOWN:
						m_direction.y += 5;
						break;
					case SDLK_LEFT:
						m_direction.x -= 5;
						break;
					case SDLK_RIGHT:
						m_direction.x += 5;
						break;
					default:
						break;
					}
				}
				m_posComp[i]->move(m_direction);
		}
	}

private:
	std::vector<Entity*> m_entities;
	//std::vector<InputComponent*> m_inputComp;
	std::vector<PositionComponent*> m_posComp;
	
};