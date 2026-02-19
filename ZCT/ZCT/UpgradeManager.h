#pragma once
#include <vector>
#include "Upgrade.h"

class UpgradeManager
{
public:
	// Load And Unload
	UpgradeManager();
	~UpgradeManager();
	// Render Upgrade Things
	void RenderUpgradeStats(Font font, int buyAmount);
	void RenderUpgradeStatUI(Upgrade* upgrade, Vector2 position, Font font, int buyAmount);
	// Upgrade Handling
	void PurchaseUpgrade(Upgrade* upgrade);
	Upgrade* CreateUpgrade(double baseCost, float baseCostIncrease, int quantityOwned, double baseIncome, float baseIncomeIncrease);
	// Total Income Handler
	void UpdateTotalIncome(double multiplier);
	// Upgrades
	Upgrade* upgrade_01{};
	Upgrade* upgrade_02{};
	Upgrade* upgrade_03{};
	Upgrade* upgrade_04{};
	Upgrade* upgrade_05{};
	Upgrade* upgrade_06{};
	Upgrade* upgrade_07{};
	// Total Income
	int totalIncome{};
	// Vector Arrays
	std::vector<Upgrade*> upgrades{};
private:
};

