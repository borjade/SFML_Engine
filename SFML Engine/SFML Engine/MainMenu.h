#pragma once
#include "Menu_Abstract.h"
#include "ServiceLocator.h"
class CMainMenu : public IMenu_Abstract
	{
	public:
		CMainMenu(void);
		~CMainMenu(void);

		GLOBAL_ENUM show(CRenderer & renderer);

	protected:
		GLOBAL_ENUM GetMenuResponse(CRenderer & renderer);
		GLOBAL_ENUM HandleClick(int x, int y);

		bool HandleHover(int x, int y);

		MenuButton PlayButton;
		MenuButton ExitBtn;
		MenuButton debugBtn;

	};

