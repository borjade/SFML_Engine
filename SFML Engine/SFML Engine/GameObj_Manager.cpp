#include "GameObj_Manager.h"


CGameObj_Manager::CGameObj_Manager(void)
	{
	}


CGameObj_Manager::~CGameObj_Manager(void)
	{
		std::for_each(_gameObjects.begin(),_gameObjects.end(),GameObjectDealloc());
	}

void CGameObj_Manager::Add(std::string name,CGameObject* go)
	{
		_gameObjects.insert(std::pair<std::string,CGameObject*>(name,go));
	}

void CGameObj_Manager::Remove(std::string name)
	{
		std::map<std::string, CGameObject*>::iterator result = _gameObjects.find(name);
		if (result != _gameObjects.end())
			{
				delete result->second;
				_gameObjects.erase(result);
			}
	}

CGameObject* CGameObj_Manager::GetGO(std::string name) const
	{
		std::map<std::string, CGameObject*>::const_iterator result = _gameObjects.find(name);
		if (result != _gameObjects.end())
			{
				return result->second;
			}
		return NULL;
	}

