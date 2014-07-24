#pragma once

#include <string>
using namespace std;
class IAudioProvider
{
public:	
  virtual ~IAudioProvider() {}
  virtual void PlaySound(string filename) = 0;
  virtual void PlaySong(string filename, bool looping) = 0;
  virtual void StopAllSounds() = 0;
  
  virtual bool IsSoundPlaying() = 0;
  virtual bool IsSongPlaying() = 0;
};

