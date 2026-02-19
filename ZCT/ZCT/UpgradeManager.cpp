#include "UpgradeManager.h"

UpgradeManager::UpgradeManager()
{
	// Init Upgrades
	// BASE COST, BASE COST INCREASE, QUANTITY, BASE INCOME, BASE INCOME INCREASE  
	upgrade_01 = CreateUpgrade(50, 25.00, 0, 10, 2.00);
	upgrade_02 = CreateUpgrade(2500, 25.00, 0, 50, 2.00);
	upgrade_03 = CreateUpgrade(5500, 25.00, 0, 250, 2.00);
	upgrade_04 = CreateUpgrade(10500, 25.00, 0, 500, 2.00);
	upgrade_05 = CreateUpgrade(15500, 25.00, 0, 1000, 2.00);
	upgrade_06 = CreateUpgrade(45000, 25.00, 0, 5000, 2.00);
	upgrade_07 = CreateUpgrade(85000, 25.00, 0, 10000, 2.00);
}

UpgradeManager::~UpgradeManager()
{
	// Delete Upgrades
	for (int i = 0; i < upgrades.size(); i++)
	{
		delete(upgrades[i]);
	}
}

void UpgradeManager::RenderUpgradeStats(Font font, int buyAmount)
{
	RenderUpgradeStatUI(upgrade_01, Vector2{ 630, 30 }, font, buyAmount);
	RenderUpgradeStatUI(upgrade_02, Vector2{ 630, 85 }, font, buyAmount);
	RenderUpgradeStatUI(upgrade_03, Vector2{ 630, 140 }, font, buyAmount);
	RenderUpgradeStatUI(upgrade_04, Vector2{ 630, 195 }, font, buyAmount);
	RenderUpgradeStatUI(upgrade_05, Vector2{ 630, 250 }, font, buyAmount);
	RenderUpgradeStatUI(upgrade_06, Vector2{ 630, 305 }, font, buyAmount);
	RenderUpgradeStatUI(upgrade_07, Vector2{ 630, 360 }, font, buyAmount);
}

void UpgradeManager::RenderUpgradeStatUI(Upgrade* upgrade, Vector2 position, Font font, int buyAmount)
{
	DrawTextEx(font, TextFormat("LV: %i", (int)upgrade->quantityOwned), Vector2{ position.x, position.y }, 17, 2, YELLOW);
	DrawTextEx(font, TextFormat("COST: $%i", (int)upgrade->baseCost * buyAmount), Vector2{ position.x, position.y + 16 }, 18, 2, Color{ 130, 221, 130, 255 });
	DrawTextEx(font, TextFormat("INCOME: $%i", (int)upgrade->baseIncome), Vector2{ position.x , position.y + 32 }, 17, 2, Color{ 201, 229, 197, 255 });
}

void UpgradeManager::PurchaseUpgrade(Upgrade* upgrade)
{
	upgrade->Purchase();
	upgrade->UpdateCost();
	upgrade->UpdateIncome();
	
}

Upgrade* UpgradeManager::CreateUpgrade(double baseCost, float baseCostIncrease, int quantityOwned, double baseIncome, float baseIncomeIncrease)
{
	Upgrade* upgrade = new Upgrade();
	upgrade->baseCost = baseCost;
	upgrade->costIncrease = baseCostIncrease;
	upgrade->quantityOwned = quantityOwned;
	upgrade->baseIncome = baseIncome;
	upgrade->incomeIncease = baseIncomeIncrease;
	upgrades.push_back(upgrade);
	return upgrade;
}

void UpgradeManager::UpdateTotalIncome(double multiplier)
{
	totalIncome = 0;
	for (int i = 0; i < upgrades.size(); i++)
	{
		if (upgrades[i]->quantityOwned > 0)
		{
			totalIncome += upgrades[i]->baseIncome * multiplier;
		}
	}
}