#include "GameObject.h"


CGameObject::CGameObject(void)
	{
		loaded = false;
		dead = false;
		sprite = new Sprite();
	}


CGameObject::~CGameObject(void)
	{
	}

void CGameObject::AttachTexture(Texture* tex)
	{
		if (tex != NULL)
			{
				texture = tex;

				sprite->setTexture(*texture);

				loaded = true;

			}
		else
			{
				loaded = false;
				texture = NULL;
			}
	}

void CGameObject::SetPosition(int x, int y)
	{
		if(loaded == true)
			{
				sprite->setPosition(x,y);
			}
	}

void CGameObject::Update(float elapsedTime)
	{
		
	}

Vector2f CGameObject::GetPosition() const
	{
		if(loaded == true)
			{
				return sprite->getPosition();
			}
		return Vector2f();
	}

float CGameObject::getVelocity()
	{
		return velocity;
	}