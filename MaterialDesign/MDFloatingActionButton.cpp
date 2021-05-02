#include "MDFloatingActionButton.h"
#include "MaterialDesign.h"

MDFloatingActionButton::MDFloatingActionButton()
	: MDFloatingActionButtonBase()
{
	SetBackgroundColor(MaterialDesign::GetColorPrimary());
	MaterialDesign::AddOnThemeChangeCallback([this](const MDTheme* pTheme) {
		if (!mHasColor)
			SetBackgroundColor(MaterialDesign::GetColorPrimary());
		if (!mHasIconColor)
			mIcon->SetTextColor(glm::vec4(255));
		
	});
}

void MDFloatingActionButton::SetIcon(const std::string& iconName)
{
	mIcon->SetName(iconName);

}

void MDFloatingActionButton::SetColor(const glm::vec4& color)
{
	SetBackgroundColor(color);
	mHasColor = true;
}

void MDFloatingActionButton::SetIconColor(const glm::vec4& color)
{
	mIcon->SetTextColor(color);
	mHasIconColor = true;
}

bool MDFloatingActionButton::OnClick(e3::MouseEvent* pEvent)
{
	if (!mRippleAnimation)
		mRippleAnimation = new e3::Animation();

	float x = pEvent->GetX();
	float y = pEvent->GetY();
	mRippleAnimation->Start(0.4, [this, x, y](float v) {
		mRipple->SetHeight(2 * GetGeometry().width * v);
		glm::vec4 c = MDColors::Grey::Get("300");
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

	return 	MDFloatingActionButtonBase::OnClick(pEvent);
}