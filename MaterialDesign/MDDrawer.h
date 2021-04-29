
#ifndef MDDrawer_H_
#define MDDrawer_H_

#include "private/MDDrawerBase.h"

class E3_EXPORT MDDrawer : public MDDrawerBase
{
public:
	MDDrawer();

	virtual void AddElement(e3::Element* pElement) override;

	void Show();
	void ShowModal();
	void Hide();

	bool IsShown();

	void Render();
public:
	virtual bool OnClick(e3::MouseEvent* pEvent) override;

private:
	void Show(bool showModal);

	virtual void Build() override;

private:
	bool mIsShown = false;;
	e3::Element* mContent = nullptr;
	e3::Animation* mAnimation = nullptr;
};

#endif // MDDrawer_H_

