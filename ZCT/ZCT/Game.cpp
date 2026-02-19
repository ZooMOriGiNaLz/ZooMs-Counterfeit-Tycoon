#include "Game.h"

Game::~Game()
{
	// Close Audio Device
	CloseAudioDevice();
	// Save On Close
	//saveDataManager->SaveGame(txtCoins, upgradeManager->upgrades, shopManager->items, achievementManager->badges);
	// Delete Headers
	delete(ui_header_Upgrades);
	delete(ui_header_Badges);
	delete(ui_header_Stats);
	delete(ui_header_Cookie);
	delete(ui_header_Shop);
	// Unload Font
	UnloadFont(better_comic_sans);
	// Unload Sprites
	UnloadTexture(sprite_printer);
	UnloadTexture(sprite_money);
	// Delete
	delete(buttonManager);
	delete(upgradeManager);
	delete(saveDataManager);
	delete(sfxManager);
	delete(achievementManager);
	delete(shopManager);
}

void Game::Start()
{
    // Init Window
    InitWindow(screenWidth, screenHeight, title);
    SetTargetFPS(fps);
	// Init Font
	better_comic_sans = LoadFontEx("assets/better_comic_sans_bold.ttf", 20, nullptr, 250);
	// Init Buttons And Headers
	ui_header_Upgrades = new Header(500, 400, "BUSINESSES", Vector2{ 400, 0 });
	ui_header_Badges = new Header(500, 500, "BADGES", Vector2{ 400, 425 });
	ui_header_Stats = new Header(400, 100, "STATS", Vector2{ 0, 0 });
	ui_header_Cookie = new Header(400, 275, "MONEY PRINTER", Vector2{ 0, 125 });
	ui_header_Shop = new Header(400, 500, "SHOP", Vector2{ 0, 425 });
	// Managers
	popupManager = new PopupManager();
	buttonManager = new ButtonManager();
	upgradeManager = new UpgradeManager();
	saveDataManager = new SaveDataManager();
	shopManager = new ShopManager();
	sfxManager = new SFXManager();
	achievementManager = new AchievementManager();
	saveDataManager->LoadGame(txtCoins, upgradeManager->upgrades, shopManager->items, achievementManager->badges);
	// Sprite Loading
	sprite_money = LoadTexture("assets/money.png");
	sprite_printer = LoadTexture("assets/money_printer.png");
	// Give items on load
	GrantItems();
}

void Game::Update()
{
	Buttons();
	Shop();
	shopManager->ItemHandler();
	MoneyAnimation();
	buttonManager->ButtonHandler();

	upgradeManager->UpdateTotalIncome(incomeMultiplier);
	HandleIncome();

	sfxManager->PlayBackgroundSFX(sfxManager->sfx_background_music, 0.2f);
	
	// Give Money
	if (IsKeyPressed(KEY_C))
	{
		GiveCoins(1000000000);
	}
	
	popupManager->PopupHandler(achievementManager->badges);
	popupManager->PopupHandlerItems(shopManager->items);

	// Money achievements
	if (txtCoins >= 500000 && !achievementManager->badge_half_a_millionaire->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_half_a_millionaire);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (txtCoins >= 1000000 && !achievementManager->badge_millionaire->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_millionaire);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (txtCoins >= 1000000000 && !achievementManager->badge_billionaire->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_billionaire);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}

	// Upgrade achivements
	if (shopManager->item_sports_car->owned && !achievementManager->badge_own_a_sports_car->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_a_sports_car);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}

	if (shopManager->item_double_click_01->owned && 
		shopManager->item_double_click_02->owned &&
		shopManager->item_double_click_03->owned &&
		shopManager->item_double_click_04->owned &&
		!achievementManager->badge_master_printer->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_master_printer);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}

	if (shopManager->item_white_house->owned && !achievementManager->badge_mr_president->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_mr_president);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}

	if (shopManager->item_business_strats_01->owned &&
		shopManager->item_business_strats_02->owned &&
		shopManager->item_business_strats_03->owned &&
		shopManager->item_business_strats_04->owned &&
		!achievementManager->badge_this_is_business->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_this_is_business);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}

	// Soda Achievements
	if (upgradeManager->upgrade_01->quantityOwned >= 5 && !achievementManager->badge_own_5_soda_stands->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_5_soda_stands);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_01->quantityOwned >= 10 && !achievementManager->badge_own_10_soda_stands->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_10_soda_stands);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_01->quantityOwned >= 50 && !achievementManager->badge_own_50_soda_stands->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_50_soda_stands);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_01->quantityOwned >= 100 && !achievementManager->badge_own_100_soda_stands->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_100_soda_stands);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}

	// Kebab Achivements
	if (upgradeManager->upgrade_02->quantityOwned >= 5 && !achievementManager->badge_own_5_kebab_shops->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_5_kebab_shops);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_02->quantityOwned >= 10 && !achievementManager->badge_own_10_kebab_shops->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_10_kebab_shops);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_02->quantityOwned >= 50 && !achievementManager->badge_own_50_kebab_shops->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_50_kebab_shops);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_02->quantityOwned >= 100 && !achievementManager->badge_own_100_kebab_shops->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_100_kebab_shops);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}

	// Cafe Achivements
	if (upgradeManager->upgrade_03->quantityOwned >= 5 && !achievementManager->badge_own_5_cafes->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_5_cafes);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_03->quantityOwned >= 10 && !achievementManager->badge_own_10_cafes->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_10_cafes);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_03->quantityOwned >= 50 && !achievementManager->badge_own_50_cafes->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_50_cafes);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_03->quantityOwned >= 100 && !achievementManager->badge_own_100_cafes->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_100_cafes);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}

	// Studio achievements
	if (upgradeManager->upgrade_04->quantityOwned >= 5 && !achievementManager->badge_own_5_studios->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_5_studios);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_04->quantityOwned >= 10 && !achievementManager->badge_own_10_studios->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_10_studios);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_04->quantityOwned >= 50 && !achievementManager->badge_own_50_studios->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_50_studios);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_04->quantityOwned >= 100 && !achievementManager->badge_own_100_studios->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_100_studios);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}

	// Lucci Clothes achievements
	if (upgradeManager->upgrade_05->quantityOwned >= 5 && !achievementManager->badge_own_5_clothes->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_5_clothes);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_05->quantityOwned >= 10 && !achievementManager->badge_own_10_clothes->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_10_clothes);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_05->quantityOwned >= 50 && !achievementManager->badge_own_50_clothes->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_50_clothes);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_05->quantityOwned >= 100 && !achievementManager->badge_own_100_clothes->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_100_clothes);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}

	// Car achievements
	if (upgradeManager->upgrade_06->quantityOwned >= 5 && !achievementManager->badge_own_5_cars->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_5_cars);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_06->quantityOwned >= 10 && !achievementManager->badge_own_10_cars->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_10_cars);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_06->quantityOwned >= 50 && !achievementManager->badge_own_50_cars->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_50_cars);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_06->quantityOwned >= 100 && !achievementManager->badge_own_100_cars->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_100_cars);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}

	// Diamond achievements
	if (upgradeManager->upgrade_07->quantityOwned >= 5 && !achievementManager->badge_own_5_diamonds->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_5_diamonds);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_07->quantityOwned >= 10 && !achievementManager->badge_own_10_diamonds->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_10_diamonds);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_07->quantityOwned >= 50 && !achievementManager->badge_own_50_diamonds->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_50_diamonds);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
	if (upgradeManager->upgrade_07->quantityOwned >= 100 && !achievementManager->badge_own_100_diamonds->awarded)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_100_diamonds);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}

	// Own one of each business
	if (upgradeManager->upgrade_01->quantityOwned >= 1 &&
		upgradeManager->upgrade_02->quantityOwned >= 1 &&
		upgradeManager->upgrade_03->quantityOwned >= 1 &&
		upgradeManager->upgrade_04->quantityOwned >= 1 &&
		upgradeManager->upgrade_05->quantityOwned >= 1 &&
		upgradeManager->upgrade_06->quantityOwned >= 1 &&
		upgradeManager->upgrade_07->quantityOwned >= 1)
	{
		achievementManager->UnlockAchievement(achievementManager->badge_own_every_business);
		sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
	}
}

void Game::Render()
{
    // Upgrades Header
	ui_header_Upgrades->Render();
	ui_header_Badges->Render();
	ui_header_Cookie->Render();
	ui_header_Shop->Render();
	buttonManager->RenderButtons();
	upgradeManager->RenderUpgradeStats(better_comic_sans, buyAmount);
	RenderGameStats();
	// Render Sprites
	if (moneyPosY > moneyPosYLimit)
	{
		DrawTextureEx(sprite_money, Vector2{ 150, moneyPosY }, 0.0f, 3.0f, WHITE);
	}
	DrawTextureEx(sprite_printer, Vector2{ 70, 250 }, 0.0f, 4.0f, WHITE);
	// Render Badges
	achievementManager->RenderBadges();
	shopManager->RenderItems();
	popupManager->RenderPopupBadge(GetMousePosition());
	popupManager->RenderPopupItem(GetMousePosition());
}

void Game::RenderGameStats()
{
	ui_header_Stats->Render();
	// Cash On Hand
	DrawTextEx(better_comic_sans, "Cash: ", Vector2{ 0, 30 }, 16, 2, WHITE);
	DrawTextEx(better_comic_sans, TextFormat("$%i", txtCoins), Vector2{ 135, 30 }, 16, 2, Color{ 130, 221, 130, 255 });

	// Cash Per Sec
	DrawTextEx(better_comic_sans, "Total Income: ", Vector2{ 0, 50 }, 16, 2, WHITE);
	DrawTextEx(better_comic_sans, TextFormat("$%i", upgradeManager->totalIncome), Vector2{ 135, 50 }, 16, 2, Color{201, 229, 197, 255});

	// Cash Per Click
	DrawTextEx(better_comic_sans, "Cash Per Click: ", Vector2{ 0, 70 }, 16, 2, WHITE);
	DrawTextEx(better_comic_sans, TextFormat("$%.0f", moneyperClick * moneyPerClickMultiplier), Vector2{ 135, 70 }, 16, 2, SKYBLUE);

	// Income Multiplier
	DrawTextEx(better_comic_sans, "Income Multiplier: ", Vector2{ 0, 90 }, 16, 2, WHITE);
	DrawTextEx(better_comic_sans, TextFormat("x%.2f", incomeMultiplier), Vector2{ 135, 90 }, 16, 2, PINK);

	// Click Multiplier
	DrawTextEx(better_comic_sans, "Click Multiplier: ", Vector2{ 0, 110 }, 16, 2, WHITE);
	DrawTextEx(better_comic_sans, TextFormat("x%.2f", moneyPerClickMultiplier), Vector2{ 135, 110 }, 16, 2, YELLOW);

	// Amount To Buy
	DrawTextEx(better_comic_sans, "Purchase Amount: ", Vector2{ 240, 110 }, 16, 2, WHITE);
	DrawTextEx(better_comic_sans, TextFormat("x%i", buyAmount), Vector2{ 380, 110 }, 16, 2, RED);
}

void Game::HandleIncome()
{
	incomeTimer += GetFrameTime();
	if (incomeTimer >= incomePerSecond)
	{
		incomeTimer = 0;
		txtCoins += upgradeManager->totalIncome;
	}
}

void Game::Buttons()
{
	// Print Money Button
	if (buttonManager->IsButtonClicked(buttonManager->button_print_money))
	{
		txtCoins += moneyperClick * moneyPerClickMultiplier;
		moneyPosY = 230;
		sfxManager->PlaySFX(sfxManager->sfx_click, 0.5f);

		// Achievement For First Click
		if (achievementManager->badge_first_click->awarded == false)
		{
			achievementManager->UnlockAchievement(achievementManager->badge_first_click);
			sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
		}

	}
	// Change Purchase Amount Once
	if (buttonManager->IsButtonClicked(buttonManager->button_buy_one))
	{
		buyAmount = 1;
		sfxManager->PlaySFX(sfxManager->sfx_click, 0.5f);
		std::cout << buyAmount << std::endl;
	}
	// Change Purchase Amount Five
	if (buttonManager->IsButtonClicked(buttonManager->button_buy_five))
	{
		buyAmount = 5;
		sfxManager->PlaySFX(sfxManager->sfx_click, 0.5f);
		std::cout << buyAmount << std::endl;
	}
	// Change Purchase Amount Ten
	if (buttonManager->IsButtonClicked(buttonManager->button_buy_ten))
	{
		buyAmount = 10;
		sfxManager->PlaySFX(sfxManager->sfx_click, 0.5f);
		std::cout << buyAmount << std::endl;
	}
	// Change Purchase Amount Fifty
	if (buttonManager->IsButtonClicked(buttonManager->button_buy_fifty))
	{
		buyAmount = 50;
		sfxManager->PlaySFX(sfxManager->sfx_click, 0.5f);
		std::cout << buyAmount << std::endl;
	}
	// Upgrade Button 1
	if (buttonManager->IsButtonClicked(buttonManager->button_upgrade_01) && txtCoins >= upgradeManager->upgrade_01->baseCost * buyAmount)
	{
		txtCoins -= (int)upgradeManager->upgrade_01->baseCost * buyAmount;
		for (int i = 0; i < buyAmount; i++)
		{
			upgradeManager->PurchaseUpgrade(upgradeManager->upgrade_01);
		}
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
	}
	// Upgrade Button 2
	if (buttonManager->IsButtonClicked(buttonManager->button_upgrade_02) && txtCoins >= upgradeManager->upgrade_02->baseCost * buyAmount)
	{
		txtCoins -= (int)upgradeManager->upgrade_02->baseCost;
		for (int i = 0; i < buyAmount; i++)
		{
			upgradeManager->PurchaseUpgrade(upgradeManager->upgrade_02);
		}
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
	}
	// Upgrade Button 3
	if (buttonManager->IsButtonClicked(buttonManager->button_upgrade_03) && txtCoins >= upgradeManager->upgrade_03->baseCost * buyAmount)
	{
		txtCoins -= (int)upgradeManager->upgrade_03->baseCost;
		for (int i = 0; i < buyAmount; i++)
		{
			upgradeManager->PurchaseUpgrade(upgradeManager->upgrade_03);
		}
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
	}
	// Upgrade Button 4
	if (buttonManager->IsButtonClicked(buttonManager->button_upgrade_04) && txtCoins >= upgradeManager->upgrade_04->baseCost * buyAmount)
	{
		txtCoins -= (int)upgradeManager->upgrade_04->baseCost;
		for (int i = 0; i < buyAmount; i++)
		{
			upgradeManager->PurchaseUpgrade(upgradeManager->upgrade_04);
		}
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
	}
	// Upgrade Button 5
	if (buttonManager->IsButtonClicked(buttonManager->button_upgrade_05) && txtCoins >= upgradeManager->upgrade_05->baseCost * buyAmount)
	{
		txtCoins -= (int)upgradeManager->upgrade_05->baseCost;
		for (int i = 0; i < buyAmount; i++)
		{
			upgradeManager->PurchaseUpgrade(upgradeManager->upgrade_05);
		}
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
	}
	// Upgrade Button 6
	if (buttonManager->IsButtonClicked(buttonManager->button_upgrade_06) && txtCoins >= upgradeManager->upgrade_06->baseCost * buyAmount)
	{
		txtCoins -= (int)upgradeManager->upgrade_06->baseCost;
		for (int i = 0; i < buyAmount; i++)
		{
			upgradeManager->PurchaseUpgrade(upgradeManager->upgrade_06);
		}
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
	}
	// Upgrade Button 7
	if (buttonManager->IsButtonClicked(buttonManager->button_upgrade_07) && txtCoins >= upgradeManager->upgrade_07->baseCost * buyAmount)
	{
		txtCoins -= (int)upgradeManager->upgrade_07->baseCost;
		for (int i = 0; i < buyAmount; i++)
		{
			upgradeManager->PurchaseUpgrade(upgradeManager->upgrade_07);
		}
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
	}

	// Achievement For First Upgrade
	for (int i = 0; i < upgradeManager->upgrades.size(); i++)
	{
		if (upgradeManager->upgrades[i]->quantityOwned >= 1) 
		{
			if (achievementManager->badge_first_upgrade->awarded == false)
			{
				achievementManager->UnlockAchievement(achievementManager->badge_first_upgrade);
				sfxManager->PlaySFX(sfxManager->sfx_unlock, 0.5f);
			}
		}
	}
	
}

void Game::Shop()
{
	// Item double click 1
	if (shopManager->IsItemClicked(shopManager->item_double_click_01) && txtCoins >= shopManager->item_double_click_01->cost && !shopManager->item_double_click_01->owned)
	{
		txtCoins -= shopManager->item_double_click_01->cost;
		shopManager->PurchaseItem(shopManager->item_double_click_01);
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
		moneyperClick += 2;
	}
	// Item double click 2 
	if (shopManager->IsItemClicked(shopManager->item_double_click_02) && txtCoins >= shopManager->item_double_click_02->cost && !shopManager->item_double_click_02->owned)
	{
		txtCoins -= shopManager->item_double_click_02->cost;
		shopManager->PurchaseItem(shopManager->item_double_click_02);
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
		moneyperClick += 4;
	}
	// Item double click 3
	if (shopManager->IsItemClicked(shopManager->item_double_click_03) && txtCoins >= shopManager->item_double_click_03->cost && !shopManager->item_double_click_03->owned)
	{
		txtCoins -= shopManager->item_double_click_03->cost;
		shopManager->PurchaseItem(shopManager->item_double_click_03);
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
		moneyperClick += 6;
	}
	// Item double click 4
	if (shopManager->IsItemClicked(shopManager->item_double_click_04) && txtCoins >= shopManager->item_double_click_04->cost && !shopManager->item_double_click_04->owned)
	{
		txtCoins -= shopManager->item_double_click_04->cost;
		shopManager->PurchaseItem(shopManager->item_double_click_04);
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
		moneyPerClickMultiplier += 2.00;
	}
	// Item sports car
	if (shopManager->IsItemClicked(shopManager->item_sports_car) && txtCoins >= shopManager->item_sports_car->cost && !shopManager->item_sports_car->owned)
	{
		txtCoins -= shopManager->item_sports_car->cost;
		shopManager->PurchaseItem(shopManager->item_sports_car);
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
		incomeMultiplier += 0.15;
	}
	// Item white house
	if (shopManager->IsItemClicked(shopManager->item_white_house) && txtCoins >= shopManager->item_white_house->cost && !shopManager->item_white_house->owned)
	{
		txtCoins -= shopManager->item_white_house->cost;
		shopManager->PurchaseItem(shopManager->item_white_house);
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
		incomeMultiplier += 2.00;
	}
	// Item personal bank
	if (shopManager->IsItemClicked(shopManager->item_personal_bank) && txtCoins >= shopManager->item_personal_bank->cost && !shopManager->item_personal_bank->owned)
	{
		txtCoins -= shopManager->item_personal_bank->cost;
		shopManager->PurchaseItem(shopManager->item_personal_bank);
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
		incomeMultiplier += 1.00;
	}
	// Item gold chain
	if (shopManager->IsItemClicked(shopManager->item_24_carat_gold_chain) && txtCoins >= shopManager->item_24_carat_gold_chain->cost && !shopManager->item_24_carat_gold_chain->owned)
	{
		txtCoins -= shopManager->item_24_carat_gold_chain->cost;
		shopManager->PurchaseItem(shopManager->item_24_carat_gold_chain);
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
		incomeMultiplier += 0.10;
	}
	// Item personal jet
	if (shopManager->IsItemClicked(shopManager->item_personal_jet) && txtCoins >= shopManager->item_personal_jet->cost && !shopManager->item_personal_jet->owned)
	{
		txtCoins -= shopManager->item_personal_jet->cost;
		shopManager->PurchaseItem(shopManager->item_personal_jet);
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
		incomeMultiplier += 0.10;
	}
	// Item 1x1 cube
	if (shopManager->IsItemClicked(shopManager->item_1x_cube) && txtCoins >= shopManager->item_1x_cube->cost && !shopManager->item_1x_cube->owned)
	{
		txtCoins -= shopManager->item_1x_cube->cost;
		shopManager->PurchaseItem(shopManager->item_1x_cube);
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
		moneyPerClickMultiplier += 0.25;
	}
	// Item fake moustache
	if (shopManager->IsItemClicked(shopManager->item_fake_moustache) && txtCoins >= shopManager->item_fake_moustache->cost && !shopManager->item_fake_moustache->owned)
	{
		txtCoins -= shopManager->item_fake_moustache->cost;
		shopManager->PurchaseItem(shopManager->item_fake_moustache);
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
		moneyPerClickMultiplier += 0.15;
	}
	// Item swedish fish
	if (shopManager->IsItemClicked(shopManager->item_swedish_fish) && txtCoins >= shopManager->item_swedish_fish->cost && !shopManager->item_swedish_fish->owned)
	{
		txtCoins -= shopManager->item_swedish_fish->cost;
		shopManager->PurchaseItem(shopManager->item_swedish_fish);
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
		moneyPerClickMultiplier += 0.55;
	}
	// Item business strats 1
	if (shopManager->IsItemClicked(shopManager->item_business_strats_01) && txtCoins >= shopManager->item_business_strats_01->cost && !shopManager->item_business_strats_01->owned)
	{
		txtCoins -= shopManager->item_business_strats_01->cost;
		shopManager->PurchaseItem(shopManager->item_business_strats_01);
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
		incomeMultiplier += 0.25;
	}
	// Item business strats 2
	if (shopManager->IsItemClicked(shopManager->item_business_strats_02) && txtCoins >= shopManager->item_business_strats_02->cost && !shopManager->item_business_strats_02->owned)
	{
		txtCoins -= shopManager->item_business_strats_02->cost;
		shopManager->PurchaseItem(shopManager->item_business_strats_02);
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
		incomeMultiplier += 0.30;
	}
	// Item business strats 3
	if (shopManager->IsItemClicked(shopManager->item_business_strats_03) && txtCoins >= shopManager->item_business_strats_03->cost && !shopManager->item_business_strats_03->owned)
	{
		txtCoins -= shopManager->item_business_strats_03->cost;
		shopManager->PurchaseItem(shopManager->item_business_strats_03);
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
		incomeMultiplier += 0.35;
	}
	// Item business strats 4
	if (shopManager->IsItemClicked(shopManager->item_business_strats_04) && txtCoins >= shopManager->item_business_strats_04->cost && !shopManager->item_business_strats_04->owned)
	{
		txtCoins -= shopManager->item_business_strats_04->cost;
		shopManager->PurchaseItem(shopManager->item_business_strats_04);
		sfxManager->PlaySFX(sfxManager->sfx_purchase, 0.5f);
		incomeMultiplier += 0.40;
	}
}

void Game::MoneyAnimation()
{
	// Logic For Small Money Animation
	if (moneyPosY <= moneyPosYLimit)
	{
		moneyPosY = moneyPosYLimit;
	}
	else
	{
		moneyPosY -= 200 * GetFrameTime();
	}
}

void Game::GrantItems()
{
	// Grant Items After Loading Save
	if (shopManager->item_double_click_01->owned)
	{
		moneyperClick += 2;
	}
	if (shopManager->item_double_click_02->owned)
	{
		moneyperClick += 4;
	}
	if (shopManager->item_double_click_03->owned)
	{
		moneyperClick += 6;
	}
	if (shopManager->item_double_click_04->owned)
	{
		moneyPerClickMultiplier += 2.00;
	}
	if (shopManager->item_sports_car->owned)
	{
		incomeMultiplier += 0.15;
	}
	if (shopManager->item_white_house->owned)
	{
		incomeMultiplier += 2.00;
	}
	if (shopManager->item_personal_bank->owned)
	{
		incomeMultiplier += 1.00;
	}
	if (shopManager->item_24_carat_gold_chain->owned)
	{
		incomeMultiplier += 0.10;
	}
	if (shopManager->item_personal_jet->owned)
	{
		incomeMultiplier += 0.20;
	}
	if (shopManager->item_1x_cube->owned)
	{
		moneyPerClickMultiplier += 0.25;
	}
	if (shopManager->item_fake_moustache->owned)
	{
		moneyPerClickMultiplier += 0.15;
	}
	if (shopManager->item_swedish_fish->owned)
	{
		moneyPerClickMultiplier += 0.55;
	}
	if (shopManager->item_business_strats_01->owned)
	{
		incomeMultiplier += 0.25;
	}
	if (shopManager->item_business_strats_02->owned)
	{
		incomeMultiplier += 0.30;
	}
	if (shopManager->item_business_strats_03->owned)
	{
		incomeMultiplier += 0.35;
	}
	if (shopManager->item_business_strats_04->owned)
	{
		incomeMultiplier += 0.40;
	}
}

void Game::GiveCoins(int amount)
{
	txtCoins += amount;
}
