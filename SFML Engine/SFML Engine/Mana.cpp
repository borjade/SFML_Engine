#include "Mana.h"


CMana::CMana(void)
	{
		loaded = true;
	}


CMana::~CMana(void)
	{
	}

void CMana::Update(float elapsedTime)
	{
		if(hitPoints > 99)
			{
				hitPoints = 99;
			}
		else if(hitPoints < 0)
			{
				hitPoints = 0;
			}
	}