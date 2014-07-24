#include "Splash.h"
#include <Windows.h>


CSplash::CSplash(void)
	{
	}


CSplash::~CSplash(void)
	{
	}

GLOBAL_ENUM CSplash::Show(sf::RenderWindow& rw)
	{
		sf::Texture image;

		if(image.loadFromFile("resources/Images/splash.png") != true)
			{
				char* e = new char('c');
				MessageBox(NULL,NULL,NULL, MB_OK | MB_ICONERROR);
				delete e;

				return Nothing;
			}

		sf::Sprite sprite(image);

		rw.draw(sprite);
		rw.display();

		sf::Event evnt;
		while(true)
			{
				while(rw.pollEvent(evnt))
					{
							if(evnt.type == sf::Event::EventType::KeyPressed 
							  || evnt.type == sf::Event::EventType::MouseButtonPressed )
							{
								rw.clear();
								return ExitToMain;
							}
							if(evnt.type == sf::Event::EventType::Closed)
								{
								   rw.clear();
									return Exit;
								}
					}
			}

	}
