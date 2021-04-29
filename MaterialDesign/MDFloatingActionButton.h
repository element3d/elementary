
#ifndef MDFloatingActionButton_H_
#define MDFloatingActionButton_H_

#include "private/MDFloatingActionButtonBase.h"

class E3_EXPORT MDFloatingActionButton : public MDFloatingActionButtonBase
{
public:
	MDFloatingActionButton();

	void SetIcon(const std::string& iconName);

public:
	virtual bool OnClick(e3::MouseEvent* pEvent) override;

private:
	e3::Animation* mRippleAnimation = nullptr;
};

#endif // MDFloatingActionButton_H_

