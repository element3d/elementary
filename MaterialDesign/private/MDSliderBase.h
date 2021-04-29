
#ifndef __MDSliderBase_H__
#define __MDSliderBase_H__

#include <e3/ViewFactory.h>

// #include "../AppAssets.h"

class MDSliderBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDSliderBase();

 
protected:
	e3::Element* mValue = nullptr;
e3::Element* mHoverCircle = nullptr;
e3::Element* mCircle = nullptr;


};

#endif // __MDSliderBase_H__

