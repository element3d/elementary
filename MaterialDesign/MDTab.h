
#ifndef MDTab_H_
#define MDTab_H_

#include "private/MDTabBase.h"
#include "MaterialDesign.h"

class E3_EXPORT MDTab : public MDTabBase
{
	friend class MDTabBar;
public:
	MDTab();

	void SetTextLabel(const std::string& textLabel);
	void SetLeadingIcon(const std::string& leadingIcon);

public:
	virtual bool OnClick(e3::MouseEvent* pEvent) override;
	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;

private:
	void Select();
	void Unselect();
	void Render() override 
	{
		MDTabBase::Render();
	}
private:
	const MDTheme* mTheme = nullptr;
	e3::Dim mIconDim;
	e3::Animation* mRippleAnimation = nullptr;
};

#endif // MDTab_H_

