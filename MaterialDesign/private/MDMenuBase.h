
#ifndef __MDMenuBase_H__
#define __MDMenuBase_H__

#include <e3/ViewFactory.h>
#include <MDIcon.h>

// #include "../AppAssets.h"

class MDMenuBase : public e3::Dropdown
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDMenuBase();

 
protected:
	MDIcon* mIcon = nullptr;


};

#endif // __MDMenuBase_H__

