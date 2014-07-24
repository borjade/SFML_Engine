#pragma once
#include "GameObject.h"
//#include "Engine.h"
#include <string>
#include <list>
using namespace std;
class CGameObjManager
	{
	public:
		CGameObjManager(void);
		~CGameObjManager(void);

		void Add(string name, CGameObject* a);
		void Remove(string name);
		void UpdateAll(float time);

		CGameObject* Get(string name);

		inline int GetObjCount()
			{
				return gameObjects.size();
			};

		void addToDelete(string name)
			{
				toDelete.push_back(name);
			}

		void ClearDead()
			{
				list<string>::iterator iterator;
				for ( iterator = toDelete.begin(); iterator != toDelete.end(); iterator++) 
				{
					Remove(*iterator);
				}
			}

		list <string> CleanUpNames()
			{
				
				return toDelete;	
			}

		bool debug;

	private:
		map<string,CGameObject*> gameObjects;
		list <string> toDelete;

		struct GameObjectDealloc
			{
				void operator()(const pair<string,CGameObject*> & p) const
					{
						delete p.second;
					}
			};
	};

