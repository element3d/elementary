
#ifndef __MDMenuItemBase_H__
#define __MDMenuItemBase_H__

#include <e3/ViewFactory.h>
#include "MDListTile.h"

// #include "../AppAssets.h"

class MDMenuItemBase : public MDListTile
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDMenuItemBase();

 
protected:
	e3::Text* mText = nullptr;


};

#endif // __MDMenuItemBase_H__

