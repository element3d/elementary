#include "MDMenuItem.h"
#include "MaterialDesign.h"

MDMenuItem::MDMenuItem()
	: MDMenuItemBase()
{
	mText->SetTextColor(MDColors::Grey::Get("800"));
}

void MDMenuItem::SetText(const std::string& text)
{
	mText->SetText(text);
}

void MDMenuItem::SetText(const std::string& text, bool translate)
{
	mText->SetText(text, translate);
}

void MDMenuItem::SetIcon(const std::string& iconName)
{
	mIcon->SetVisibility(EVisibility::Visible);
	mIcon->SetName(iconName);
}
/*bool MDMenuItem::OnClick(e3::MouseEvent* pEvent)
{
	
	return 	MDMenuItemBase::OnClick(pEvent);
}

void MDMenuItem::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDMenuItemBase::OnMouseEnter(pEvent);
	//SetBackgroundColor(MDColors::Grey::Get("100"));
}

void MDMenuItem::OnMouseLeave(e3::MouseEvent* pEvent)
{
	MDMenuItemBase::OnMouseLeave(pEvent);

	//SetBackgroundColor(glm::vec4(255));
}*/