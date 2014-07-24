#pragma once
#include "GameObjManager.h"
#include "Paddle.h"
#include <SFML\Config.hpp>
#include <sstream>
class CBall : public CGameObject
	{
	public:
		CBall(void);
		CBall(CGameObjManager * go);
		~CBall(void);
		void Update(float elapsedTime);

		float LinearVelocityX(float& _angle);
		float LinearVelocityY(float& _angle);

		void setGO(CGameObjManager* g)
			{
				GO = g;
			};

		void multiplier(float multi);

		int ballCount;

	private:
		bool init;
		//float velocity;
		float xVel;
		float yVel;

		float PI;

		float ballSpeed;
		float gameTime;
		float ballAngle;
		float collisionTime;

		CGameObjManager* GO;
	};

