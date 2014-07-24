#include "SpriteManager.h"


CSpriteManager::CSpriteManager(void)
	{
	}


CSpriteManager::~CSpriteManager(void)
	{
		DeleteAll();
	}

void CSpriteManager::DeleteAll()
	{
		for_each(SpriteMap.begin(),SpriteMap.end(),SpriteDealloc());
		SpriteMap.clear();
	}

void CSpriteManager::Add(string name, Sprite* s)
	{
		SpriteMap.insert(pair<string, Sprite*>(name,s));
	}

void CSpriteManager::Remove(string name)
	{
		map<string,Sprite*>::iterator result = SpriteMap.find(name);

		if(result != SpriteMap.end())
			{
				delete result->second;
				SpriteMap.erase(result);
			}
	}

Sprite* CSpriteManager::Get(string name)
	{
		map<string,Sprite*>::iterator result = SpriteMap.find(name);

		if(result != SpriteMap.end())
			{
				return result->second;
			}
		return NULL;
	}


void CSpriteManager::DrawAll(RenderWindow* w)
	{
		map<string,Sprite*>::const_iterator itr = SpriteMap.begin();

		while(itr != SpriteMap.end())
		 {
		 if(itr->second->getPosition().y >= -5.0f && itr->second->getPosition().y <= 600.0f)
			 {
				w->draw(*(itr->second));
			 }
			itr++;
		 }
	}