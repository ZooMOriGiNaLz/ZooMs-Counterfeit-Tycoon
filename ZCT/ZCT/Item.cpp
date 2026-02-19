#include "Item.h"

Item::Item(std::string name, std::string description, Texture2D icon, int cost)
{
	this->item_name = name;
	this->item_description = description;
	this->item_icon = icon;
	this->cost = cost;
}

Item::~Item()
{
	// Unload Textures
	UnloadTexture(item_icon);
}

void Item::Render(Vector2 position)
{
	// Render Badge Icon
	DrawTexture(item_icon, position.x, position.y, WHITE);
}
