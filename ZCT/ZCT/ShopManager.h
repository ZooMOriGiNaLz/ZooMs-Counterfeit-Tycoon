#pragma once
#include <vector>
#include "raylib.h"
#include "Item.h"


class ShopManager
{
public:
	ShopManager();
	~ShopManager();
	void RenderItems();
	Item* CreateItem(std::string name, std::string description, Texture2D icon, int cost);
	void PurchaseItem(Item* item);
	void ItemHandler();
	bool OnHoverItem(Item* item);
	bool IsItemClicked(Item* item);
	// Items
	Item* item_double_click_01{};
	Item* item_double_click_02{};
	Item* item_double_click_03{};
	Item* item_double_click_04{};
	Item* item_business_strats_01{};
	Item* item_business_strats_02{};
	Item* item_business_strats_03{};
	Item* item_business_strats_04{};
	Item* item_sports_car{};
	Item* item_personal_bank{};
	Item* item_white_house{};
	Item* item_24_carat_gold_chain{};
	Item* item_personal_jet{};
	Item* item_1x_cube{};
	Item* item_fake_moustache{};
	Item* item_swedish_fish{};
	// Item Container
	std::vector<Item*> items{};
	// Track Selected Item
	Item* item_selected{};
	// Achievement Tracking Bools
	bool hasClickedPrintMoney{ false };
private:

};

