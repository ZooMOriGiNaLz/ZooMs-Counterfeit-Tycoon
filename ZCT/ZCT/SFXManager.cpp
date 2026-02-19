#include "SFXManager.h"

SFXManager::SFXManager()
{
	InitAudioDevice();
	// Load Sounds
	sfx_purchase = LoadSound("assets/sfx/purchase.wav");
	sounds.push_back(sfx_purchase);

	sfx_click = LoadSound("assets/sfx/click.wav");
	sounds.push_back(sfx_click);

	sfx_unlock = LoadSound("assets/sfx/unlock.wav");
	sounds.push_back(sfx_unlock);

	sfx_background_music = LoadSound("assets/sfx/heaven.wav");
	sounds.push_back(sfx_background_music);
}

SFXManager::~SFXManager()
{
	// Unload Sounds
	for (int i = 0; i < sounds.size(); i++)
	{
		UnloadSound(sounds[i]);
	}
}

void SFXManager::PlaySFX(Sound sound, float volume)
{
	SetSoundVolume(sound, volume);
	PlaySound(sound);
}

void SFXManager::PlayBackgroundSFX(Sound sound, float volume)
{
	SetSoundVolume(sound, volume);
	if(!IsSoundPlaying(sound))
	{
		PlaySound(sound);
	}
}
