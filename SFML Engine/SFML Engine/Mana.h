#pragma once
#include "gameobject.h"
class CMana :
	public CGameObject
	{
	public:
		CMana(void);
		~CMana(void);

		void Update(float elapsedTime);
	};

