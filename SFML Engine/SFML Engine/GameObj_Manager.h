#pragma once
#include "GameObject.h"
class CGameObj_Manager
	{
	public:
		CGameObj_Manager(void);
		~CGameObj_Manager(void);

		void Add(std::string name,CGameObject* go);
		void Remove(std::string name);
		inline int GetObjCount()const{return _gameObjects.size();};
		CGameObject* GetGO(std::string name) const;

	private:

		std::map<std::string, CGameObject*> _gameObjects;

		struct GameObjectDealloc
			{
				void operator()(const std::pair<std::string,CGameObject*> & p)const
					{
						delete p.second;
					}
			};

	};

