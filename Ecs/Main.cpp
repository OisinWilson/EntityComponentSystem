
// @Author: Oisin Wilson
// @Num: C00213826


#include<iostream>
#include<string>

#include <SDL.h>
#include <SDL_image.h>

#include "Entity.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "InputComponent.h"
#include "HealthSystem.h"
#include "RenderSystem.h"
#include "AiSystem.h"
#include "ControlSystem.h"



int main(int argc, char**argv)
{
	SDL_Window* m_window = SDL_CreateWindow("ECS", 300, 100, 800, 600, SDL_WINDOW_INPUT_FOCUS);
	SDL_Renderer * m_renderer = SDL_CreateRenderer(m_window, -1, 0);


	Entity* player = new Entity(0);
	Entity* Alien = new Entity(1);
	Entity* Dog = new Entity(2);
	Entity* Cat = new Entity(3);

	player->addComponent(new HealthComponent());
	player->addComponent(new PositionComponent(SDL_Rect{100,100,100,100}));
	
	Alien->addComponent(new HealthComponent());
	Alien->addComponent(new PositionComponent(SDL_Rect{ 200,200,100,100 }));

	Dog->addComponent(new HealthComponent());
	Dog->addComponent(new PositionComponent(SDL_Rect{ 300,300,100,100 }));

	Cat->addComponent(new HealthComponent());



	HealthSystem hs; RenderSystem rs; AiSystem as; ControlSystem cs;

	hs.addEntity(player);
	rs.addEntity(player);
	cs.addEntity(player);

	hs.addEntity(Alien);
	rs.addEntity(Alien);
	as.addEntity(Alien);

	hs.addEntity(Dog);
	rs.addEntity(Dog);

	hs.addEntity(Cat);


	while (true)
	{
		hs.update();
		as.update();
		cs.update();
		rs.update(m_renderer);
	}

	return 0;
}