#include "TextManager.h"


CTextManager::CTextManager(void)
	{
	}


CTextManager::~CTextManager(void)
	{
		for_each(TextMap.begin(),TextMap.end(),TextDealloc());
	}

void CTextManager::Init()
	{
		if(!gameFont.loadFromFile("resources/Fonts/alphbeta.ttf"))
		{
			return;
		}
	}

void CTextManager::Add(string name,Text* t)
	{
		t->setFont(gameFont);
		t->setColor(Color::White);
		TextMap.insert(pair<string, Text*>(name,t));
	}

void CTextManager::DrawAll(RenderWindow* rw)
	{
		map<string,Text*>::const_iterator itr = TextMap.begin();

		while(itr != TextMap.end())
		 {
			rw->draw(*(itr->second));
			itr++;
		 }
	}