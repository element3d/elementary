#include "MDTabBarViewBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDTabBarViewBase::MDTabBarViewBase()
	: e3::Element()
{
        this->SetOverflow((e3::EOverflow)0);
        this->SetAlignItemsHor((e3::EAlignment)0);

}
