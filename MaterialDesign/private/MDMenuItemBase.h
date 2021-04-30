
#ifndef __MDMenuItemBase_H__
#define __MDMenuItemBase_H__

#include <e3/ViewFactory.h>
#include <MDIcon.h>
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
	MDIcon* mIcon = nullptr;
e3::Text* mText = nullptr;


};

#endif // __MDMenuItemBase_H__

