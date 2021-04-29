
#ifndef MDMenuItem_H_
#define MDMenuItem_H_

#include "private/MDMenuItemBase.h"

class E3_EXPORT MDMenuItem : public MDMenuItemBase
{
public:
	MDMenuItem();

	void SetText(const std::string& text);
	void SetText(const std::string& text, bool translate);

/*public:
	virtual bool OnClick(e3::MouseEvent* pEvent) override;
	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;*/
};

#endif // MDMenuItem_H_

