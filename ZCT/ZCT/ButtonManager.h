#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"
#include "Button.h"

class ButtonManager
{
public:
	// Load And Unload
	ButtonManager();
	~ButtonManager();
	// Button Functionality
	bool OnHoverButton(Button* button);
	void ButtonHandler();
	void RenderButtons();
	Button* CreateButton(int width, int height, std::string text, Vector2 position);
	bool IsButtonClicked(Button* button);
	// Buttons
	Button* button_upgrade_01{};
	Button* button_upgrade_02{};
	Button* button_upgrade_03{};
	Button* button_upgrade_04{};
	Button* button_upgrade_05{};
	Button* button_upgrade_06{};
	Button* button_upgrade_07{};
	Button* button_buy_one{};
	Button* button_buy_five{};
	Button* button_buy_ten{};
	Button* button_buy_fifty{};
	Button* button_print_money{};
private:
	// Button Container
	std::vector<Button*> ui_Buttons{};
	// Current Selected Button
	Button* ui_selected_button{};
	int heldDownTime{};
};

