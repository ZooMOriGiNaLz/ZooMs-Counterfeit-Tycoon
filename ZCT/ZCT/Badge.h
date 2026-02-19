#pragma once
#include <vector>
#include <iostream>
#include "raylib.h"

class Badge
{
public:
	Badge(std::string name, std::string description, Texture2D icon);
	~Badge();
	void Render(Vector2 position);
	Texture2D badge_icon{};
	std::string badge_name{};
	std::string badge_description{};
	Vector2 position{};
	int width{};
	int height{};
	bool awarded{};
};

