
#ifndef __MDTabBarBase_H__
#define __MDTabBarBase_H__

#include <e3/ViewFactory.h>

// #include "../AppAssets.h"

class MDTabBarBase : public e3::ScrollView
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDTabBarBase();

 
protected:
	e3::Element* mContent = nullptr;
e3::Element* mSelection = nullptr;


};

#endif // __MDTabBarBase_H__

