#include "MDTabBar.h"

MDTabBar::MDTabBar()
	: MDTabBarBase()
{

}

void MDTabBar::AddElement(MDTab* pTab)
{
	int index = mContent->GetNumChildren();
	mContent->AddElement(pTab);
	pTab->SetOnClickCallback([this, pTab, index](e3::MouseEvent*) {
		if (mOnTabSelectCallback) mOnTabSelectCallback(pTab);

		if (mTabBarView) mTabBarView->SetIndex(index);
		auto g = mSelection->GetGeometry();
		mAnimation = new e3::Animation();
		mAnimation->Start(0.3, [this, pTab, g](float v) {
			mSelection->SetWidth(g.width + (pTab->GetGeometry().width - g.width) * v);
			float sx = GetGeometry().x;
			mSelection->SetTranslation(glm::vec3(g.x -sx - GetScrollVec().x + (pTab->GetGeometry().x - g.x) * v, 0, 0));
		}, [this](e3::Animation*) {
			mAnimation = nullptr;
		});
		//mSelection->SetWidth(pTab->GetGeometry().width);
		//float sx = GetGeometry().x;
		//mSelection->SetTranslation(glm::vec3(pTab->GetGeometry().x - sx, 0, 0));

		for (int i = 0; i < mContent->GetNumChildren(); ++i)
		{
			if (mContent->GetChildren()[i] == pTab) pTab->Select();
			else 
			{
				((MDTab*)mContent->GetChildren()[i])->Unselect();
			}
		}

	});
}

void MDTabBar::Render() 
{
	if (mFirstFrame && mContent->GetNumChildren())
	{
		mSelection->SetWidth(mContent->GetChildren()[0]->GetGeometry().width);
		mFirstFrame = false;
	}

	MDTabBarBase::Render();
}

void MDTabBar::SetTabBarView(MDTabBarView* pTabBarView)
{
	mTabBarView = pTabBarView;
}

void MDTabBar::SetOnTabSelectCallback(OnTabSelectCallback onTabSelectCallback) 
{
	mOnTabSelectCallback = onTabSelectCallback;
}

void MDTabBar::SetTranslation(const glm::vec3 &pos)
{
	glm::vec4 tr(0, 0, 0, 1);
	tr = GetTranslation() * tr;

	glm::vec4 selectiontr(0, 0, 0, 1);
	selectiontr = mSelection->GetTranslation() * selectiontr;

	glm::vec4 diff = selectiontr - tr;
	e3::Element::SetTranslation(glm::vec3(pos));
	mSelection->SetTranslation(pos + glm::vec3(diff));
}