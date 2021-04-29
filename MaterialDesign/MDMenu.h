
#ifndef MDMenu_H_
#define MDMenu_H_

#include "private/MDMenuBase.h"

class E3_EXPORT MDMenu : public MDMenuBase
{
public:
	MDMenu();

	void SetBody(e3::DropdownBody* pBody) override;

	void Expand() override;

	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;
};

#endif // MDMenu_H_

