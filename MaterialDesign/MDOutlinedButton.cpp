#include "MDOutlinedButton.h"
#include "MaterialDesign.h"

MDOutlinedButton::MDOutlinedButton()
	: MDOutlinedButtonBase()
{
	SetBackgroundColor(glm::vec4(255));
	mIcon->SetTextColor(MaterialDesign::GetColorPrimary());
	mLabel->SetTextColor(MaterialDesign::GetColorPrimary());
	SetBorderColor(MaterialDesign::GetColorPrimary());
	
	MaterialDesign::AddOnThemeChangeCallback([this](const MDTheme* pTheme) {
		SetBackgroundColor(glm::vec4(255));
		mIcon->SetTextColor(MaterialDesign::GetColorPrimary());
		mLabel->SetTextColor(MaterialDesign::GetColorPrimary());
		SetBorderColor(MaterialDesign::GetColorPrimary());
	});
}

void MDOutlinedButton::SetIcon(const std::string& iconName)
{
	mIcon->SetName(iconName);
	mIcon->SetHeight("40%");
	mIcon->SetMarginRight(10);
	//	mIcon->SetTextColor(MaterialDesign::GetColorPrimary());
}

void MDOutlinedButton::SetLabel(const std::string& label)
{
	mLabel->SetText(label);
	//	mLabel->SetTextColor(MaterialDesign::GetColorPrimary());
}

void MDOutlinedButton::SetLabel(const std::string& label, bool translate)
{
	mLabel->SetText(label, translate);
}

bool MDOutlinedButton::OnClick(e3::MouseEvent* pEvent)
{
	if (!mRippleAnimation)
		mRippleAnimation = new e3::Animation();

	float x = pEvent->GetX();
	float y = pEvent->GetY();
	mRippleAnimation->Start(0.4, [this, x, y](float v) {
		mRipple->SetHeight(2 * GetGeometry().width * v);
		glm::vec4 c = MDColors::Grey::Get("300");//MaterialDesign::GetColorPrimary();
		c.w = (1 - v) * 255;
		mRipple->SetBackgroundColor(c);

		e3::Rect2f rippleGeo = mRipple->GetGeometry();
		e3::Rect2f geo = GetGeometry();
		mRipple->SetTranslation(glm::vec3(x - (geo.x + geo.width / 2.0f), y - (geo.y + geo.height / 2.0f), 0));
	}, [this](e3::Animation*) {
		mRippleAnimation = nullptr;
		mRipple->SetBackgroundColor(glm::vec4(0));
		mRipple->SetHeight(0);
	});

	return 	MDOutlinedButtonBase::OnClick(pEvent);
}

void MDOutlinedButton::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDOutlinedButtonBase::OnMouseEnter(pEvent);
	EMDColorScheme colorScheme = MaterialDesign::GetColorScheme();
	switch (colorScheme)
	{
	case EMDColorScheme::Red:
		SetBackgroundColor(MDColors::Red::Get("50"));
		break;
	case EMDColorScheme::DeepPurple:
	{
		SetBackgroundColor(MDColors::DeepPurple::Get("50"));
		break;
	}
	case EMDColorScheme::Grey:
		SetBackgroundColor(MDColors::Grey::Get("50"));
		break;
	default:
		break;
	}
}

void MDOutlinedButton::OnMouseLeave(e3::MouseEvent* pEvent)
{
	MDOutlinedButtonBase::OnMouseLeave(pEvent);
	SetBackgroundColor(glm::vec4(255));
}