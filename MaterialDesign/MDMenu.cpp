#include "MDMenu.h"
#include "MaterialDesign.h"

MDMenu::MDMenu()
	: MDMenuBase()
{
	mIcon->SetTextColor(MDColors::Grey::Get("600"));
}

void MDMenu::SetBody(e3::DropdownBody* pBody)
{
	e3::Dropdown::SetBody(pBody);
	pBody->SetTop(-500);
}
void MDMenu::Expand()
{
	e3::Rect2f iconGeo = mIcon->GetGeometry();
	e3::Rect2f geo = GetGeometry();
	e3::DropdownBody* pBody = GetBody();
	pBody->SetTop(-geo.height);
	pBody->SetLeft(-pBody->GetGeometry().width + geo.width);
	e3::Dropdown::Expand();
}

void MDMenu::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDMenuBase::OnMouseEnter(pEvent);
	SetBackgroundColor(glm::vec4(255, 255, 255, 50));
}

void MDMenu::OnMouseLeave(e3::MouseEvent* pEvent)
{
	MDMenuBase::OnMouseLeave(pEvent);

	SetBackgroundColor(glm::vec4(0));
}