#include "MDListTile.h"
#include "MaterialDesign.h"

MDListTile::MDListTile()
	: MDListTileBase()
{

}

bool MDListTile::OnClick(e3::MouseEvent* pEvent)
{
	if (!mRippleAnimation)
		mRippleAnimation = new e3::Animation();

	float x = pEvent->GetX();
	float y = pEvent->GetY();
	mRippleAnimation->Start(0.4, [this, x, y](float v) {
		mRipple->SetHeight(2 * GetGeometry().width * v);
		glm::vec4 c = MDColors::Grey::Get("300");//glm::vec4(150);//MaterialDesign::GetColorFromScheme("400"); //GetColorPrimary();
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

	return 	MDListTileBase::OnClick(pEvent);
}

void MDListTile::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDListTileBase::OnMouseEnter(pEvent);
	SetBackgroundColor(MDColors::Grey::Get("100"));
}

void MDListTile::OnMouseLeave(e3::MouseEvent* pEvent)
{
	MDListTileBase::OnMouseLeave(pEvent);

	SetBackgroundColor(glm::vec4(255));
}