#include "MDMenuItemBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDMenuItemBase::MDMenuItemBase()
	: MDListTile()
{
        this->SetAlignItemsHor((e3::EAlignment)0);
        this->SetPaddingLeft(e3::Dim("20", "20", "36", "20", "20", "20"));
        mIcon = new MDIcon();
        AddElement(mIcon);
        mIcon->SetVisibility((EVisibility)2);
        mIcon->SetHeight("40%");
        mIcon->SetAspectRatio(1.000000);
        mIcon->SetMarginRight(e3::Dim("30", "30", "56", "30", "30", "30"));
        mIcon->SetMarginLeft(e3::Dim("10", "10", "18", "10", "10", "10"));
        mText = e3::ViewFactory::CreateText();
        AddElement(mText);
        mText->SetFontSize(e3::Dim("20", "20", "36", "20", "20", "20"));
        mText->SetTextColor(glm::vec4(0.000000, 0.000000, 0.000000, 255.000000));

}
