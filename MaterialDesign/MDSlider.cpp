#include "MDSlider.h"

MDSlider::MDSlider()
	: MDSliderBase()
{
	MaterialDesign::AddOnThemeChangeCallback([this](const MDTheme* pTheme) {
		mTheme = pTheme;
		mCircle->SetBackgroundColor(pTheme->ColorPrimary);
		glm::vec4 hoverColor = pTheme->ColorPrimary;
		hoverColor.w = 25;
		mHoverCircle->SetBackgroundColor(hoverColor);
		mValue->SetBackgroundColor(pTheme->ColorPrimary);
	});

}

void MDSlider::OnMouseMove(e3::MouseEvent* pEvent)
{
	mSliderValue = pEvent->GetX() - GetGeometry().x - mCircle->GetGeometry().width / 2.0f;
	mValue->SetWidth(mSliderValue + mCircle->GetGeometry().width / 2.0f);
	mCircle->SetTranslation(glm::vec3(mSliderValue, 0, 0));
	auto geo = mCircle->GetGeometry();
	auto hg = mHoverCircle->GetGeometry();
	mHoverCircle->SetTranslation(glm::vec3(mSliderValue - (hg.height - geo.height) / 2, 0, 0));
}

void MDSlider::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDSliderBase::OnMouseEnter(pEvent);
	mCircle->SetTranslation(glm::vec3(mSliderValue, 0, 0));

	if (!mHoverAnimation)
		mHoverAnimation = new e3::Animation();

	mHoverCircle->SetOpacity(1.0);

	mHoverAnimation->Start(0.1, [this](float value) {
		auto geo = mCircle->GetGeometry();
		mHoverCircle->SetHeight((1 + 1.5 * value) * geo.height);
		auto hg = mHoverCircle->GetGeometry();
		mHoverCircle->SetTranslation(glm::vec3(mSliderValue - (hg.height - geo.height) / 2, 0, 0));
	}, [this](e3::Animation*) {
		mHoverAnimation = nullptr;
	});
}

void MDSlider::OnMouseLeave(e3::MouseEvent* pEvent)
{
	MDSliderBase::OnMouseLeave(pEvent);

	if (!mHoverAnimation)
		mHoverAnimation = new e3::Animation();
	mHoverAnimation->Start(0.1, [this](float value) {
		auto geo = mCircle->GetGeometry();
		//mHoverCircle->SetOpacity(1 - value);
		mHoverCircle->SetHeight((1 + 1.5 * (1 - value)) * geo.height);
		auto hg = mHoverCircle->GetGeometry();
		mHoverCircle->SetTranslation(glm::vec3(mSliderValue - (hg.height - geo.height) / 2, 0, 0));
	}, [this](e3::Animation*) {
		mHoverAnimation = nullptr;
		mHoverCircle->SetOpacity(0.0);
	});
}

bool MDSlider::OnMouseDown(e3::MouseEvent* pEvent)
{
	mSliderValue = pEvent->GetX() - GetGeometry().x - mCircle->GetGeometry().width / 2.0f;
	mValue->SetWidth(mSliderValue + mCircle->GetGeometry().width / 2.0f);
	mCircle->SetTranslation(glm::vec3(mSliderValue, 0, 0));
	auto hg = mHoverCircle->GetGeometry();
	auto geo = mCircle->GetGeometry();
	mHoverCircle->SetTranslation(glm::vec3(mSliderValue - (hg.height - geo.height) / 2, 0, 0));

	return MDSliderBase::OnMouseDown(pEvent);
}

bool MDSlider::OnMouseUp(e3::MouseEvent* pEvent)
{
	

	return MDSliderBase::OnMouseUp(pEvent);
}

void MDSlider::SetTranslation(const glm::vec3 &pos)
{
	glm::vec4 tr(0, 0, 0, 1);
	tr = GetTranslation() * tr;

	glm::vec4 circletr(0, 0, 0, 1);
	circletr = mCircle->GetTranslation() * circletr;

	glm::vec4 hovertr(0, 0, 0, 1);
	hovertr = mHoverCircle->GetTranslation() * hovertr;

	e3::Element::SetTranslation(glm::vec3(pos));

	{
		glm::vec4 diff = circletr - tr;
		mCircle->SetTranslation(pos + glm::vec3(diff));
	}
	{
		glm::vec4 diff = hovertr - tr;
		mHoverCircle->SetTranslation(pos + glm::vec3(hovertr));
	}
}