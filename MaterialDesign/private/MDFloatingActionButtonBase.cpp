#include "MDFloatingActionButtonBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDFloatingActionButtonBase::MDFloatingActionButtonBase()
	: e3::Element()
{
        this->SetWidth(e3::Dim("55", "80", "140", "55", "55", "55"));
        this->SetShapeType((e3::EShapeType)1);
        this->SetAspectRatio(1.000000);
        this->SetOverflow((e3::EOverflow)0);
        e3::ShadowParams ShadowParams;
        ShadowParams.Color = glm::vec4(0.000000, 0.000000, 0.000000, 255.000000);
        ShadowParams.BlurSize = 2;
        ShadowParams.Opacity = 1.0;
        ShadowParams.Scale = 1.0;
        ShadowParams.Offset = glm::ivec2(0, 2);
        SetShadow(ShadowParams);
        mRipple = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
        AddElement(mRipple);
        mRipple->SetPositionType((e3::EPositionType)1);
        mRipple->SetShapeType((e3::EShapeType)1);
        mRipple->SetAspectRatio(1.000000);
        mIcon = new MDIcon();
        AddElement(mIcon);
        mIcon->SetHeight(e3::Dim("15", "22", "30", "15", "15", "15"));
        mIcon->SetAspectRatio(1.000000);

}
