#include "MDRadioBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDRadioBase::MDRadioBase()
	: e3::Element()
{
        this->SetWidth(e3::Dim("22", "33", "40", "22", "22", "22"));
        this->SetHeight(e3::Dim("22", "33", "40", "22", "22", "22"));
        this->SetShapeType((EShapeType)1);
        this->SetBorderSize(5.000000);
        mCheck = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
        AddElement(mCheck);
        mCheck->SetWidth(e3::Dim("10", "15", "15", "10", "10", "10"));
        mCheck->SetHeight(e3::Dim("10", "15", "15", "10", "10", "10"));
        mCheck->SetShapeType((EShapeType)1);

}
