
#ifndef MDSwitch_H_
#define MDSwitch_H_

#include "private/MDSwitchBase.h"
#include "MaterialDesign.h"

class E3_EXPORT MDSwitch : public MDSwitchBase
{
public:
	MDSwitch();

	void Check();
	void Uncheck();

public:
	virtual bool OnClick(e3::MouseEvent*) override;
	virtual void SetTranslation(const glm::vec3 &pos) override;

private:
	bool mChecked = false;
	e3::Animation* mAnimation = nullptr;
	const MDTheme* mTheme = nullptr;
};

#endif // MDSwitch_H_

