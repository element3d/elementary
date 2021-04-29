
#ifndef __MDInputBase_H__
#define __MDInputBase_H__

#include <e3/ViewFactory.h>

// #include "../AppAssets.h"

class MDInputBase : public e3::Input
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDInputBase();

 
protected:
	e3::Text* mHintText = nullptr;
e3::Element* mUnderline = nullptr;


};

#endif // __MDInputBase_H__

