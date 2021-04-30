
#ifndef MDButton_H_
#define MDButton_H_

#include "private/MDButtonBase.h"

enum class EMDButtonType
{
	Regular,
	Elevated,
	Outlined,
	FAB
};

class E3_EXPORT MDButton : public MDButtonBase
{
public:
	MDButton();

	void SetButtonType(EMDButtonType buttonType);
	EMDButtonType GetButtonType();

	void SetIcon(const std::string& iconName);
	void SetLabel(const std::string& label);

public:
	virtual bool OnClick(e3::MouseEvent* pEvent) override;
	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;

public:
	virtual void Render() override;

private:
	void _UpdateStyles();

private:
	EMDButtonType mButtonType;
	e3::Animation* mRippleAnimation = nullptr;
};

#endif // MDButton_H_

