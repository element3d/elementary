
#ifndef MDTabBar_H_
#define MDTabBar_H_

#include "private/MDTabBarBase.h"
#include "MDTab.h"
#include "MDTabBarView.h"

class E3_EXPORT MDTabBar : public MDTabBarBase
{
	typedef std::function<void(MDTab*)> OnTabSelectCallback;
public:
	MDTabBar();

public:
	virtual void Render() override;
	void AddElement(MDTab* pTab);

public:
	void SetTabBarView(MDTabBarView* pTabBarView);
	void SetOnTabSelectCallback(OnTabSelectCallback onTabSelectCallback);

public:
	virtual void SetTranslation(const glm::vec3 &pos) override;

private:
	bool mFirstFrame = true;
	MDTabBarView* mTabBarView = nullptr;
	OnTabSelectCallback mOnTabSelectCallback;
	e3::Animation* mAnimation = nullptr;
};

#endif // MDTabBar_H_

