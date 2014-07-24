#include "Paddle.h"


CPaddle::CPaddle(void): max_velocity(1000.0f)
	{
		controller = XBOXController(1);
		x = 300.0f;
		no = 0;
		no1 = 0;
		no2 = 0;
		ability1Cooldown = 0;
		ability2Cooldown = 0;
		manaCooldown = 0;
		gameTime = 0;
	}


CPaddle::~CPaddle(void)
	{
	}

void CPaddle::Update(float elapsedTime)
	{

		ability1Cooldown += elapsedTime;
		ability2Cooldown += elapsedTime;
		manaCooldown += elapsedTime;
		gameTime += elapsedTime;
		if(gameTime < 3.0f)
			{
				this->SetPosition(400.0f,550.0f);
			}

		if(controller.GetState().Gamepad.sThumbLX >  6553 )
			{
				velocity+= controller.thumbStick()/ 20.0f;
			}
		else if(controller.GetState().Gamepad.sThumbLX < -6553)
			{
				velocity-=controller.thumbStick()/ 20.0f;
			}

		if(controller.GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X)
			{
			if(ability1Cooldown > 4.0f)
				{
					if(GO->Get("manaNo")->getHP() >= 40)
					{
						stringstream bricky;
						bricky << "upwards" << no;
						CAbility * ab = new CAbility(bricky.str());
						ab->AttachTexture(ability1);
						ab->setDir(false,false);
						ab->SetPosition(GetPosition().x,GetPosition().y-50.0f);
						ab->setGO(GO);
						GO->Add(bricky.str(),ab);
						sprite->Add(bricky.str(),ab->GetSprite());
						no += 1;
						if(GO->debug == false)
							{
								GO->Get("manaNo")->minusHP(50);
							}
						ability1Cooldown = 0;
						soundProvider->PlaySound("resourcer/Sounds/photon.wav");
					}
				}
			}
		if(controller.GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)
			{
			if(ability2Cooldown > 1.5f)
				{
				if(GO->Get("manaNo")->getHP() > 9)
					{
						stringstream laser;
						laser << "sidewaysA" << no1;
						CAbility * ab = new CAbility(laser.str());
						ab->AttachTexture(ability2);
						ab->setHitpoints(2);
						ab->setDir(true,false);
						ab->SetPosition(GetPosition().x,GetPosition().y);
						ab->setGO(GO);
						GO->Add(laser.str(),ab);
						sprite->Add(laser.str(),ab->GetSprite());
						no1 += 1;

						stringstream laserLeft;
						laserLeft << "sidewaysB" << no2;
						CAbility * ac = new CAbility(laserLeft.str());
						ac->AttachTexture(ability2);
						ac->setHitpoints(2);
						ac->setDir(true,true);
						ac->SetPosition(GetPosition().x,GetPosition().y);
						ac->setGO(GO);
						GO->Add(laserLeft.str(),ac);
						sprite->Add(laserLeft.str(),ac->GetSprite());
						no2 += 1;
						if(GO->debug == false)
							{
								GO->Get("manaNo")->minusHP(20);
							}
						ability2Cooldown = 0;
						soundProvider->PlaySound("resourcer/Sounds/kaboom.wav");
					}
				}
			}

		
		if(velocity > max_velocity)
			{
				velocity = max_velocity;
			}
		if(velocity < -max_velocity)
			{
				velocity = -max_velocity;
			}


		if(this->GetPosition().x < 0.0f)
		  {
			this->SetPosition(0.0f,550.0f);
			controller.Vibrate(32767, 0);
		  }

		if(this->GetPosition().x > 735.0f)
		  {
			this->SetPosition(735.0f,550.0f);
			controller.Vibrate(0, 32767);
		  }

		GetSprite()->move(velocity * elapsedTime,0);
		velocity = 0;
		controller.Vibrate(0, 0);
		if(manaCooldown > 5.0f)
		{
			GO->Get("manaNo")->addHP(2);
			manaCooldown = 0;
		}
	}

float CPaddle::getVelocity()
	{
		return velocity;
	}