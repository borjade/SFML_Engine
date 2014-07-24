#include "Engine.h"



CEngine::CEngine(void)
	{
		state = Uninitialized;
		GOMan = NULL;
	}

CEngine::~CEngine()
	{
		
	}

//Function containing main game loop
void CEngine::MainLoop()
	{
		float lastTime = 0;
		//While the window is indeed open
		while(!isExiting())
			{
				
				switch(state){
				case ShowingSplash:
					{
						ShowSplash();
						break;
					}
				case ShowingMenu:
					{
						ShowMenu();
						break;
					}
				case Playing:
					{
					ProcessInput();	
					//Process the input
						float currentTime = gameClock.restart().asSeconds();
						float fps = 1.0f / (currentTime);
						lastTime = currentTime;
						Update(currentTime,fps);
						
						//Update the state of the game
						renderer.RenderFrame();
						

						break;
					}
				case Lost:
					{
						nukeGOs();
						renderer.getSpriteMngr()->DeleteAll();
						ShowDefeat();
						break;
					}
				}
				//Lets render the results
			}
		Close_and_Clean(); //Kill all subsystems and clean after them
	}

//Basic Init function
bool CEngine::Init()
	{
		
	    //Lets initialise the renderer
		if(!renderer.Init())
			{
				//Something's gone wrong!
				return false;
			}
		else{
				soundProvider = new SFMLAudio();
				//CServiceLocator::RegisterServiceLocator(soundProvider);
				

				//It worked, lets get the GO manager up and running!!!
				initialiseGOs();

				ManaNo = new Text();
				ManaNo->setPosition(435.0f,565.0f);
				ManaNo->setCharacterSize(30);
				renderer.addText("manaNo",ManaNo);

				ScoreNo = new Text();
				ScoreNo->setPosition(125.0f,565.0f);
				ScoreNo->setCharacterSize(30);
				renderer.addText("scoreNo",ScoreNo);

				Mana = new Text();
				Mana->setString("Mana:");
				Mana->setPosition(350.0f,565.0f);
				Mana->setCharacterSize(30);
				renderer.addText("mana",Mana);

				Lives = new Text();
				Lives->setString("Lives:");
				Lives->setPosition(600.0f,565.0f);
				Lives->setCharacterSize(30);
				renderer.addText("lives",Lives);

				LivesNo = new Text();
				LivesNo->setPosition(700.0f,565.0f);
				LivesNo->setCharacterSize(30);
				renderer.addText("livesNo",LivesNo);

				FPS = new Text();
				FPS->setPosition(400,300);
				FPS->setCharacterSize(30);
				renderer.addText("FPS",FPS);

				Score = new Text();
				Score->setString("Score:");
				Score->setPosition(10.0f,565.0f);
				Score->setCharacterSize(30);
				renderer.addText("score",Score);
				state = ShowingSplash;
				return true;
				
			}
	}

void CEngine::initialiseGOs()
	{
				if(GOMan == NULL)
					{
				GOMan = new CGameObjManager();
				
				Sprite* bkg = new Sprite(*renderer.getTextureManager().getTex("bkg.png"));
				renderer.addSprite("abkg",bkg);

				player = new CPaddle();
				player->setAudio(soundProvider);

				player->AttachTexture(renderer.getTextureManager().getTex("paddle.png"));
				GOMan->Add("paddle",player);

				player->sendTexes(renderer.getTextureManager().getTex("photon.png"),renderer.getTextureManager().getTex("laser.png"));
				
				ball = new CBall();

				GOMan->Add("ball",ball);
				ball->AttachTexture(renderer.getTextureManager().getTex("ball.png"));
				ball->setAudio(soundProvider);

				scoreTracker = new CScore();
				scoreTracker->setHitpoints(0000);
				GOMan->Add("scoreNo",scoreTracker);

				livesTracker = new CLives();
				livesTracker->setHitpoints(3);
				GOMan->Add("livesNo",livesTracker);

				manaTracker = new CMana();
				manaTracker->setHitpoints(100);
				GOMan->Add("manaNo",manaTracker);

				ball->setGO(GOMan);
				ball->setVelocity(0.2f);
				ball->SetPosition(400.0f,300.0f);
				
				int count = 0;
				for(int y = 0; y < 10; y++)
					{
						for(int x = 0; x < 10; x++)
							{
								CBrick* brick = new CBrick();
								stringstream bricky;
								bricky << "brick" << count;
								GOMan->Add(bricky.str(),brick);
								if(y < 6)
									{
										brick->AttachTexture(renderer.getTextureManager().getTex("brick_yellow.png"));
										brick->setHitpoints(1);
									}
								else if (y <9)
									{
										brick->AttachTexture(renderer.getTextureManager().getTex("brick_green.png"));
										brick->setHitpoints(2);
									}
								else
									{
										brick->AttachTexture(renderer.getTextureManager().getTex("brick_red.png"));
										brick->setHitpoints(3);
									}
								renderer.addSprite(bricky.str(),brick->GetSprite());
								brick->SetPosition(15.0f + ((brick->GetSprite()->getLocalBounds().width + 50.0f) * x),y * -20);
								count++;
							}
					}
				
				renderer.addSprite("paddle",player->GetSprite());
				renderer.addSprite("ball",ball->GetSprite());
				player->SetGO(GOMan);
				player->SetSpriteMan(renderer.getSpriteMngr());
				
					}
	}

void CEngine::nukeGOs()
	{
		if(GOMan != NULL)
			{
				delete GOMan;
				GOMan = NULL;
			}
	}
void CEngine::ProcessInput()
	{
		Event evnt;
		//Keep polling for events
		while(renderer.getWindow()->pollEvent(evnt))
			{
				//If the event is of type Closed, then operation "Clean-after-your-mess" is a go
				if(evnt.type == Event::Closed)
					{
						state = Exiting;
					}
			}
	}

void CEngine::Close_and_Clean()
	{
		renderer.Kill(); //Bang
		nukeGOs();
	}

void CEngine::Update(float time,float fps)
	{
		//Lets update the game
		GOMan->UpdateAll(time);
		GOMan->ClearDead();
		renderer.getSpriteMngr()->addToDelete(GOMan->CleanUpNames());
		renderer.getSpriteMngr()->ClearDead();
		
		if(GOMan->debug == false)
			{
				stringstream mana;
				mana << GOMan->Get("manaNo")->getHP();
				ManaNo->setString(mana.str());

				FPS->setString("");

				stringstream lives;
				lives << GOMan->Get("livesNo")->getHP();
				LivesNo->setString(lives.str());
			}
		else
			{
				ManaNo->setString("dbg");
				LivesNo->setString("dbg");

				stringstream f;
				f << fps;
				FPS->setString(f.str());

			}
		stringstream score;
		score << GOMan->Get("scoreNo")->getHP();
		ScoreNo->setString(score.str());
		
		
		if(GOMan->Get("livesNo")->getHP() == 0)
			{
				state = Lost;
			}
	}

//Turn the key and start the engine
void CEngine::Go()
	{
		//if we can't initialise something's definitely wrong!!
		if(!Init())
			{
				throw "Could not Initialize engine!";
			}
		//It's all ok, so lets get into the main loop
		MainLoop();
	}