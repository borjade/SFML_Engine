#pragma once
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class CTextManager
	{
	public:
		CTextManager(void);
		~CTextManager(void);

		void Add(string name,Text* t);
		void Remove();
		void Init();
		void DrawAll(RenderWindow* rw);
	private:
		map<string, Text*> TextMap;
		Font gameFont;

		struct TextDealloc
			{
				void operator()(const pair<string,Text*> & p) const
					{
						delete p.second;
					}
			};

	};

