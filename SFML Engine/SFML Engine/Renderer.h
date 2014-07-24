#pragma once
#include <SFML\Graphics.hpp>
#include "Texture_Manager.h"
#include "TextManager.h"
#include <list>
#include "SpriteManager.h"

using namespace sf;
class CRenderer
	{
		//This is our window
		RenderWindow* window;

		CTexture_Manager TexMan;

		//std::list<Sprite*> spriteObjects;
		CSpriteManager* spriteMan;

		CTextManager* TextManager;

	public:

		CTexture_Manager getTextureManager(){return TexMan;}

		void addText(string name, Text* t);

		//Render just one frame
		void RenderFrame();

		//Draw all sprites!
		void DrawSprites();

		CSpriteManager* getSpriteMngr()
			{
				return spriteMan;
			}

		void addSprite(string name ,Sprite * s);

		//Initialise the renderer
		bool Init();

		void Kill();

		RenderWindow* getWindow(){return window;}
		//Constr & Destr
		CRenderer(void);

		~CRenderer(void);
	};

