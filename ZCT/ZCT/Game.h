#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"
#include "Header.h"
#include "Button.h"
#include "Upgrade.h"
#include "ButtonManager.h"
#include "UpgradeManager.h"
#include "SaveDataManager.h"
#include "SFXManager.h"
#include "AchievementManager.h"
#include "PopupManager.h"
#include "ShopManager.h"

class Game
{
public:
	// Main Functions
	~Game();
	void Start();
	void Update();
	void Render();
	// Other UI Functions
	void RenderGameStats();
	// Game Functions
	void HandleIncome();
	void Buttons();
	void Shop();
	void MoneyAnimation();
	void GrantItems();
	// Dev Cheats
	void GiveCoins(int amount);
private:
	// Window Settings
	const int screenWidth{ 800 };
	const int screenHeight{ 800 };
	int fps{ 60 };
	const char* title{ "ZooM's Counterfeit Tycoon" };
	// Game Managers
	SaveDataManager* saveDataManager{};
	AchievementManager* achievementManager{};
	ButtonManager* buttonManager{};
	UpgradeManager* upgradeManager{};
	PopupManager* popupManager{};
	SFXManager* sfxManager{};
	ShopManager* shopManager{};
	// UI Headers
	Header* ui_header_Upgrades{};
	Header* ui_header_Badges{};
	Header* ui_header_Stats{};
	Header* ui_header_Cookie{};
	Header* ui_header_Shop{};
	// Font
	Font better_comic_sans{};
	// Sprites
	Texture2D sprite_printer{};
	Texture2D sprite_money{};
	// Game Stats
	int txtCoins{};
	int incomePerSecond{ 1 };
	int buyAmount{ 1 };
	double totalIncome{};
	double incomeMultiplier{ 1.00 };
	int moneyperClick{ 1 };
	float moneyPerClickMultiplier{ 1.00 };
	float incomeTimer{};
	// Money Animation
	bool isMoneyClicked{ false };
	float moneyPosY{ 175 };
	float moneyPosYLimit{ 175 };
};

