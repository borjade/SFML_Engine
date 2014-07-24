#include "MainMenu.h"


CMainMenu::CMainMenu(void) : IMenu_Abstract()
	{
	}


CMainMenu::~CMainMenu(void)
	{
	}

GLOBAL_ENUM CMainMenu::show(CRenderer& renderer)
	{
		PlayButton.buttonNormal = Sprite(*renderer.getTextureManager().getTex("menu_play.png"));
		PlayButton.buttonNormal.setPosition(350,300);

		PlayButton.action = Play;
	    items.push_back(PlayButton);

		ExitBtn.buttonNormal = Sprite(*renderer.getTextureManager().getTex("menu_exit.png"));
		ExitBtn.buttonNormal.setPosition(350,400);

		ExitBtn.action = Exit;
		items.push_back(ExitBtn);

		debugBtn.buttonNormal = Sprite(*renderer.getTextureManager().getTex("debug.png"));
		debugBtn.buttonNormal.setPosition(10,10);
		debugBtn.action = Debug;
		items.push_back(debugBtn);

		Sprite sf (*renderer.getTextureManager().getTex("gamebkg.png"));

		renderer.getWindow()->clear();
		renderer.getWindow()->draw(sf);
		renderer.getWindow()->draw(debugBtn.buttonNormal);
		renderer.getWindow()->draw(PlayButton.buttonNormal);
		renderer.getWindow()->draw(ExitBtn.buttonNormal);
		renderer.getWindow()->display();

		return GetMenuResponse(renderer);

		
	}

GLOBAL_ENUM CMainMenu::GetMenuResponse(CRenderer& renderer)
	{
		Event menuEvent;

		while(true)
			{
				while(renderer.getWindow()->pollEvent(menuEvent))
				{
					if(menuEvent.type == Event::MouseButtonPressed)
						{
							return HandleClick(menuEvent.mouseButton.x,menuEvent.mouseButton.y);
							

						}
					if(menuEvent.type == Event::Closed)
						{
							return Exit;
						}
				}
			}
	}

GLOBAL_ENUM CMainMenu::HandleClick(int x, int y)
	{
		list<MenuButton>::iterator it;

		for ( it = items.begin(); it != items.end(); it++)
			{
				FloatRect menuItem = (*it).buttonNormal.getGlobalBounds();

				bool test = menuItem.contains(x,y); 

				if(test == true )
					{
						
						return (*it).action;
					}
			}

		return Nothing;
	}

bool CMainMenu::HandleHover(int x, int y)
	{
		list<MenuButton>::iterator it;

		for ( it = items.begin(); it != items.end(); it++)
			{
				FloatRect menuItem = (*it).buttonNormal.getGlobalBounds();

				if(menuItem.contains(x,y))
					{
						return true;
					}	
			}
		return false;
	}