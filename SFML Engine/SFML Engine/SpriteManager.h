#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;
class CSpriteManager
	{
	public:
		CSpriteManager(void);
		~CSpriteManager(void);

		void Add(string name, Sprite* s);
		void Remove(string name);

		map<string, Sprite*> getMap()
			{
				return SpriteMap;
			}

		Sprite* Get(string name);

		void addToDelete(list<string> names)
			{
				toDelete = names;
			}

		void ClearDead()
			{
				list<string>::iterator iterator;
				for ( iterator = toDelete.begin(); iterator != toDelete.end(); iterator++) 
				{
					Remove(*iterator);
				}
			}

		void CleanUpNames()
			{
				
				//toDelete.pop_back();	
			}
		void DrawAll(RenderWindow* w);

		void DeleteAll();

	private:
		map<string, Sprite*> SpriteMap;
		list <string> toDelete;

		struct SpriteDealloc
			{
				void operator()(const pair<string,Sprite*> & p) const
					{
						delete p.second;
					}
			};
	}; 

