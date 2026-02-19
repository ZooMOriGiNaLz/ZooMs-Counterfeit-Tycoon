#include "Header.h"

Header::~Header()
{
	UnloadFont(font);
}

Header::Header(int width, int height, std::string text, Vector2 position)
{
	this->width = width;
	this->height = height;
	this->text = text;
	this->position = position;
	// Load Custom Font
	font = LoadFontEx("assets/better_comic_sans_bold.ttf", 16, 0, 250);
}

void Header::Render()
{
	DrawRectangle(position.x, position.y, width, 25, Color{0, 0, 0, 200});
	//DrawText(text.c_str(), position.x + 10, position.y + 5, 20, WHITE);
	DrawTextEx(font, text.c_str(), Vector2{ position.x + 10, position.y + 5 }, 20, 2, WHITE);
	DrawRectangle(position.x, position.y + 25, width, height, Color{ 0, 0, 0, 100 });
}
