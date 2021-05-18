#include "MDBottomNavigationBarItemBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDBottomNavigationBarItemBase::MDBottomNavigationBarItemBase()
	: e3::Element()
{
        this->SetHeight("100%");
        this->SetAspectRatio(1.000000);
        this->SetShapeType((EShapeType)1);
        this->SetOrientation((e3::EOrientation)1);
        mIcon = new MDIcon();
        AddElement(mIcon);
        mIcon->SetAspectRatio(1.000000);
        mIcon->SetHeight("35%");
        mIcon->SetTextColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
        mTitle = e3::ViewFactory::CreateText();
        AddElement(mTitle);
        mTitle->SetFontSize(e3::Dim("14", "14", "28", "14", "14", "14"));
        mTitle->SetTextColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));

}
