#include "MDListTileBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDListTileBase::MDListTileBase()
	: e3::Element()
{
        this->SetWidth("100%");
        this->SetHeight(e3::Dim("50", "50", "140", "50", "50", "50"));
        this->SetBackgroundColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
        this->SetOverflow((e3::EOverflow)0);
        mRipple = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
        AddElement(mRipple);
        mRipple->SetPositionType((e3::EPositionType)1);
        mRipple->SetShapeType((EShapeType)1);
        mRipple->SetAspectRatio(1.000000);

}
