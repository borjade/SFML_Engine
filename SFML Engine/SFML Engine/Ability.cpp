#include "Ability.h"


CAbility::CAbility(void)
	{
		hitPoints = 4;
	}


CAbility::CAbility(std::string n)
	{
		hitPoints = 4;
		name = n;
	}


CAbility::~CAbility(void)
	{
	}

void CAbility::Update(float elapsedTime)
	{
		int count = 0;
				for(int y = 0; y < 10; y++)
					{
						for(int x = 0; x < 10; x++)
							{
								if(hitPoints > 0)
									{
										stringstream bricky;
										bricky << "brick" << count;
										if(GO->Get(bricky.str()) != NULL)
										{
											if(this->GetBoundingRect().intersects(GO->Get(bricky.str())->GetBoundingRect()))
											{
												minusHP(1);
												GO->addToDelete(bricky.str());
												GO->Get("scoreNo")->addHP(5);
												if(hitPoints <= 0)
												{
													GO->addToDelete(name);
												}
											}
										}

										count++;

									}
							}
					}
		if(GetPosition().x < 0.0f)
			{
				GO->addToDelete(name);
			}
		if(GetPosition().x > 800.0f)
			{
				GO->addToDelete(name);
			}

		if(horizontal == false)
			{
				GetSprite()->move(0,-600.0f*elapsedTime);
			}
		else
			{
				if(left == false)
					{
						GetSprite()->move(600.0f*elapsedTime,0);
					}
				else
					{
						GetSprite()->move(-600.0f*elapsedTime,0);
					}
			}
	}