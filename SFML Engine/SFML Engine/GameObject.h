#pragma once
#include "SFML\Graphics.hpp"
#include "SFMLAudio.h"

using namespace sf;
class CGameObject
	{
	public:
		CGameObject(void);
		virtual ~CGameObject(void);

		virtual void AttachTexture(Texture* tex);

		virtual float getVelocity();

		inline virtual void setVelocity(float v)
			{
				velocity = v;
			}

		virtual void SetPosition(int x, int y);

		inline virtual Sprite* GetSprite()
			{
				return sprite;
			};

		virtual void Update(float elapsedTime);

		virtual Vector2f GetPosition() const;


		virtual  float GetWidth()
			{
				return sprite->getTexture()->getSize().x;
			};

		inline virtual  float GetHeight()
			{
				return sprite->getTexture()->getSize().y;
			};

		inline virtual FloatRect GetBoundingRect() const
			{
				return sprite->getGlobalBounds();
			}
		inline virtual void SetDead()
			{
				dead = true;	
			}
		inline virtual bool GetDead()
			{
				return dead;
			}

		inline virtual void setHitpoints(int hp)
			{
				hitPoints = hp;
			}

		inline virtual void minusHP(int hp)
			{
				hitPoints -= hp;
			}

		inline virtual int getHP()
			{
				return hitPoints;
			}

		inline virtual void addHP(int hp)
			{
				hitPoints +=hp;
			}

		inline virtual void setAudio(SFMLAudio * s)
			{
				soundProvider = s;
			}

	protected:
		Sprite* sprite;
		Texture* texture;

		SFMLAudio* soundProvider;

		float velocity;

		int hitPoints;

		bool dead;
		bool loaded;
	};

