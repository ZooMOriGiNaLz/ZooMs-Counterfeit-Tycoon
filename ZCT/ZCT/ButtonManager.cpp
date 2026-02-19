#include "ButtonManager.h"

ButtonManager::ButtonManager()
{
	// nullptr The Buttons
	ui_selected_button = nullptr;
	// Create The Cookie
	button_print_money = CreateButton(250, 50, "         Print Some Cash", Vector2{ 70, 350 });
	// Create Buttons
	button_upgrade_01 = CreateButton(380, 50, "Sally's Soda Stand", Vector2{ 410, 30 });
	button_upgrade_02 = CreateButton(380, 50, "Kebab Empire", Vector2{ 410, 85 });
	button_upgrade_03 = CreateButton(380, 50, "World Wide Cafe", Vector2{ 410, 140 });
	button_upgrade_04 = CreateButton(380, 50, "ALTF4 Studios", Vector2{ 410, 195 });
	button_upgrade_05 = CreateButton(380, 50, "Lucci Clothes", Vector2{ 410, 250 });
	button_upgrade_06 = CreateButton(380, 50, "Luxery Car Dealership", Vector2{ 410, 305 });
	button_upgrade_07 = CreateButton(380, 50, "Dazzling Diamonds", Vector2{ 410, 360 });

	button_buy_one = CreateButton(45, 50, "x1", Vector2{ 350, 155 });
	button_buy_five = CreateButton(45, 50, "x5", Vector2{ 350, 215 });
	button_buy_ten = CreateButton(45, 50, "x10", Vector2{ 350, 275 });
	button_buy_fifty = CreateButton(45, 50, "x50", Vector2{ 350, 335 });
}

ButtonManager::~ButtonManager()
{
	// Delete Buttons
	for (int i = 0; i < ui_Buttons.size(); i++)
	{
		std::cout << "Deleted Button: " << ui_Buttons[i]->GetText() << std::endl;
		delete(ui_Buttons[i]);
	}
}

bool ButtonManager::OnHoverButton(Button* button)
{
	if (GetMousePosition().x < button->GetPosition().x + button->GetWidth() &&
		GetMousePosition().x > button->GetPosition().x &&
		GetMousePosition().y < button->GetPosition().y + button->GetHeight() &&
		GetMousePosition().y > button->GetPosition().y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ButtonManager::ButtonHandler()
{
	// Figure Out Which Upgrade Button Is Selected
	for (int i = 0; i < ui_Buttons.size(); i++)
	{
		if (OnHoverButton(ui_Buttons[i]))
		{
			ui_selected_button = ui_Buttons[i];
			break;
		}
		else
		{
			ui_selected_button = nullptr;
		}
	}
	// Visual Change For Selected Button
	if (ui_selected_button != nullptr && ui_selected_button->GetCanRender())
	{
		ui_selected_button->isSelected = true;
	}
	else
	{
		for (int i = 0; i < ui_Buttons.size(); i++)
		{
			ui_Buttons[i]->isSelected = false;
		}
	}
}

void ButtonManager::RenderButtons()
{
	for (int i = 0; i < ui_Buttons.size(); i++)
	{
		ui_Buttons[i]->Render();
	}
}

Button* ButtonManager::CreateButton(int width, int height, std::string text, Vector2 position)
{
	Button* button = new Button(width, height, text.c_str(), position);
	button->EnableRender();
	ui_Buttons.push_back(button);
	return button;
}

bool ButtonManager::IsButtonClicked(Button* button)
{
	if (IsMouseButtonPressed(0))
	{
		if (button == ui_selected_button)
		{
			return true;
		}
	}
	return false;
}
