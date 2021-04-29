#include "MDSwitch.h"

MDSwitch::MDSwitch()
	: MDSwitchBase()
{
	mBack->SetBackgroundColor(MDColors::Grey::Get());
	mCircle->SetBackgroundColor(glm::vec4(255));
	MaterialDesign::AddOnThemeChangeCallback([this](const MDTheme* pTheme) {
		mTheme = pTheme;
	});
}

bool MDSwitch::OnClick(e3::MouseEvent* pEvent) 
{
	if (!mChecked) Check();
	else Uncheck();

	return MDSwitchBase::OnClick(pEvent);
}

void MDSwitch::SetTranslation(const glm::vec3 &pos)
{
	glm::vec4 tr(0, 0, 0, 1);
	tr = GetTranslation() * tr;

	glm::vec4 checktr(0, 0, 0, 1);
	checktr = mCircle->GetTranslation() * checktr;

	glm::vec4 diff = checktr - tr;
	e3::Element::SetTranslation(glm::vec3(pos));
	mCircle->SetTranslation(pos + glm::vec3(diff));
}

void MDSwitch::Check() 
{
	mChecked = true;
	if (mAnimation) return;
	mAnimation = new e3::Animation();

	glm::vec4 bgColor;
	const MDTheme* pTheme = mTheme ? mTheme : MaterialDesign::GetTheme();
	switch (pTheme->ColorScheme)
	{
	case EMDColorScheme::Red:
		bgColor = MDColors::Red::Get("200");
		break;
	case EMDColorScheme::DeepPurple:
	{
		bgColor = MDColors::DeepPurple::Get("200");
		break;
	}
	case EMDColorScheme::Grey:
		bgColor = MDColors::Grey::Get("200");
		break;
	default:
		break;
	}

	mAnimation->Start(0.3, [this, bgColor, pTheme](float v) {
		e3::Rect2f geo = GetGeometry();
		mCircle->SetBackgroundColor(glm::mix(glm::vec4(255), pTheme->ColorPrimary, v));
		mCircle->SetTranslation(glm::vec3(v * (geo.width - mCircle->GetGeometry().width), 0, 0));
		
		mBack->SetBackgroundColor(glm::mix(MDColors::Grey::Get(), bgColor, v));
	}, [this](e3::Animation*) {
		mAnimation = nullptr;
	});
}

void MDSwitch::Uncheck() 
{
	mChecked = false;
	if (mAnimation) return;
	mAnimation = new e3::Animation();

	const MDTheme* pTheme = mTheme ? mTheme : MaterialDesign::GetTheme();
	glm::vec4 bgColor;
	switch (pTheme->ColorScheme)
	{
	case EMDColorScheme::Red:
		bgColor = MDColors::Red::Get("200");
		break;
	case EMDColorScheme::DeepPurple:
	{
		bgColor = MDColors::DeepPurple::Get("200");
		break;
	}
	case EMDColorScheme::Grey:
		bgColor = MDColors::Grey::Get("200");
		break;
	default:
		break;
	}

	mAnimation->Start(0.3, [this, bgColor, pTheme](float v) {
		e3::Rect2f geo = GetGeometry();
		mCircle->SetBackgroundColor(glm::mix(glm::vec4(255), pTheme->ColorPrimary, 1 - v));
		mCircle->SetTranslation(glm::vec3((1 - v) * (geo.width - mCircle->GetGeometry().width), 0, 0));

		mBack->SetBackgroundColor(glm::mix(MDColors::Grey::Get(), bgColor, 1 - v));
	}, [this](e3::Animation*) {
		mAnimation = nullptr;
	});
}