#pragma once
#include <map>
#include <string>
#include "SFML\Graphics.hpp"

using namespace std;
using namespace sf;

class CTexture_Manager
	{
	private:
		map<string,Texture*> ImageMap;
	public:
		CTexture_Manager(void);
		~CTexture_Manager(void) {};

		bool LoadTex(string name);
		bool checkTex(string name);

		void addTex(Texture* i, string name);
		Texture* getTex(string name);

		void cleanUp();


	};

