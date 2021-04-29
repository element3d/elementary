#include "MaterialDesign.h"

MDTheme MaterialDesign::sTheme;
int MaterialDesign::sId = 0;
std::map<int, MaterialDesign::OnThemeChangeCallback> MaterialDesign::sOnThemeChangeCallbacks;

void MaterialDesign::SetColorPrimary(const glm::vec4& color) 
{
	sTheme.ColorPrimary = color;
	for (auto c : sOnThemeChangeCallbacks) c.second(&sTheme);
}

glm::vec4 MaterialDesign::GetColorPrimary()
{
	return sTheme.ColorPrimary;
}

void MaterialDesign::SetColorScheme(EMDColorScheme colorScheme) 
{
	sTheme.ColorScheme = colorScheme;
	for (auto c : sOnThemeChangeCallbacks) c.second(&sTheme);
}

EMDColorScheme MaterialDesign::GetColorScheme()
{
	return sTheme.ColorScheme;
}

glm::vec4 MaterialDesign::GetColorFromScheme(const std::string name)
{
	EMDColorScheme colorScheme = MaterialDesign::GetColorScheme();
	switch (colorScheme)
	{
	case EMDColorScheme::Red:
		return MDColors::Red::Get(name);
		break;
	case EMDColorScheme::DeepPurple:
	{
		return MDColors::DeepPurple::Get(name);
		break;
	}
	case EMDColorScheme::Grey:
		return MDColors::Grey::Get(name);
		break;
	default:
		break;
	}
	return glm::vec4(0);
}

int MaterialDesign::AddOnThemeChangeCallback(OnThemeChangeCallback c) 
{
	int id = sOnThemeChangeCallbacks.size();
	sOnThemeChangeCallbacks[id] = c;
	return id;
}

void MaterialDesign::RemoveOnThemeChangeCallback(int id) 
{
	sOnThemeChangeCallbacks.erase(id);
}