#pragma once
#include <iostream>
#include "raylib.h"

class Header
{
public:
	~Header();
	Header(int width, int height, std::string text, Vector2 position);
	void Render();
private:
	int width{};
	int height{};
	std::string text{};
	Vector2 position{};
	Font font{};
};

