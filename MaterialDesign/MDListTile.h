
#ifndef MDListTile_H_
#define MDListTile_H_

#include "private/MDListTileBase.h"

class E3_EXPORT MDListTile : public MDListTileBase
{
public:
	MDListTile();

public:
	virtual bool OnClick(e3::MouseEvent* pEvent) override;
	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;

private:
	e3::Animation* mRippleAnimation = nullptr;
};

#endif // MDListTile_H_

