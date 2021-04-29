
#ifndef MDBottomNavigationBarItem_H_
#define MDBottomNavigationBarItem_H_

#include "private/MDBottomNavigationBarItemBase.h"

class E3_EXPORT MDBottomNavigationBarItem : public MDBottomNavigationBarItemBase
{
public:
	MDBottomNavigationBarItem();

	void SetIcon(const std::string& iconName);
	void SetTitle(const std::string& title);
};

#endif // MDBottomNavigationBarItem_H_

