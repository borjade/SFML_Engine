#include "Renderer.h"


CRenderer::CRenderer(void)
	{
	}


CRenderer::~CRenderer(void)
	{
		
	}

bool CRenderer::Init()
	{
		window = new RenderWindow(VideoMode(800,600,32),"Game Dev - Engine");

		TextManager = new CTextManager();
		TextManager->Init();

		spriteMan = new CSpriteManager();
		TexMan = CTexture_Manager();
		
		window->setVerticalSyncEnabled(true);

		if(!window)
			{
				return false;
			}
		else
			{
				//We have a window!, lets get the texture manager going!
				//LOAD ALL OF THE TEXTURES HERE!!!!
			TexMan.LoadTex("gamebkg.png");
			TexMan.LoadTex("menu_exit.png");
			TexMan.LoadTex("menu_play.png");
			TexMan.LoadTex("menu_exit_hover.png");
			TexMan.LoadTex("menu_play_hover.png");
			TexMan.LoadTex("paddle.png");
			TexMan.LoadTex("ball.png");
			TexMan.LoadTex("brick_yellow.png");
			TexMan.LoadTex("bkg.png");
			TexMan.LoadTex("brick_green.png");
			TexMan.LoadTex("brick_red.png");
			TexMan.LoadTex("photon.png");
			TexMan.LoadTex("laser.png");
			TexMan.LoadTex("menu_play_again.png");
			TexMan.LoadTex("menu_ToMain.png");
			TexMan.LoadTex("defeat.png");
			TexMan.LoadTex("debug.png");
			TexMan.LoadTex("victory.png");
				return true;
			}
	}

void CRenderer::RenderFrame()
	{
		window->clear(Color(0,0,0));
		DrawSprites();
		window->display();
	}

void CRenderer::DrawSprites()
	{
		spriteMan->DrawAll(window);
		TextManager->DrawAll(window);
	}

void CRenderer::Kill()
	{
		window->close();
		TexMan.cleanUp();
		delete spriteMan;
		delete window;
		delete TextManager;
	}

void CRenderer::addSprite(string name, Sprite* s)
	{
		spriteMan->Add(name,s);
	}

void CRenderer::addText(string name, Text* t)
	{
		TextManager->Add(name,t);
	}