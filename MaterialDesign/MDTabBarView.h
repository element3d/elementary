
#ifndef MDTabBarView_H_
#define MDTabBarView_H_

#include "private/MDTabBarViewBase.h"
class MDTabBar;
class E3_EXPORT MDTabBarView : public MDTabBarViewBase
{
public:
	MDTabBarView();

	void SetIndex(int index);
	void SetTabBar(MDTabBar* pTabBar);

public:
	virtual void Render() override;
	virtual void AddElement(e3::Element* pPage) override;

private:
	int mIndex = 0;
	e3::Element* mCurrentPage = nullptr;
	e3::Element* mTmpPage = nullptr;
	e3::Animation* mAnimation = nullptr;
};

#endif // MDTabBarView_H_

