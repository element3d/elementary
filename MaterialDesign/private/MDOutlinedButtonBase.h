
#ifndef __MDOutlinedButtonBase_H__
#define __MDOutlinedButtonBase_H__

#include <e3/ViewFactory.h>
#include <MDIcon.h>

// #include "../AppAssets.h"

class MDOutlinedButtonBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDOutlinedButtonBase();

 
protected:
	e3::Element* mRipple = nullptr;
MDIcon* mIcon = nullptr;
e3::Text* mLabel = nullptr;


};

#endif // __MDOutlinedButtonBase_H__

