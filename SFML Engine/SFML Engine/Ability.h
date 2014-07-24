#pragma once
#include "GameObjManager.h"
#include "GameObject.h"
#include <sstream>
#include <string>
class CAbility : public CGameObject
	{
	public:
		CAbility(void);
		CAbility(std::string n);
		~CAbility(void);

		void Update(float elapsedTime);

		void setGO(CGameObjManager* g)
			{
				GO = g;
			};

		void setDir(bool h, bool l)
			{
				horizontal = h;
				left = l;
			}

	private:
		std::string name;
		CGameObjManager* GO;
		bool horizontal;
		bool left;
	};

