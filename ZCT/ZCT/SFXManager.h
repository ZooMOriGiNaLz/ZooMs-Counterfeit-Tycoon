#pragma once
#include <vector>
#include "raylib.h"

class SFXManager
{
public:
	SFXManager();
	~SFXManager();
	// Functions
	void PlaySFX(Sound sound, float volume);
	void PlayBackgroundSFX(Sound sound, float volume);
	// Sounds
	Sound sfx_purchase{};
	Sound sfx_click{};
	Sound sfx_unlock{};
	Sound sfx_background_music{};
	// Volume Settings
private:
	std::vector<Sound> sounds{};
};

