#pragma once
#include <SFML/Window.hpp>
#include "Renderer.h"

#include <list>
enum GLOBAL_ENUM
		{
			Nothing,
			Exit,
			Play,
			ExitToMain,
			Debug
		};

using namespace std;
using namespace sf;
class IMenu_Abstract
	{
	public:

		

		struct MenuButton 
			{
				Sprite buttonNormal;
				Sprite buttonHover;

				GLOBAL_ENUM action;
			};

		IMenu_Abstract(void) {};
		virtual ~IMenu_Abstract(void) {};
		virtual GLOBAL_ENUM show(CRenderer & renderer) = 0; 
	protected:
		virtual GLOBAL_ENUM GetMenuResponse(CRenderer & renderer)= 0;
		virtual GLOBAL_ENUM HandleClick(int x, int y) = 0;

		

		list<MenuButton> items;
	};

