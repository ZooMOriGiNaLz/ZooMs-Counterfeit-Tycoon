#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "raylib.h"
#include "Upgrade.h"
#include "ShopManager.h"
#include "AchievementManager.h"



class SaveDataManager
{
public:
	void SaveGame(int cash, std::vector<Upgrade*> upgrades, std::vector<Item*> items, std::vector<Badge*> badges);
	void LoadGame(int &cash, std::vector<Upgrade*> &upgrades, std::vector<Item*> &items, std::vector<Badge*> &badges);
};

