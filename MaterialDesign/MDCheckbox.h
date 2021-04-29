
#ifndef MDCheckbox_H_
#define MDCheckbox_H_

#include "private/MDCheckboxBase.h"
#include "MaterialDesign.h"

class E3_EXPORT MDCheckbox : public MDCheckboxBase
{
public:
	MDCheckbox();

	void Check();
	void Uncheck();

public:
	virtual bool OnClick(e3::MouseEvent*) override;

private:
	bool mChecked = false;
	e3::Animation* mAnimation = nullptr;
	const MDTheme* mTheme = nullptr;
};

#endif // MDCheckbox_H_

