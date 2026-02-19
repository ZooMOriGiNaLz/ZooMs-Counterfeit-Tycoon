#include "SaveDataManager.h"

void SaveDataManager::SaveGame(int cash, std::vector<Upgrade*> upgrades, std::vector<Item*> items, std::vector<Badge*> badges)
{
	std::ofstream saveFile("savegame.txt");
	if (saveFile.is_open())
	{
		// Save Cash
		saveFile << "CASH " << cash << std::endl;
		// Save Upgrades
		for (int i = 0; i < upgrades.size(); ++i)
		{
            saveFile << "UPGRADE " << i << " " << upgrades[i]->baseCost << " " << upgrades[i]->quantityOwned << " " << upgrades[i]->baseIncome << std::endl;
		}
        // Save Achievements
        for (int i = 0; i < badges.size(); ++i)
        {
            saveFile << "ACHIEVEMENTS " << i << " " << badges[i]->awarded << std::endl;
        }
        // Save Items
        for (int i = 0; i < items.size(); ++i)
        {
            saveFile << "ITEMS " << i << " " << items[i]->owned << std::endl;
        }
		saveFile.close();
	}
}

void SaveDataManager::LoadGame(int &cash, std::vector<Upgrade*> &upgrades, std::vector<Item*> &items, std::vector<Badge*> &badges)
{
    std::ifstream loadFile("savegame.txt");
    if (!loadFile.is_open())
    {
        std::cerr << "Failed to open save file\n";
        return;
    }

    std::string type;
    while (loadFile >> type)
    {
        if (type == "CASH")
        {
            loadFile >> cash;
        }
        else if (type == "UPGRADE")
        {
            int index;
            loadFile >> index;
            if (index >= upgrades.size()) upgrades.resize(index + 1);
            loadFile >> upgrades[index]->baseCost >> upgrades[index]->quantityOwned >> upgrades[index]->baseIncome;
        }
        else if (type == "ACHIEVEMENTS")
        {
            int index;
            bool awarded;
            loadFile >> index >> awarded;

            if (index < badges.size())
            {
                badges[index]->awarded = awarded;
            }
        }
        else if (type == "ITEMS")
        {
            int index;
            bool owned;
            loadFile >> index >> owned;

            if (index < items.size())
            {
                items[index]->owned = owned;
            }
        }
    }

}
