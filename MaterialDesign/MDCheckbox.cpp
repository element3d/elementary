#include "MDCheckbox.h"

MDCheckbox::MDCheckbox()
	: MDCheckboxBase()
{
	mChecked = false;
	mIcon->SetOpacity(0);
	SetBorderColor(MDColors::Grey::Get());
	MaterialDesign::AddOnThemeChangeCallback([this](const MDTheme* pTheme) {
		mTheme = pTheme;
	});
}


bool MDCheckbox::OnClick(e3::MouseEvent* pEvent)
{
	if (!mChecked) Check();
	else Uncheck();

	return MDCheckboxBase::OnClick(pEvent);
}

void MDCheckbox::Check()
{
	mChecked = true;
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

	mAnimation->Start(0.2, [this, bgColor, pTheme](float v) {
		e3::Rect2f geo = GetGeometry();
		SetBackgroundColor(glm::mix(glm::vec4(0), pTheme->ColorPrimary, v));
		glm::vec4 bc = MDColors::Grey::Get();
		SetBorderColor(glm::vec4(glm::vec3(bc), 255 * (1 - v)));
		mIcon->SetOpacity(v);
		//SetBorderColor(glm::mix(glm::vec4(200, 200, 200, 255), mTheme->ColorPrimary, v));
	}, [this](e3::Animation*) {
		mAnimation = nullptr;
	});
}

void MDCheckbox::Uncheck()
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

	mAnimation->Start(0.2, [this, bgColor, pTheme](float v) {
		e3::Rect2f geo = GetGeometry();
		SetBackgroundColor(glm::mix(glm::vec4(0), pTheme->ColorPrimary, 1 - v));
		SetBorderColor(glm::mix(MDColors::Grey::Get(), pTheme->ColorPrimary, 1 - v));
		mIcon->SetOpacity(1 - v);
	}, [this](e3::Animation*) {
		mAnimation = nullptr;
	});
}

bool MDCheckbox::IsChecked()
{
	return mChecked;
}