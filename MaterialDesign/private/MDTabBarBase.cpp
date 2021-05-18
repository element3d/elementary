#include "MDTabBarBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDTabBarBase::MDTabBarBase()
	: e3::ScrollView()
{
        this->SetOrientation((e3::EOrientation)0);
        this->SetOverflow((e3::EOverflow)0);
//        this->SetBackgroundColor(glm::vec4(255.000000, 0.000000, 255.000000, 255.000000));
        e3::ShadowParams ShadowParams;
        ShadowParams.Color = glm::vec4(100.000000, 100.000000, 100.000000, 255.000000);
        ShadowParams.BlurSize = 2;
        ShadowParams.Opacity = 1.0;
        ShadowParams.Scale = 1.0;
        ShadowParams.Offset = glm::ivec2(0, 2);
        SetShadow(ShadowParams);
        e3::Element* pElement1 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
        AddElement(pElement1);
        pElement1->SetOrientation((e3::EOrientation)1);
        pElement1->SetAlignItemsHor((e3::EAlignment)0);
        mContent = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
        pElement1->AddElement(mContent);
        mContent->SetScaling((e3::EScaling)1);
    //    mContent->SetBackgroundColor(glm::vec4(255.000000, 0.000000, 255.000000, 255.000000));
        mSelection = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
        pElement1->AddElement(mSelection);
        mSelection->SetPositionType((e3::EPositionType)1);
        mSelection->SetLeft(0.000000);
        mSelection->SetBottom(0.000000);
        mSelection->SetBackgroundColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
        mSelection->SetWidth("100%");
        mSelection->SetHeight(e3::Dim("2", "2", "4", "2", "2", "2"));
        mSelection->SetScaling((e3::EScaling)2);

}
