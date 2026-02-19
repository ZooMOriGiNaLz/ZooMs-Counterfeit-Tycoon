#include "ShopManager.h"

ShopManager::ShopManager()
{
	item_double_click_01 = CreateItem("Printer I", "+2 Cash Per Click", LoadTexture("assets/shop_art/money_printer_upgrade_01.png"), 100);
	item_fake_moustache = CreateItem("Fake Moustache", "+15% Cash Per Click Multiplier", LoadTexture("assets/shop_art/fake_moustache.png"), 200);
	item_1x_cube = CreateItem("1x1 Cube", "+25% Cash Per Click Multiplier", LoadTexture("assets/shop_art/1x1_cube.png"), 300);
	item_double_click_02 = CreateItem("Printer II", "+4 Cash Per Click", LoadTexture("assets/shop_art/money_printer_upgrade_02.png"), 500);
	item_24_carat_gold_chain = CreateItem("24 Carat Gold Chain", "+10% Income Multiplier", LoadTexture("assets/shop_art/gold_chain.png"), 1500);
	item_double_click_03 = CreateItem("Printer III", "+8 Cash Per Click", LoadTexture("assets/shop_art/money_printer_upgrade_03.png"), 2000);
	item_swedish_fish = CreateItem("Swedish Fish", "55% Cash Per Click Multiplier", LoadTexture("assets/shop_art/swedish_fish.png"), 2500);
	item_sports_car = CreateItem("Sports Car", "+15% Income Multiplier", LoadTexture("assets/shop_art/sports_car_upgrade.png"), 10000);
	item_personal_jet = CreateItem("Personal Jet", "+20% Income Multiplier", LoadTexture("assets/shop_art/personal_jet.png"), 25000);
	item_business_strats_01 = CreateItem("Business Strategy I", "+25% Income Multiplier", LoadTexture("assets/shop_art/business_strats_01.png"), 30000);
	item_business_strats_02 = CreateItem("Business Strategy II", "+30% Income Multiplier", LoadTexture("assets/shop_art/business_strats_02.png"), 35000);
	item_business_strats_03 = CreateItem("Business Strategy III", "+35% Income Multiplier", LoadTexture("assets/shop_art/business_strats_03.png"), 40000);
	item_business_strats_04 = CreateItem("Business Strategy X", "+40% Income Multiplier", LoadTexture("assets/shop_art/business_strats_04.png"), 45000);
	item_double_click_04 = CreateItem("Printer X", "+200% Cash Per Click Multiplier", LoadTexture("assets/shop_art/money_printer_upgrade_04.png"), 50000);
	item_personal_bank = CreateItem("Personal Bank", "+100% Income Multiplier", LoadTexture("assets/shop_art/personal_bank.png"), 12000000);
	item_white_house = CreateItem("White House", "+200% Income Multiplier", LoadTexture("assets/shop_art/white_house_upgrade.png"), 400000000 );
}

ShopManager::~ShopManager()
{
	for (int i = 0; i < items.size(); i++)
	{
		delete(items[i]);
	}
}

void ShopManager::RenderItems()
{
	for (int i = 0; i < items.size(); ++i)
	{
		int col = i % 7;
		int row = i / 7;
		float x = 10 + (float)col * (48 + 5);
		float y = 460 + (float)row * (48 + 5);
		items[i]->position.x = x;
		items[i]->position.y = y;
		items[i]->width = 48;
		items[i]->height = 48;

		if (!items[i]->owned)
		{
			DrawTexture(items[i]->item_icon, x, y, WHITE);
		}
		else
		{
			DrawTexture(items[i]->item_icon, x, y, Color{255, 255, 255, 100});
		}
	}
}

Item* ShopManager::CreateItem(std::string name, std::string description, Texture2D icon, int cost)
{
	Item* item = new Item(name, description, icon, cost);
	items.push_back(item);
	return item;
}

void ShopManager::PurchaseItem(Item* item)
{
	if (item != nullptr)
	{
		item->owned = true;
	}
}

void ShopManager::ItemHandler()
{
	// Figure Out Which Upgrade Button Is Selected
	for (int i = 0; i < items.size(); i++)
	{
		if (OnHoverItem(items[i]))
		{
			item_selected = items[i];
			break;
		}
		else
		{
			item_selected = nullptr;
		}
	}
}

bool ShopManager::OnHoverItem(Item* item)
{
	if (GetMousePosition().x < item->position.x + item->width &&
		GetMousePosition().x > item->position.x &&
		GetMousePosition().y < item->position.y + item->height &&
		GetMousePosition().y > item->position.y)
	{
		return true;
	}
	
	return false;
}

bool ShopManager::IsItemClicked(Item* item)
{
	if (IsMouseButtonPressed(0))
	{
		if (item == item_selected)
		{
			return true;
		}
	}

	return false;
}
