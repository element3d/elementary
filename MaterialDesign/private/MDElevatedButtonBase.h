
#ifndef __MDElevatedButtonBase_H__
#define __MDElevatedButtonBase_H__

#include <e3/ViewFactory.h>
#include <MDIcon.h>

// #include "../AppAssets.h"

class MDElevatedButtonBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDElevatedButtonBase();

 
protected:
	e3::Element* mRipple = nullptr;
MDIcon* mIcon = nullptr;
e3::Text* mLabel = nullptr;


};

#endif // __MDElevatedButtonBase_H__

