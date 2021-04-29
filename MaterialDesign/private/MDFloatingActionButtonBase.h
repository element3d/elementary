
#ifndef __MDFloatingActionButtonBase_H__
#define __MDFloatingActionButtonBase_H__

#include <e3/ViewFactory.h>
#include <MDIcon.h>

// #include "../AppAssets.h"

class MDFloatingActionButtonBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDFloatingActionButtonBase();

 
protected:
	e3::Element* mRipple = nullptr;
MDIcon* mIcon = nullptr;


};

#endif // __MDFloatingActionButtonBase_H__

