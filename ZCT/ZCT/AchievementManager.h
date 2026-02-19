#pragma once
#include <vector>
#include "raylib.h"
#include "Badge.h"


class AchievementManager
{
public:
	AchievementManager();
	~AchievementManager();
	void AchievementListener();
	void RenderBadges();
	Badge* CreateAchievement(std::string name, std::string description, Texture2D icon);
	void UnlockAchievement(Badge* badge);
	// Achievements / Badges
	Badge* badge_first_click{};
	Badge* badge_first_upgrade{};
	Badge* badge_half_a_millionaire{};
	Badge* badge_millionaire{};
	Badge* badge_billionaire{};
	Badge* badge_own_a_sports_car{};
	Badge* badge_master_printer{};
	Badge* badge_mr_president{};
	Badge* badge_this_is_business{};
	// Business Badges
	Badge* badge_own_5_soda_stands{};
	Badge* badge_own_10_soda_stands{};
	Badge* badge_own_50_soda_stands{};
	Badge* badge_own_100_soda_stands{};
	Badge* badge_own_5_kebab_shops{};
	Badge* badge_own_10_kebab_shops{};
	Badge* badge_own_50_kebab_shops{};
	Badge* badge_own_100_kebab_shops{};
	Badge* badge_own_5_cafes{};
	Badge* badge_own_10_cafes{};
	Badge* badge_own_50_cafes{};
	Badge* badge_own_100_cafes{};
	Badge* badge_own_5_studios{};
	Badge* badge_own_10_studios{};
	Badge* badge_own_50_studios{};
	Badge* badge_own_100_studios{};
	Badge* badge_own_5_clothes{};
	Badge* badge_own_10_clothes{};
	Badge* badge_own_50_clothes{};
	Badge* badge_own_100_clothes{};
	Badge* badge_own_5_cars{};
	Badge* badge_own_10_cars{};
	Badge* badge_own_50_cars{};
	Badge* badge_own_100_cars{};
	Badge* badge_own_5_diamonds{};
	Badge* badge_own_10_diamonds{};
	Badge* badge_own_50_diamonds{};
	Badge* badge_own_100_diamonds{};
	Badge* badge_own_every_business{};
	// Badge Container
	std::vector<Badge*> badges{};
private:
	
};

