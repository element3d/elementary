#include "MDBottomNavigationBarItem.h"

MDBottomNavigationBarItem::MDBottomNavigationBarItem()
	: MDBottomNavigationBarItemBase()
{

}

void MDBottomNavigationBarItem::SetIcon(const std::string& iconName)
{
	mIcon->SetName(iconName);
}

void MDBottomNavigationBarItem::SetTitle(const std::string& title)
{
	mTitle->SetText(title);
}