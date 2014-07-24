#include "DefeatMenu.h"


DefeatMenu::DefeatMenu(void)
	{
	}


DefeatMenu::~DefeatMenu(void)
	{
	}

GLOBAL_ENUM DefeatMenu::show(CRenderer& renderer)
	{
		PlayButton.buttonNormal = Sprite(*renderer.getTextureManager().getTex("menu_play_again.png"));
		PlayButton.buttonNormal.setPosition(350,300);

		PlayButton.action = Play;
	    items.push_back(PlayButton);

		ExitBtn.buttonNormal = Sprite(*renderer.getTextureManager().getTex("menu_exit.png"));
		ExitBtn.buttonNormal.setPosition(350,500);

		ExitBtn.action = Exit;
		items.push_back(ExitBtn);

		ToMenu.buttonNormal = Sprite(*renderer.getTextureManager().getTex("menu_ToMain.png"));
		ToMenu.buttonNormal.setPosition(350,400);

		ToMenu.action = ExitToMain;
		items.push_back(ToMenu);

		Sprite sf (*renderer.getTextureManager().getTex("defeat.png"));

		renderer.getWindow()->clear();
		renderer.getWindow()->draw(sf);
		renderer.getWindow()->draw(PlayButton.buttonNormal);
		renderer.getWindow()->draw(ToMenu.buttonNormal);
		renderer.getWindow()->draw(ExitBtn.buttonNormal);
		renderer.getWindow()->display();

		return GetMenuResponse(renderer);

		
	}

GLOBAL_ENUM DefeatMenu::GetMenuResponse(CRenderer& renderer)
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

GLOBAL_ENUM DefeatMenu::HandleClick(int x, int y)
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