#include "GameObjManager.h"


CGameObjManager::CGameObjManager(void)
	{
		debug = false;
	}


CGameObjManager::~CGameObjManager(void)
	{
		for_each(gameObjects.begin(),gameObjects.end(),GameObjectDealloc());
	}


void CGameObjManager::Add(string name, CGameObject* a)
	{
		gameObjects.insert(pair<string, CGameObject*>(name,a));
	}

void CGameObjManager::Remove(string name)
	{
		map<string,CGameObject*>::iterator result = gameObjects.find(name);

		if(result != gameObjects.end())
			{
				delete result->second;
				gameObjects.erase(result);
			}
	}

CGameObject* CGameObjManager::Get(string name)
	{
		map<string,CGameObject*>::iterator result = gameObjects.find(name);

		if(result != gameObjects.end())
			{
				return result->second;
			}
		return NULL;
	}

void CGameObjManager::UpdateAll(float time)
	{
		map<string,CGameObject*>::const_iterator itr = gameObjects.begin();

		while(itr != gameObjects.end())
		 {
		 if(itr->second->GetDead() == false)
			 {
				itr->second->Update(time); //NEED A WAY TO SEND IN FRAMETIME!!!!
			 }
			itr++;
		 }
	}