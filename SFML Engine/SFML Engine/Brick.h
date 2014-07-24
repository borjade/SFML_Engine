#pragma once
#include "gameobject.h"
class CBrick :
	public CGameObject
	{
	public:
		CBrick(void);
		~CBrick(void);

		void Update(float elapsedTime);

	};

