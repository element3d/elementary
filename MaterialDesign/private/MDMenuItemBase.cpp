#include "MDMenuItemBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDMenuItemBase::MDMenuItemBase()
	: MDListTile()
{
        mText = e3::ViewFactory::CreateText();
        AddElement(mText);
        mText->SetFontSize(e3::Dim("20", "20", "36", "20", "20", "20"));
        mText->SetTextColor(glm::vec4(0.000000, 0.000000, 0.000000, 255.000000));

}
