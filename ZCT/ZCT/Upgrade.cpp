#include "Upgrade.h"

void Upgrade::Purchase()
{
	quantityOwned += 1;
}

void Upgrade::UpdateCost()
{
	baseCost = baseCost + (quantityOwned * costIncrease);
}

void Upgrade::UpdateIncome()
{
	if (quantityOwned > 1)
	{
		baseIncome = baseIncome + (quantityOwned * incomeIncease);
	}
}
