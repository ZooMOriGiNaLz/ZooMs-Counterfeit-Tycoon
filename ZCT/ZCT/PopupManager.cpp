#include "PopupManager.h"

PopupManager::PopupManager()
{
	font = LoadFontEx("assets/better_comic_sans_bold.ttf", 12, 0, 250);
}

PopupManager::~PopupManager()
{
	UnloadFont(font);
}

void PopupManager::RenderPopupBadge(Vector2 mousePos)
{
	if (popUpActive && badge_selected != nullptr && badge_selected->awarded)
	{
		if (mousePos.x + 250 > 800)
		{
			mousePos.x -= 250;
		}
		if (mousePos.y + 125  > 750)
		{
			mousePos.y -= 125;
		}
		DrawRectangle(mousePos.x, mousePos.y + 25, 250, 80, Color{ 0, 0, 0, 230 });
		// Draw Name
		DrawTextEx(font, badge_selected->badge_name.c_str(), Vector2{ mousePos.x + 45, mousePos.y + 40 }, 16, 2, WHITE);
		// Draw Icon
		DrawTextureEx(badge_selected->badge_icon, Vector2{ mousePos.x + 10, mousePos.y + 35 }, 0, 0.5f, WHITE);
		// Draw Description
		DrawTextEx(font, badge_selected->badge_description.c_str(), Vector2{ mousePos.x + 10, mousePos.y + 75 }, 16, 2, WHITE);
	}
}

void PopupManager::RenderPopupItem(Vector2 mousePos)
{
	if (itemPopUpActive && item_selected != nullptr)
	{
		if (mousePos.x + 250 > 800)
		{
			mousePos.x -= 200;
		}
		if (mousePos.y + 125 > 750)
		{
			mousePos.y -= 125;
		}
		DrawRectangle(mousePos.x, mousePos.y + 25, 300, 100, Color{ 0, 0, 0, 230 });
		// Draw Name
		DrawTextEx(font, item_selected->item_name.c_str(), Vector2{ mousePos.x + 45, mousePos.y + 40 }, 16, 2, WHITE);
		// Draw Icon
		DrawTextureEx(item_selected->item_icon, Vector2{ mousePos.x + 10, mousePos.y + 35 }, 0, 0.5f, WHITE);
		// Draw Description
		DrawTextEx(font, item_selected->item_description.c_str(), Vector2{ mousePos.x + 10, mousePos.y + 100 }, 16, 2, WHITE);

		if (!item_selected->owned)
		{
			DrawTextEx(font, TextFormat("Cost: $%i", item_selected->cost), Vector2{ mousePos.x + 10, mousePos.y + 75 }, 16, 2, WHITE);
		}
		else
		{
			DrawTextEx(font, "Owned", Vector2{mousePos.x + 10, mousePos.y + 75}, 16, 2, WHITE);
		}
	}
}

void PopupManager::PopupHandler(std::vector<Badge*> badges)
{
	for (int i = 0; i < badges.size(); i++)
	{
		if (EnablePopup(badges[i])) 
		{
			badge_selected = badges[i];
			popUpActive = true;
			break;
		}
		else
		{
			badge_selected = nullptr;
			popUpActive = false;
		}
	}
}

void PopupManager::PopupHandlerItems(std::vector<Item*> items)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (EnablePopupItem(items[i]))
		{
			item_selected = items[i];
			itemPopUpActive = true;
			break;
		}
		else
		{
			item_selected = nullptr;
			itemPopUpActive = false;
		}
	}
}

bool PopupManager::EnablePopup(Badge* badge)
{
	if (GetMousePosition().x < badge->position.x + badge->width &&
		GetMousePosition().x > badge->position.x &&
		GetMousePosition().y < badge->position.y + badge->height &&
		GetMousePosition().y > badge->position.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool PopupManager::EnablePopupItem(Item* item)
{
	if (GetMousePosition().x < item->position.x + item->width &&
		GetMousePosition().x > item->position.x &&
		GetMousePosition().y < item->position.y + item->height &&
		GetMousePosition().y > item->position.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
