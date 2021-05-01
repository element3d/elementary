#include "MDElevatedButton.h"
#include "MaterialDesign.h"

MDElevatedButton::MDElevatedButton()
	: MDElevatedButtonBase()
{
	MaterialDesign::AddOnThemeChangeCallback([this](const MDTheme* pTheme) {
		SetBackgroundColor(MaterialDesign::GetColorPrimary());
		mLabel->SetTextColor(glm::vec4(255));
		mIcon->SetTextColor(glm::vec4(255));
	});
}

void MDElevatedButton::SetIcon(const std::string& iconName)
{
	mIcon->SetName(iconName);
	mIcon->SetHeight("40%");
	mIcon->SetMarginRight(10);
	//	mIcon->SetTextColor(MaterialDesign::GetColorPrimary());
}

void MDElevatedButton::SetLabel(const std::string& label)
{
	mLabel->SetText(label);
	//	mLabel->SetTextColor(MaterialDesign::GetColorPrimary());
}


bool MDElevatedButton::OnClick(e3::MouseEvent* pEvent)
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

	return 	MDElevatedButtonBase::OnClick(pEvent);
}

void MDElevatedButton::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDElevatedButtonBase::OnMouseEnter(pEvent);
	EMDColorScheme colorScheme = MaterialDesign::GetColorScheme();
	switch (colorScheme)
	{
	case EMDColorScheme::Red:
		SetBackgroundColor(MDColors::Red::Get("50"));
		break;
	case EMDColorScheme::DeepPurple:
	{
		
		SetBackgroundColor(MDColors::DeepPurple::Get("400"));
		break;
	}
	case EMDColorScheme::Grey:
		SetBackgroundColor(MDColors::Grey::Get("50"));
		break;
	default:
		break;
	}
}

void MDElevatedButton::OnMouseLeave(e3::MouseEvent* pEvent)
{
	MDElevatedButtonBase::OnMouseLeave(pEvent);
	SetBackgroundColor(MaterialDesign::GetColorPrimary());
}