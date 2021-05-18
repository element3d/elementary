#include "MDMenuBodyBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDMenuBodyBase::MDMenuBodyBase()
	: e3::DropdownBody()
{
        this->SetWidth(e3::Dim("200", "200", "600", "230", "230", "230"));
        this->SetPaddingTop(e3::Dim("10", "10", "20", "10", "10", "10"));
        this->SetPaddingBottom(e3::Dim("10", "10", "20", "10", "10", "10"));
        this->SetBackgroundColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
        this->SetBorderRadius(glm::vec4(5.000000, 5.000000, 5.000000, 5.000000));
        this->SetOrientation((e3::EOrientation)1);
        e3::ShadowParams ShadowParams;
        ShadowParams.Color = glm::vec4(0.000000, 0.000000, 0.000000, 255.000000);
        ShadowParams.BlurSize = 3;
        ShadowParams.Opacity = 1.0;
        ShadowParams.Scale = 1.0;
        ShadowParams.Offset = glm::ivec2(0, 3);
        SetShadow(ShadowParams);

}
