
#ifndef __MDBottomNavigationBarItemBase_H__
#define __MDBottomNavigationBarItemBase_H__

#include <e3/ViewFactory.h>
#include <MDIcon.h>

// #include "../AppAssets.h"

class MDBottomNavigationBarItemBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDBottomNavigationBarItemBase();

 
protected:
	MDIcon* mIcon = nullptr;
e3::Text* mTitle = nullptr;


};

#endif // __MDBottomNavigationBarItemBase_H__

