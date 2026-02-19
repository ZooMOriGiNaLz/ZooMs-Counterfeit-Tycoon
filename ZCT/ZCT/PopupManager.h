#pragma once
#include <iostream>
#include "raylib.h"
#include "AchievementManager.h"
#include "Badge.h"
#include "Item.h"


class PopupManager
{
public:
	PopupManager();
	~PopupManager();
	void RenderPopupBadge(Vector2 mousePos);
	void RenderPopupItem(Vector2 mousePos);
	void PopupHandler(std::vector<Badge*> badges);
	void PopupHandlerItems(std::vector<Item*> items);
	// Enable Using Badge
	bool EnablePopup(Badge* badge);
	bool EnablePopupItem(Item* item);
	Badge* badge_selected{};
	Item* item_selected{};
private:
	bool popUpActive{};
	bool itemPopUpActive{};
	Font font{};
};

