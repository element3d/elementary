#include "MDInput.h"
#include "MaterialDesign.h"

MDInput::MDInput()
	: MDInputBase()
{
	MaterialDesign::AddOnThemeChangeCallback([this](const MDTheme* pTheme) {
		mTheme = pTheme;
		SetCursorColor(mTheme->ColorPrimary);
		SetBackgroundColor(MDColors::Grey::Get("200"));
		mUnderline->SetBackgroundColor(MDColors::Grey::Get("500"));
	});

	GetChildren()[0]->SetPaddingLeft(e3::Dim(10, 15, 20, 10, 10, 10));
}

bool MDInput::OnClick(e3::MouseEvent* pEvent)
{
	bool b = e3::Input::OnClick(pEvent);
	
	return b;
}

void MDInput::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDInputBase::OnMouseEnter(pEvent);
	if (!mFocused)
		SetBackgroundColor(MDColors::Grey::Get("300"));
}

void MDInput::OnMouseLeave(e3::MouseEvent* pEvent)
{
	MDInputBase::OnMouseLeave(pEvent);

	SetBackgroundColor(MDColors::Grey::Get("200"));
}

void MDInput::Focus()
{
	const MDTheme* pTheme = mTheme ? mTheme : MaterialDesign::GetTheme();

	e3::Input::Focus();
	mHintText->SetTranslation(glm::vec3(0, e3::Dim(-10, -15, -20, -10, -10, -10), 0));
	mHintText->SetScale(glm::vec3(0.7, 0.7, 1.0));
	mHintText->SetTextColor(pTheme->ColorPrimary);
	mUnderline->SetBackgroundColor(pTheme->ColorPrimary);
	SetBackgroundColor(MDColors::Grey::Get("200"));
	mFocused = true;
}

void MDInput::Unfocus()
{
	mFocused = false;
	if (!GetText().size())
	{
		mHintText->SetTranslation(glm::vec3(0, 0, 0));
		mHintText->SetScale(glm::vec3(1.0, 1.0, 1.0));
	}
	mHintText->SetTextColor(glm::vec4(0, 0, 0, 255));
	mUnderline->SetBackgroundColor(MDColors::Grey::Get("600"));
	e3::Input::Unfocus();
}

void MDInput::SetTranslation(const glm::vec3 &pos)
{
	glm::vec4 tr(0, 0, 0, 1);
	tr = GetTranslation() * tr;

	glm::vec4 checktr(0, 0, 0, 1);
	checktr = mHintText->GetTranslation() * checktr;

	glm::vec4 diff = checktr - tr;
	e3::Element::SetTranslation(glm::vec3(pos));
	mHintText->SetTranslation(pos + glm::vec3(diff));
}
