#include "Button.h"

Button::Button()
{
	
}

Button::~Button()
{
	UnloadFont(font);
}

Button::Button(int width, int height, std::string text, Vector2 position)
{
	this->width = width;
	this->height = height;
	this->text = text;
	this->position = position;
	// Load Custom Font
	font = LoadFontEx("assets/better_comic_sans_bold.ttf", 16, 0, 250);
}

void Button::Render()
{
	if (!isSelected)
	{
		DrawRectangle(position.x, position.y, width, height, Color{ 0, 0, 0, 200 });
		DrawTextEx(font, text.c_str(), Vector2{ position.x + 10, position.y + 15 }, 20, 2, WHITE);
	}
	else
	{
		DrawRectangle(position.x, position.y - 3, width, height, Color{ 0, 0, 0, 255 });
		DrawTextEx(font, text.c_str(), Vector2{ position.x + 10, position.y + 15 }, 20, 2, WHITE);
	}
}

Vector2 Button::GetPosition()
{
	return position;
}

int Button::GetWidth()
{
	return width;
}

int Button::GetHeight()
{
	return height;
}

std::string Button::GetText()
{
	return text;
}

void Button::OnHover()
{
	DrawRectangle(position.x, position.y - 5, width, height, Color{ 0, 0, 0, 255 });
}

void Button::SetColour(Color colour)
{
	this->colour = colour;
}

void Button::EnableRender()
{
	canRender = true;
}

void Button::DisableRender()
{
	canRender = false;
}

bool Button::GetCanRender()
{
	return canRender;
}

void Button::Enable()
{
	isEnabled = true;
}

void Button::Disable()
{
	isEnabled = false;
}

bool Button::GetActive()
{
	return isEnabled;
}
