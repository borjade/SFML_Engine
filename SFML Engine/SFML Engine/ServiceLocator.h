#pragma once
#include "AudioProvider.h"
class CServiceLocator
	{
	public:
		static IAudioProvider * GetAudio()  { return audioProvider; } const

		static void RegisterServiceLocator(IAudioProvider * provider)
			{
				audioProvider = provider;
			}

		CServiceLocator(void);
		~CServiceLocator(void);

	private:
		static IAudioProvider* audioProvider;
	};

