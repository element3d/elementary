#include "MDElevatedButtonBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDElevatedButtonBase::MDElevatedButtonBase()
	: e3::Element()
{
        this->SetWidth(e3::Dim("100", "150", "200", "100", "100", "100"));
        this->SetHeight(e3::Dim("35", "55", "70", "35", "35", "35"));
        this->SetBorderRadius(glm::vec4(5.000000, 5.000000, 5.000000, 5.000000));
        this->SetOverflow((e3::EOverflow)0);
        mRipple = e3::ViewFactory::CreateShape( EOrientation::Horizontal);
        AddElement(mRipple);
        mRipple->SetPositionType((e3::EPositionType)1);
        mRipple->SetShapeType((EShapeType)1);
        mRipple->SetAspectRatio(1.000000);
        mIcon = new MDIcon();
        AddElement(mIcon);
        mLabel = e3::ViewFactory::CreateText();
        AddElement(mLabel);
        mLabel->SetFontSize(e3::Dim("18", "22", "36", "18", "18", "18"));

}
