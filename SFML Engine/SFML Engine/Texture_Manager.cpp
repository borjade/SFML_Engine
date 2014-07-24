#include "Texture_Manager.h"


CTexture_Manager::CTexture_Manager(void)
	{
	}

bool CTexture_Manager::LoadTex(string name)
	{
		if(!checkTex(name)) //Is the image already here?
		{
			 Texture* tex = new Texture();

			if(tex->loadFromFile("resources/Images/"+name) != true)
				{
					return false;
				};

			addTex(tex,name);
			return true;
		}
		return false;
	}

void CTexture_Manager::addTex(Texture* i, string name)
	{
		ImageMap.insert(pair<string,Texture*>(name,i));
	}

bool CTexture_Manager::checkTex(string name)
	{
		map<string, Texture*>::iterator i=ImageMap.find(name);

		if(i!=ImageMap.end())
			{
				return true; //It is there
			}
		else
			{
				return false; //it isn't
			}

	}

Texture* CTexture_Manager::getTex(string name)
	{
		map<string, Texture*>::iterator i=ImageMap.find(name);
		if(i != ImageMap.cend())
			{
				return i->second;
			}
		else
			{
				return NULL;
			}
	}

void CTexture_Manager::cleanUp()
	{
		for(map<string, Texture*>::iterator i = ImageMap.begin();i != ImageMap.end(); ++i )
			{
				delete i->second;
			}
		ImageMap.erase(ImageMap.begin(),ImageMap.end());
	}