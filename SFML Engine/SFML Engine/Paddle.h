#pragma once
#include "GameObject.h"
#include "SpriteManager.h"
//#include "GameObjManager.h"
#include "XBOXController.h"
#include "Ability.h"
#include <sstream>
class CPaddle :
	public CGameObject
	{
	public:
		CPaddle(void);
		~CPaddle(void);

		void Update(float elapsedTime);

		float getVelocity();

		inline void SetGO(CGameObjManager * g)
			{
				 GO = g;
			}

		inline void sendTexes(Texture* a, Texture* b)
			{
				ability1 = a;
				ability2 = b;
			}

		inline void SetSpriteMan(CSpriteManager * sMan)
			{
				 sprite = sMan;
			}

	private:
		CSpriteManager * sprite;
		CGameObjManager * GO;

		float manaCooldown;
		float ability1Cooldown;
		float ability2Cooldown;

		Texture* ability1;
		Texture* ability2;
		int no;

		int no1;
		int no2;

		float gameTime;
		//float velocity;
		float max_velocity;
		float x;
		XBOXController controller;
	};

