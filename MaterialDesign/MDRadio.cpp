#include "MDRadio.h"

MDRadio::MDRadio()
	: MDRadioBase()
{
	mCheckDim = e3::Dim("12", "15", "15", "10", "10", "10");

	MaterialDesign::AddOnThemeChangeCallback([this](const MDTheme* pTheme) {
		mTheme = pTheme;
		SetBorderColor(MDColors::Grey::Get());
	});
}

bool MDRadio::OnClick(e3::MouseEvent* pEvent)
{
	if (!mIsChecked) Check();
	return MDRadioBase::OnClick(pEvent);
}

void MDRadio::Check() 
{
	mIsChecked = true;
	SetBorderColor(mTheme->ColorPrimary);
	mCheck->SetBackgroundColor(mTheme->ColorPrimary);

	if (!mAnimation) mAnimation = new e3::Animation();
	mAnimation->Start(0.1, [this](float v) {
		mCheck->SetWidth(v * mCheckDim);
		mCheck->SetHeight(v * mCheckDim);
		SetBorderColor(glm::mix(MDColors::Grey::Get(), mTheme->ColorPrimary, v));
	}, [this](e3::Animation*) {
		mAnimation = nullptr;
	});
}

void MDRadio::Uncheck() 
{
	SetBorderColor(MDColors::Grey::Get());
	
	mIsChecked = false;
	if (!mAnimation) mAnimation = new e3::Animation();
	mAnimation->Start(0.1, [this](float v) {
		mCheck->SetWidth((1 - v) * mCheckDim);
		mCheck->SetHeight((1 - v) * mCheckDim);
		SetBorderColor(glm::mix(MDColors::Grey::Get(), mTheme->ColorPrimary, 1 - v));
	}, [this](e3::Animation*) {
		mAnimation = nullptr;
		mCheck->SetBackgroundColor(glm::vec4(0));
	});
}