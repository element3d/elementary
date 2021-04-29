#include "MDTab.h"

MDTab::MDTab()
	: MDTabBase()
{
	mIconDim = e3::Dim(25, 25, 50, 25, 25, 25);
	MaterialDesign::AddOnThemeChangeCallback([this](const MDTheme* pTheme) {
		mTheme = pTheme;
		SetBackgroundColor(pTheme->ColorPrimary);
	});
}

void MDTab::SetTextLabel(const std::string& textLabel)
{
	mLabel->SetText(textLabel);
}

void MDTab::SetLeadingIcon(const std::string& leadingIcon)
{
	mLeadingIcon->SetWidth(mIconDim);
	mLeadingIcon->SetHeight(mIconDim);
	mLeadingIcon->SetMarginRight(e3::Dim(10, 10, 20, 10, 10, 10));
	mLeadingIcon->SetName(leadingIcon);
}

bool MDTab::OnClick(e3::MouseEvent* pEvent)
{
	if (!mRippleAnimation)
		mRippleAnimation = new e3::Animation();

	float x = pEvent->GetX();
	float y = pEvent->GetY();
	mRippleAnimation->Start(0.4, [this, x, y](float v) {
		mRipple->SetHeight(2 * GetGeometry().width * v);
		glm::vec4 c = glm::vec4(150);//MaterialDesign::GetColorFromScheme("400"); //GetColorPrimary();
		c.w = (1 - v) * 150;
		mRipple->SetBackgroundColor(c);

		e3::Rect2f rippleGeo = mRipple->GetGeometry();
		e3::Rect2f geo = GetGeometry();
		mRipple->SetTranslation(glm::vec3(x - (geo.x + geo.width / 2.0f), y - (geo.y + geo.height / 2.0f), 0));
	}, [this](e3::Animation*) {
		mRippleAnimation = nullptr;
		mRipple->SetBackgroundColor(glm::vec4(0));
		mRipple->SetHeight(0);
	});

	return 	MDTabBase::OnClick(pEvent);
}

void MDTab::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDTabBase::OnMouseEnter(pEvent);
	EMDColorScheme colorScheme = MaterialDesign::GetColorScheme();
	switch (colorScheme)
	{
	case EMDColorScheme::Red:
		SetBackgroundColor(MDColors::Red::Get("600"));
		break;
	case EMDColorScheme::DeepPurple:
	{
		SetBackgroundColor(MDColors::DeepPurple::Get("600"));
		break;
	}
	case EMDColorScheme::Grey:
		SetBackgroundColor(MDColors::Grey::Get("600"));
		break;
	default:
		break;
	}
}

void MDTab::OnMouseLeave(e3::MouseEvent* pEvent)
{
	MDTabBase::OnMouseLeave(pEvent);

	SetBackgroundColor(MaterialDesign::GetColorPrimary());
}

void MDTab::Select()
{
	mTopIcon->SetTextColor(glm::vec4(255));
	mLeadingIcon->SetTextColor(glm::vec4(255));
	mLabel->SetTextColor(glm::vec4(255));
}

void MDTab::Unselect()
{
	mTopIcon->SetTextColor(glm::vec4(255, 255, 255, 150));
	mLeadingIcon->SetTextColor(glm::vec4(255, 255, 255, 150));
	mLabel->SetTextColor(glm::vec4(255, 255, 255, 150));
}