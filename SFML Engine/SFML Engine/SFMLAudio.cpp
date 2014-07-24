#include "SFMLAudio.h"


SFMLAudio::SFMLAudio()
{
  
   
}


SFMLAudio::~SFMLAudio()
{

}

void SFMLAudio::PlaySound(std::string filename) 
{
  
  if(soundBuffer.getDuration().asSeconds() == 0)
  {
    soundBuffer.loadFromFile(filename);
  }
  if(sound.getStatus() == sf::Sound::Playing)
  {
    sound.stop();
  }
  sound.setBuffer(soundBuffer);
  sound.setVolume(100.0f);
  sound.play();
}
  
void SFMLAudio::PlaySong(std::string filename, bool looping)
{
  music.openFromFile(filename);
  music.setLoop(looping);
  music.setVolume(20.0f);
  music.play();
}

void SFMLAudio::StopAllSounds() 
{
  if(sound.getStatus() == sf::Sound::Playing)
    sound.stop();
  if(music.getStatus() == sf::Sound::Playing)
    music.stop();
}
  
bool SFMLAudio::IsSoundPlaying()
{
  return sound.getStatus() == sf::Sound::Playing;
}


bool SFMLAudio::IsSongPlaying()
{
  return music.getStatus() == sf::Music::Playing;  
}
