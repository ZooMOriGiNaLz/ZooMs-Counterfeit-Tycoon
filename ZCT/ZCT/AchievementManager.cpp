#include "AchievementManager.h"

AchievementManager::AchievementManager()
{
	badge_first_click = CreateAchievement("ME FIRST DOLLAR!", "Earn your first dollar!", LoadTexture("assets/badge_art/badge_mefirstdollar.png"));
	badge_first_upgrade = CreateAchievement("Spend money, make money!", "Purchase your first upgrade!", LoadTexture("assets/badge_art/badge_spendmoneymakemoney.png"));
	badge_half_a_millionaire = CreateAchievement("Half A Millionaire!", "Reach $500,000!", LoadTexture("assets/badge_art/badge_halfamillionaire.png"));
	badge_millionaire = CreateAchievement("Millionaire!", "Reach $1,000,000!", LoadTexture("assets/badge_art/badge_millionaire.png"));
	badge_billionaire = CreateAchievement("Billionaire!", "Reach $1,000,000,000!", LoadTexture("assets/badge_art/badge_billionaire.png"));
	badge_own_a_sports_car = CreateAchievement("I woke up in a new...!", "Own a Sports Car!", LoadTexture("assets/badge_art/badge_ownasportscar.png"));
	badge_master_printer = CreateAchievement("The Master Of Printers!", "Own all Money Printer Upgrades!", LoadTexture("assets/badge_art/badge_gearsandwrenches.png"));
	badge_mr_president = CreateAchievement("Mr. President!", "Buy the White House!", LoadTexture("assets/badge_art/badge_mrpresident.png"));
	badge_this_is_business = CreateAchievement("This is business!", "Own all Business Strat Upgrades!", LoadTexture("assets/badge_art/badge_this_is_business.png"));
	badge_own_5_soda_stands = CreateAchievement("Sally's Soda Stand I", "Obtain a level 5 soda stand!", LoadTexture("assets/badge_art/badge_soda_stand_01.png"));
	badge_own_10_soda_stands = CreateAchievement("Sally's Soda Stand II", "Obtain a level 10 soda stand!", LoadTexture("assets/badge_art/badge_soda_stand_02.png"));
	badge_own_50_soda_stands = CreateAchievement("Sally's Soda Stand III", "Obtain a level 50 soda stand!", LoadTexture("assets/badge_art/badge_soda_stand_03.png"));
	badge_own_100_soda_stands = CreateAchievement("Sally's Soda Stand IV", "Obtain a level 100 soda stand!", LoadTexture("assets/badge_art/badge_soda_stand_04.png"));
	badge_own_5_kebab_shops = CreateAchievement("Kebab Empire I", "Obtain a level 5 kebab shop!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_10_kebab_shops = CreateAchievement("Kebab Empire II", "Obtain a level 10 kebab shop!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_50_kebab_shops = CreateAchievement("Kebab Empire III", "Obtain a level 50 kebab shop!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_100_kebab_shops = CreateAchievement("Kebab Empire IV", "Obtain a level 100 kebab shop!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_5_cafes = CreateAchievement("World Wide Cafe I", "Obtain a level 5 cafe!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_10_cafes = CreateAchievement("World Wide Cafe II", "Obtain a level 10 cafe!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_50_cafes = CreateAchievement("World Wide Cafe III", "Obtain a level 50 cafe!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_100_cafes = CreateAchievement("World Wide Cafe IV", "Obtain a level 100 cafe!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_5_studios = CreateAchievement("ALTF4 Studios I", "Obtain a level 5 game studio!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_10_studios = CreateAchievement("ALTF4 Studios II", "Obtain a level 10 game studio!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_50_studios = CreateAchievement("ALTF4 Studios III", "Obtain a level 50 game studio!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_100_studios = CreateAchievement("ALTF4 Studios IV", "Obtain a level 100 game studio!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_5_clothes = CreateAchievement("Lucci Clothes I", "Obtain a level 5 clothing store!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_10_clothes = CreateAchievement("Lucci Clothes II", "Obtain a level 10 clothing store!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_50_clothes = CreateAchievement("Lucci Clothes III", "Obtain a level 50 clothing store!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_100_clothes = CreateAchievement("Lucci Clothes IV", "Obtain a level 100 clothing store!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_5_cars = CreateAchievement("Luxery Car Dealership I", "Obtain a level 5 car dealership!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_10_cars = CreateAchievement("Luxery Car Dealership II", "Obtain a level 10 car dealership!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_50_cars = CreateAchievement("Luxery Car Dealership III", "Obtain a level 50 car dealership!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_100_cars = CreateAchievement("Luxery Car Dealership IV", "Obtain a level 100 car dealership!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_5_diamonds = CreateAchievement("Jewellery Store I", "Obtain a level 5 jewellery store!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_10_diamonds = CreateAchievement("Jewellery Store II", "Obtain a level 10 jewellery store!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_50_diamonds = CreateAchievement("Jewellery Store III", "Obtain a level 50 jewellery store!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_100_diamonds = CreateAchievement("Jewellery Store IV", "Obtain a level 100 jewellery store!", LoadTexture("assets/badge_art/badge_placeholder.png"));
	badge_own_every_business = CreateAchievement("Variety Of Money!", "Own one of every business!", LoadTexture("assets/badge_art/badge_placeholder.png"));
}

AchievementManager::~AchievementManager()
{
	for (int i = 0; i < badges.size(); i++)
	{
		delete(badges[i]);
	}
}

void AchievementManager::AchievementListener()
{

}

void AchievementManager::RenderBadges()
{
	for (int i = 0; i < badges.size(); ++i)
	{
		int col = i % 7;
		int row = i / 7;
		float x = 420 + (float)col * (48 + 5); 
		float y = 460 + (float)row * (48 + 5);
		badges[i]->position.x = x;
		badges[i]->position.y = y;
		badges[i]->width = 48;
		badges[i]->height = 48;

		if (badges[i]->awarded)
		{
			DrawTexture(badges[i]->badge_icon, x, y, WHITE);
		}
		else
		{
			DrawTexture(badges[i]->badge_icon, x, y, Color{ 0, 0, 0, 255 });
		}
	}
}

Badge* AchievementManager::CreateAchievement(std::string name, std::string description, Texture2D icon)
{
	Badge* badge = new Badge(name, description, icon);
	badges.push_back(badge);
	return badge;
}

void AchievementManager::UnlockAchievement(Badge* badge)
{
	if (badge != nullptr)
	{
		badge->awarded = true;
	}
}
