#pragma once
#include "ServiceLocator.h"
#include "menu_abstract.h"
class DefeatMenu :
	public IMenu_Abstract
	{
	public:
		DefeatMenu(void);
		~DefeatMenu(void);

		GLOBAL_ENUM show(CRenderer & renderer);

	protected:

		GLOBAL_ENUM GetMenuResponse(CRenderer & renderer);
		GLOBAL_ENUM HandleClick(int x, int y);

		MenuButton PlayButton;
		MenuButton ToMenu;
		MenuButton ExitBtn;
	};

