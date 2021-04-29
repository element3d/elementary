#include "MDBottomSheetBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDBottomSheetBase::MDBottomSheetBase()
	: e3::Element()
{
        this->SetWidth("100%");
        this->SetPositionType((e3::EPositionType)1);
        this->SetBottom(0.000000);
        this->SetVisibility((EVisibility)1);
        this->SetAlignItemsVer((e3::EAlignment)1);

}
