
#ifndef MDElevatedButton_H_
#define MDElevatedButton_H_

#include "private/MDElevatedButtonBase.h"

class E3_EXPORT MDElevatedButton : public MDElevatedButtonBase
{
public:
	MDElevatedButton();

	void SetIcon(const std::string& iconName);
	void SetLabel(const std::string& label);

public:
	virtual bool OnClick(e3::MouseEvent* pEvent) override;
	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;

private:
	e3::Animation* mRippleAnimation = nullptr;
};

#endif // MDElevatedButton_H_

