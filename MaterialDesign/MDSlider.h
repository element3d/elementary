
#ifndef MDSlider_H_
#define MDSlider_H_

#include "private/MDSliderBase.h"
#include "MaterialDesign.h"

class E3_EXPORT MDSlider : public MDSliderBase
{
public:
	MDSlider();

public:
	virtual void OnMouseMove(e3::MouseEvent*) override;

	virtual void OnMouseEnter(e3::MouseEvent*) override;
	virtual void OnMouseLeave(e3::MouseEvent*) override;

	virtual bool OnMouseDown(e3::MouseEvent*) override;
	virtual bool OnMouseUp(e3::MouseEvent*) override;

	virtual void SetTranslation(const glm::vec3 &pos) override;

private:
	const MDTheme* mTheme = nullptr;
	e3::Animation* mHoverAnimation = nullptr;
	float mSliderValue = 0.0f;
};

#endif // MDSlider_H_

