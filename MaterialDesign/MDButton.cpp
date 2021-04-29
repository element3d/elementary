#include "MDButton.h"
#include "MaterialDesign.h"

MDButton::MDButton()
	: MDButtonBase()
{
	mButtonType = EMDButtonType::Regular;
	SetBackgroundColor(glm::vec4(255));
	SetBorderRadius(glm::vec4(5));

	MaterialDesign::AddOnThemeChangeCallback([this](const MDTheme* pTheme) {
		switch (mButtonType)
		{
		case EMDButtonType::Regular:
			SetBackgroundColor(glm::vec4(255));
			mIcon->SetTextColor(MaterialDesign::GetColorPrimary());
			mLabel->SetTextColor(MaterialDesign::GetColorPrimary());
			SetBorderColor(MaterialDesign::GetColorPrimary());
			SetBorderSize(0);
			break;
		case EMDButtonType::Elevated:
			SetBackgroundColor(MaterialDesign::GetColorPrimary());
			mLabel->SetTextColor(glm::vec4(255));
			mIcon->SetTextColor(glm::vec4(255));
			break;
		case EMDButtonType::Outlined:
			SetBackgroundColor(glm::vec4(255));
			mIcon->SetTextColor(MaterialDesign::GetColorPrimary());
			mLabel->SetTextColor(MaterialDesign::GetColorPrimary());
			SetBorderColor(MaterialDesign::GetColorPrimary());
			SetBorderSize(1);
			break;
		case EMDButtonType::FAB:
			SetBackgroundColor(MaterialDesign::GetColorPrimary());
			SetBorderSize(0);
			SetBorderRadius(glm::vec4(1));
			mLabel->SetTextColor(glm::vec4(255));
			mIcon->SetTextColor(glm::vec4(255));
			break;
		default:
			break;
		}
	});
}

void MDButton::SetButtonType(EMDButtonType buttonType) 
{
	mButtonType = buttonType;

	switch (buttonType)
	{
	case EMDButtonType::Regular:
		SetBackgroundColor(glm::vec4(255));
		break;
	case EMDButtonType::Elevated:
		SetBackgroundColor(MaterialDesign::GetColorPrimary());
		mLabel->SetTextColor(glm::vec4(255));
		mIcon->SetTextColor(glm::vec4(255));
		break;
	case EMDButtonType::Outlined:
		SetBackgroundColor(glm::vec4(255));
		SetBorderColor(MaterialDesign::GetColorPrimary());
		SetBorderSize(1);
		break;
	case EMDButtonType::FAB:
		SetBackgroundColor(MaterialDesign::GetColorPrimary());
		SetBorderSize(0);
		SetBorderRadius(glm::vec4(1));
		break;
	default:
		break;
	}
}

EMDButtonType MDButton::GetButtonType() 
{
	return mButtonType;
}

void MDButton::SetIcon(const std::string& iconName) 
{
	mIcon->SetName(iconName);
	mIcon->SetHeight("40%");
	mIcon->SetMarginRight(10);
	mIcon->SetTextColor(MaterialDesign::GetColorPrimary());
}

void MDButton::SetLabel(const std::string& label) 
{
	mLabel->SetText(label);
	mLabel->SetTextColor(MaterialDesign::GetColorPrimary());
}

void MDButton::Render()
{
	/*switch (mButtonType)
	{
	case EMDButtonType::Regular:
		SetBackgroundColor(glm::vec4(255));
		break;
	case EMDButtonType::Elevated:
		mLabel->SetTextColor(glm::vec4(255));
		mIcon->SetTextColor(glm::vec4(255));
		SetBackgroundColor(MaterialDesign::GetColorPrimary());
		break;
	case EMDButtonType::Outlined:
		mIcon->SetTextColor(MaterialDesign::GetColorPrimary());
		mLabel->SetTextColor(MaterialDesign::GetColorPrimary());
		SetBackgroundColor(glm::vec4(255));
		break;
	case EMDButtonType::FAB:
		SetBackgroundColor(MaterialDesign::GetColorPrimary());
		break;
	default:
		break;
	}*/

	SetBorderColor(MDColors::Grey::Get("400"));
	MDButtonBase::Render();
}

bool MDButton::OnClick(e3::MouseEvent* pEvent)
{
	if (!mRippleAnimation)
		mRippleAnimation = new e3::Animation();
	
	float x = pEvent->GetX();
	float y = pEvent->GetY();
	mRippleAnimation->Start(0.4, [this, x, y](float v) {
		mRipple->SetHeight(2 * GetGeometry().width * v);
		glm::vec4 c = MDColors::Grey::Get("300");//MaterialDesign::GetColorPrimary();
		c.w = (1 - v ) * 255;
		mRipple->SetBackgroundColor(c);

		e3::Rect2f rippleGeo = mRipple->GetGeometry();
		e3::Rect2f geo = GetGeometry();
		mRipple->SetTranslation(glm::vec3(x - (geo.x + geo.width / 2.0f), y - (geo.y + geo.height / 2.0f), 0));
	}, [this](e3::Animation*) {
		mRippleAnimation = nullptr;
		mRipple->SetBackgroundColor(glm::vec4(0));
		mRipple->SetHeight(0);
	});

	return 	MDButtonBase::OnClick(pEvent);
}

void MDButton::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDButtonBase::OnMouseEnter(pEvent);
	EMDColorScheme colorScheme = MaterialDesign::GetColorScheme();
	switch (colorScheme)
	{
	case EMDColorScheme::Red:
		SetBackgroundColor(MDColors::Red::Get("50"));
		break;
	case EMDColorScheme::DeepPurple:
	{
		if (mButtonType == EMDButtonType::Elevated || mButtonType == EMDButtonType::FAB)
		{
			SetBackgroundColor(MDColors::DeepPurple::Get("400"));
		}
		else
		{
			SetBackgroundColor(MDColors::DeepPurple::Get("50"));
		}
		break;
	}
	case EMDColorScheme::Grey:
		SetBackgroundColor(MDColors::Grey::Get("50"));
		break;
	default:
		break;
	}
}

void MDButton::OnMouseLeave(e3::MouseEvent* pEvent)
{
	MDButtonBase::OnMouseLeave(pEvent);
	// SetBackgroundColor(glm::vec4(255));

	switch (mButtonType)
	{
	case EMDButtonType::Regular:
		SetBackgroundColor(glm::vec4(255));
		break;
	case EMDButtonType::Elevated:
		SetBackgroundColor(MaterialDesign::GetColorPrimary());
		break;
	case EMDButtonType::Outlined:
		SetBackgroundColor(glm::vec4(255));
		break;
	case EMDButtonType::FAB:
		SetBackgroundColor(MaterialDesign::GetColorPrimary());
		break;
	default:
		break;
	}
}