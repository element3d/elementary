#include "MDSliderBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDSliderBase::MDSliderBase()
	: e3::Element()
{
        this->SetWidth(e3::Dim("300", "300", "600", "300", "300", "300"));
        this->SetHeight(e3::Dim("20", "30", "40", "20", "20", "20"));
        e3::Element* pElement1 = e3::ViewFactory::CreateShape( EOrientation::Horizontal);
        AddElement(pElement1);
        pElement1->SetWidth("100%");
        pElement1->SetHeight("30%");
        pElement1->SetBorderRadius(glm::vec4(1.000000, 1.000000, 1.000000, 1.000000));
        pElement1->SetBackgroundColor(glm::vec4(200.000000, 200.000000, 200.000000, 255.000000));
        mValue = e3::ViewFactory::CreateShape( EOrientation::Horizontal);
        AddElement(mValue);
        mValue->SetPositionType((e3::EPositionType)1);
        mValue->SetLeft(0.000000);
        mValue->SetHeight("30%");
        mValue->SetBorderRadius(glm::vec4(1.000000, 1.000000, 1.000000, 1.000000));
        mHoverCircle = e3::ViewFactory::CreateShape( EOrientation::Horizontal);
        AddElement(mHoverCircle);
        mHoverCircle->SetPositionType((e3::EPositionType)1);
        mHoverCircle->SetLeft(0.000000);
        mHoverCircle->SetOpacity(0.000000);
        mHoverCircle->SetAspectRatio(1.000000);
        mHoverCircle->SetHeight("100%");
        mHoverCircle->SetShapeType((EShapeType)1);
        mCircle = e3::ViewFactory::CreateShape( EOrientation::Horizontal);
        AddElement(mCircle);
        mCircle->SetPositionType((e3::EPositionType)1);
        mCircle->SetLeft(0.000000);
        mCircle->SetAspectRatio(1.000000);
        mCircle->SetHeight("100%");
        mCircle->SetShapeType((EShapeType)1);

}
