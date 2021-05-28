#include "MDTabBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDTabBase::MDTabBase()
	: e3::Element()
{
        this->SetOrientation((e3::EOrientation)1);
        this->SetOverflow((e3::EOverflow)0);
        mRipple = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
        AddElement(mRipple);
        mRipple->SetPositionType((e3::EPositionType)1);
        mRipple->SetShapeType((e3::EShapeType)1);
        mRipple->SetAspectRatio(1.000000);
        mTopIcon = new MDIcon();
        AddElement(mTopIcon);
        mTopIcon->SetTextColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
        e3::Element* pElement1 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
        AddElement(pElement1);
        pElement1->SetPaddingLeft(e3::Dim("20", "20", "40", "20", "20", "20"));
        pElement1->SetPaddingRight(e3::Dim("20", "20", "40", "20", "20", "20"));
        pElement1->SetPaddingTop(e3::Dim("10", "10", "40", "10", "10", "10"));
        pElement1->SetPaddingBottom(e3::Dim("10", "10", "40", "10", "10", "10"));
        mLeadingIcon = new MDIcon();
        pElement1->AddElement(mLeadingIcon);
        mLeadingIcon->SetTextColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
        mLabel = e3::ViewFactory::CreateText();
        pElement1->AddElement(mLabel);
        mLabel->SetFontSize(e3::Dim("20", "20", "40", "20", "20", "20"));
        mLabel->SetTextColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));

}
