
#ifndef MDRadio_H_
#define MDRadio_H_

#include "private/MDRadioBase.h"
#include "MaterialDesign.h"

class E3_EXPORT MDRadio : public MDRadioBase
{
public:
	MDRadio();

public:
	virtual bool OnClick(e3::MouseEvent*) override;

public:
	void Check();
	void Uncheck();

private:
	bool mIsChecked = false;
	e3::Dim mCheckDim;
	e3::Animation* mAnimation = nullptr;
	const MDTheme* mTheme = nullptr;
};

#endif // MDRadio_H_

