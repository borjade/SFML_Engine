#pragma once
#include "Renderer.h"
#include "Splash.h"
#include "MainMenu.h"
#include "SFMLAudio.h"
#include "ServiceLocator.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include "Mana.h"
#include "Score.h"
#include "Lives.h"
#include <sstream>
#include "DefeatMenu.h"



class CEngine
	{
	private:

		SFMLAudio* soundProvider;

		bool debugMode;
		//SFML Renderer 
	    CRenderer renderer;

		CLives* livesTracker;

		CPaddle* player;

		CScore* scoreTracker;

		CGameObjManager* GOMan;

		CMana* manaTracker;

		Clock gameClock;

		CBall* ball;

		Text* FPS;
		Text* Score;
		Text* Mana;
		Text* Lives;
		Text* LivesNo;
		Text* ScoreNo;
		Text* ManaNo;

		//Initialises the engine and it's subsystems
		bool Init();

		void initialiseGOs();
		void nukeGOs();

		//Main game loop logic here
	    void MainLoop();

		//Process User input
	     void ProcessInput();

		//Udpate Subsystems
		 void Update(float time,float fps);


		  void ShowDefeat()
			 {
				DefeatMenu menu;
				soundProvider->StopAllSounds();
				GLOBAL_ENUM a =menu.show(renderer);
				switch (a)
				{
					case Nothing:
						{
							state = Lost;
							break;
						}
					case Play:
						{
							initialiseGOs();
							soundProvider->PlaySong("resources/Sounds/game.ogg",false);
							state = Playing;
							break;
						}
					case Exit:
						{
							state = Exiting;
							break;
						}
					case ExitToMain:
						{
							state = ShowingMenu;
							initialiseGOs();
							break;
						}
				
				}
			 }

		 void ShowMenu()
			 {
				CMainMenu menu;
				soundProvider->PlaySong("resources/Sounds/menu.ogg",true);
				GLOBAL_ENUM a =menu.show(renderer);
				
				switch (a)
				{
					case Nothing:
						{
							state = ShowingMenu;
							break;
						}
					case Play:
						{
							soundProvider->StopAllSounds();
							soundProvider->PlaySong("resources/Sounds/game.ogg",false);
							initialiseGOs();
							state = Playing;
							break;
						}
					case Exit:
						{
							state = Exiting;
							break;
						}
					case Debug:
						{
							state = ShowingMenu;
							if(GOMan->debug == false)
								{
									 GOMan->debug= true;
								}
							else
								{
									GOMan->debug = false;
								}
						}
				
				}
			 }

		 static RenderWindow& GetWindow();

		 void ShowSplash()
			 {
				CSplash splash; 
				GLOBAL_ENUM a= splash.Show(*renderer.getWindow());
				if(a == ExitToMain)
					{
						state = ShowingMenu;
					}
				else
					{
						state = Exiting;
					}
			 }

		//Cleanup-after-your-mess function
		 void Close_and_Clean();

		 bool isExiting()
			 {
				if(state == Exiting) 
					{
						return true; 
					}
					else
					{
						 return false;
					}
			 }


		//possible states of the engine
		enum GameState { 
			Uninitialized, //not yet inited 
			ShowingSplash,  //showing our splash screen!
			Paused,  //we have paused the game!
		    ShowingMenu,  // we are showing the main menu
			Playing, //We're playing a game
			Exiting,
			Lost,
			Won}; //we're exiting

		//actual state
		GameState state;
	public:
		//Startup engine
		void Go();

		CEngine(void);
		~CEngine(void);
	};

