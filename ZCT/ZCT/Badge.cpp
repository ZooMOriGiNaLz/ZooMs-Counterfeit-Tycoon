#include "Badge.h"

Badge::Badge(std::string name, std::string description, Texture2D icon)
{
	this->badge_name = name;
	this->badge_description = description;
	this->badge_icon = icon;
}

Badge::~Badge()
{
	// Unload Textures
	UnloadTexture(badge_icon);
}

void Badge::Render(Vector2 position)
{
	// Render Badge Icon
	DrawTexture(badge_icon, position.x, position.y, WHITE);
}
