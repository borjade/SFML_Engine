#include "Ball.h"


CBall::CBall(void) :  ballSpeed(7.0f), PI(3.14159265f)
	{
		this->SetPosition(400,300);
		srand (time(NULL));
		ballAngle = ((float)(rand()%360 + 1)) * (180 / PI);
		gameTime = 0;
	}


CBall::CBall(CGameObjManager * go): xVel(0.15f), yVel(0.35f)
	{	
		GO = go;
	}


CBall::~CBall(void)
	{
	}

void CBall::Update(float elapsedTime)
	{	
		gameTime += elapsedTime;

		if(gameTime < 3.0f)
			{
				return;
			}

		if(this->GetPosition().y >= 600)
			{
				if(GO->Get("livesNo")->getHP() >0)
					{
						if(GO->debug == false)
							{
								GO->Get("livesNo")->minusHP(1);
							}
						this->SetPosition(400,500);
						srand (time(NULL));
						ballAngle = ((float)(rand()%360 + 1)) * (180 / PI);	
					}
			}


		
		
		if(this->GetPosition().y <= 0 )
			{
				ballAngle =  -ballAngle;
			}

		if(this->GetPosition().x <= 0 || this->GetPosition().x >= 800 )
			{
				ballAngle = PI - ballAngle;
			}
		if(this->GetBoundingRect().intersects(GO->Get("paddle")->GetBoundingRect()))
			{
				ballAngle =  - ballAngle + (rand() % 30) * PI / 180;
			}

		int count = 0;
				for(int y = 0; y < 10; y++)
					{
						for(int x = 0; x < 10; x++)
							{
								stringstream bricky;
								bricky << "brick" << count;
								if(GO->Get(bricky.str()) != NULL)
								{
									
									if(this->GetBoundingRect().intersects(GO->Get(bricky.str())->GetBoundingRect()))
									{
										ballAngle =  - ballAngle + (rand() % 30) * PI / 180;
											GO->Get(bricky.str())->minusHP(1);
											if(GO->Get(bricky.str())->getHP() <=0)
												{
													GO->addToDelete(bricky.str());
													GO->Get("manaNo")->addHP(5);
													GO->Get("scoreNo")->addHP(10);

												}
											
									}
								}
								count++;
							}
					}
		float moveByX = cos(ballAngle) * ballSpeed;
		float moveByY = sin(ballAngle) * ballSpeed;

		GetSprite()->move(moveByX, moveByY);
	}



float CBall::LinearVelocityX(float& _angle)
	{
			_angle -= 90;
			if(_angle < 0) 
				{
					_angle = 360 +_angle;
				}
			return (float)std::cos(_angle *  (3.1415926 / 180.0f ));
	}

float CBall::LinearVelocityY(float& _angle)
	{
			_angle -= 90;
			if(_angle < 0) 
				{
					_angle = 360 + _angle;
				}
			return (float)std::sin(_angle *  (3.1415926 / 180.0f ));
	}