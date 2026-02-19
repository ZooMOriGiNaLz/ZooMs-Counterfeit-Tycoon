#pragma once
#include <iostream>
#include "raylib.h"

class Item
{
public:
	Item(std::string name, std::string description, Texture2D icon, int cost);
	~Item();
	void Render(Vector2 position);
	Texture2D item_icon{};
	std::string item_name{};
	std::string item_description{};
	Vector2 position{};
	int width{};
	int height{};
	int cost{};
	bool owned{};
};

