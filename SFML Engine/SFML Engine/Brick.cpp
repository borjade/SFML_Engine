#include "Brick.h"


CBrick::CBrick(void)
	{
	}


CBrick::~CBrick(void)
	{
	}

void CBrick::Update(float elapsedTime)
	{
		GetSprite()->move(0,3.0 * elapsedTime);

		if(this->GetPosition().y>=600)
			{
				this->SetPosition(this->GetPosition().x,-5);
			}
	}