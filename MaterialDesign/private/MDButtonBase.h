
#ifndef __MDButtonBase_H__
#define __MDButtonBase_H__

#include <e3/ViewFactory.h>
#include <MDIcon.h>

// #include "../AppAssets.h"

class MDButtonBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDButtonBase();

 
protected:
	e3::Element* mRipple = nullptr;
MDIcon* mIcon = nullptr;
e3::Text* mLabel = nullptr;


};

#endif // __MDButtonBase_H__

