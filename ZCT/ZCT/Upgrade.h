#pragma once
#include <iostream>
#include "raylib.h"

class Upgrade
{
public:
	double baseCost{};
	float costIncrease{};
	int quantityOwned{};
	double baseIncome{};
	float incomeIncease{};
	void Purchase();
	void UpdateCost();
	void UpdateIncome();
private:
	
};

