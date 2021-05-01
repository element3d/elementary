
#ifndef MDOutlinedButton_H_
#define MDOutlinedButton_H_

#include "private/MDOutlinedButtonBase.h"

class E3_EXPORT MDOutlinedButton : public MDOutlinedButtonBase
{
public:
	MDOutlinedButton();

	void SetIcon(const std::string& iconName);
	void SetLabel(const std::string& label);
	void SetLabel(const std::string& label, bool translate);

public:
	virtual bool OnClick(e3::MouseEvent* pEvent) override;
	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;

private:
	e3::Animation* mRippleAnimation = nullptr;
};

#endif // MDOutlinedButton_H_

