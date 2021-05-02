
#ifndef MDFloatingActionButton_H_
#define MDFloatingActionButton_H_

#include "private/MDFloatingActionButtonBase.h"

class E3_EXPORT MDFloatingActionButton : public MDFloatingActionButtonBase
{
public:
	MDFloatingActionButton();

	void SetIcon(const std::string& iconName);
	void SetColor(const glm::vec4& color);
	void SetIconColor(const glm::vec4& color);
public:
	virtual bool OnClick(e3::MouseEvent* pEvent) override;

private:
	e3::Animation* mRippleAnimation = nullptr;
	bool mHasColor = false;
	bool mHasIconColor = false;
};

#endif // MDFloatingActionButton_H_

