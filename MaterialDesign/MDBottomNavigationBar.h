
#ifndef MDBottomNavigationBar_H_
#define MDBottomNavigationBar_H_

#include "private/MDBottomNavigationBarBase.h"
#include "MaterialDesign.h"

class E3_EXPORT MDBottomNavigationBar : public MDBottomNavigationBarBase
{
public:
	MDBottomNavigationBar();

private:
	const MDTheme* mTheme = nullptr;
};

#endif // MDBottomNavigationBar_H_

