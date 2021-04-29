
#ifndef __MDTabBase_H__
#define __MDTabBase_H__

#include <e3/ViewFactory.h>
#include <MDIcon.h>

// #include "../AppAssets.h"

class MDTabBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDTabBase();

 
protected:
	e3::Element* mRipple = nullptr;
MDIcon* mTopIcon = nullptr;
MDIcon* mLeadingIcon = nullptr;
e3::Text* mLabel = nullptr;


};

#endif // __MDTabBase_H__

