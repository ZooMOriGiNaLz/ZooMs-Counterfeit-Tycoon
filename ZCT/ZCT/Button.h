#pragma once
#include <iostream>
#include "raylib.h"

class Button
{
public:
	Button();
	~Button();
	Button(int width, int height, std::string text, Vector2 position);
	void Render();
	Vector2 GetPosition();
	int GetWidth();
	int GetHeight();
	std::string GetText();
	void OnHover();
	void SetColour(Color colour);
	// For Invisible Buttons
	void EnableRender();
	void DisableRender();
	bool GetCanRender();
	// For Disabling Buttons
	void Enable();
	void Disable();
	bool GetActive();
	bool isSelected{};
private:
	int width{};
	int height{};
	std::string text{};
	Vector2 position{};
	Font font{};
	Color colour{};
	bool canRender{};
	bool isEnabled{};
};

