#include "MDSwitchBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDSwitchBase::MDSwitchBase()
	: e3::Element()
{
        this->SetWidth(e3::Dim("40", "55", "80", "36", "36", "36"));
        this->SetHeight(e3::Dim("20", "30", "40", "20", "20", "20"));
        mBack = e3::ViewFactory::CreateShape( EOrientation::Horizontal);
        AddElement(mBack);
        mBack->SetWidth("100%");
        mBack->SetHeight("75%");
        mBack->SetBorderRadius(glm::vec4(1.000000, 1.000000, 1.000000, 1.000000));
        mCircle = e3::ViewFactory::CreateShape( EOrientation::Horizontal);
        AddElement(mCircle);
        mCircle->SetPositionType((e3::EPositionType)1);
        mCircle->SetLeft(0.000000);
        mCircle->SetAspectRatio(1.000000);
        mCircle->SetHeight("100%");
        mCircle->SetShapeType((EShapeType)1);
        e3::ShadowParams mCircleShadowParams;
        mCircleShadowParams.Color = glm::vec4(100.000000, 100.000000, 100.000000, 255.000000);
        mCircleShadowParams.BlurSize = 1;
        mCircleShadowParams.Opacity = 1.0;
        mCircleShadowParams.Scale = 1.0;
        mCircleShadowParams.Offset = glm::ivec2(0, 1);
        mCircle->SetShadow(mCircleShadowParams);

}
