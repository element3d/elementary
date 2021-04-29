#include "MDBottomNavigationBar.h"

MDBottomNavigationBar::MDBottomNavigationBar()
	: MDBottomNavigationBarBase()
{
	MaterialDesign::AddOnThemeChangeCallback([this](const MDTheme* pTheme) {
		mTheme = pTheme;
		SetBackgroundColor(pTheme->ColorPrimary);
	});
}
