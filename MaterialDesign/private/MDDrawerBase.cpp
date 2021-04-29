#include "MDDrawerBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDDrawerBase::MDDrawerBase()
	: e3::Element()
{
        this->SetHeight("100%");
        this->SetPositionType((e3::EPositionType)1);
        this->SetLeft(0.000000);
        this->SetVisibility((EVisibility)1);
        this->SetAlignItemsHor((e3::EAlignment)0);
        this->SetOverflow((e3::EOverflow)0);

}
