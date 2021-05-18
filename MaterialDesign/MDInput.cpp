#include "MDInput.h"
#include "MaterialDesign.h"

MDInput::MDInput()
	: MDInputBase()
{
	SetCursorColor(MaterialDesign::GetColorPrimary());
	SetBackgroundColor(MDColors::Grey::Get("200"));
	mUnderline->SetScale(glm::vec3(2 * GetGeometry().width, 1, 1));
	mUnderline->SetBackgroundColor(MDColors::Grey::Get("500"));
	mUnderline->SetTranslation(glm::vec3(GetGeometry().width , 0, 0));

	MaterialDesign::AddOnThemeChangeCallback([this](const MDTheme* pTheme) {
		mTheme = pTheme;
		SetCursorColor(mTheme->ColorPrimary);
		SetBackgroundColor(MDColors::Grey::Get("200"));
		mUnderline->SetBackgroundColor(MDColors::Grey::Get("500"));
	});

	/*GetChildren()[0]->*/SetPaddingLeft(e3::Dim(10, 15, 20, 10, 10, 10));
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
	glm::vec4 tr(0, 0, 0, 1);
	tr = GetTranslation() * tr;
	mHintText->SetTranslation(glm::vec3(tr.x, tr.y + e3::Dim(-10, -15, -20, -10, -10, -10), 0));
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
		glm::vec4 tr(0, 0, 0, 1);
		tr = GetTranslation() * tr;
		mHintText->SetTranslation(glm::vec3(tr));
		mHintText->SetScale(glm::vec3(1.0, 1.0, 1.0));
	}
	mHintText->SetTextColor(glm::vec4(0, 0, 0, 255));
	mUnderline->SetBackgroundColor(MDColors::Grey::Get("600"));
	e3::Input::Unfocus();
}


void MDInput::SetHint(const std::string &hint)
{
	mHintText->SetText(hint);
}

void MDInput::SetHint(const std::string &hint, bool translate)
{
	mHintText->SetText(hint, translate);
}

void MDInput::SetText(const std::string& text)
{
	if (text.size())
	{
		glm::vec4 tr(0, 0, 0, 1);
		tr = GetTranslation() * tr;
		mHintText->SetTranslation(glm::vec3(tr.x, tr.y + e3::Dim(-10, -15, -20, -10, -10, -10), 0));
		mHintText->SetScale(glm::vec3(0.7, 0.7, 1.0));
	}
	MDInputBase::SetText(text);
}

void MDInput::Render()
{
	e3::Input::Render();
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
