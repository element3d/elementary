
#ifndef MDInput_H_
#define MDInput_H_

#include "private/MDInputBase.h"
#include "MaterialDesign.h"

class E3_EXPORT MDInput : public MDInputBase
{
public:
	MDInput();

	virtual bool OnClick(e3::MouseEvent* pEvent) override;
	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;

	virtual void Focus() override;
	virtual void Unfocus() override;

public:
	virtual void SetTranslation(const glm::vec3 &pos) override;

private:
	const MDTheme* mTheme = nullptr;
	bool mFocused = false;
};

#endif // MDInput_H_

