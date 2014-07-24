#pragma once
#include "audioprovider.h"
#include <SFML\Audio.hpp>
using namespace sf;
class SFMLAudio :
	public IAudioProvider
	{
	public:
		SFMLAudio(void);
		~SFMLAudio(void);

	 void PlaySound(std::string filename);
	 void PlaySong(std::string filename, bool looping = false);
  void StopAllSounds();
  
  bool IsSoundPlaying();
  bool IsSongPlaying();

private:
  sf::SoundBuffer soundBuffer;
  sf::Sound sound;
  sf::Music music;
	};

