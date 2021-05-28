#include "MDMenuBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDMenuBase::MDMenuBase()
	: e3::Dropdown()
{
        this->SetShapeType((e3::EShapeType)1);
        this->SetPadding(e3::Dim("20", "20", "40", "20", "20", "20"));
        mIcon = new MDIcon();
        AddElement(mIcon);
        mIcon->SetWidth(e3::Dim("20", "20", "40", "20", "20", "20"));
        mIcon->SetHeight(e3::Dim("20", "20", "40", "20", "20", "20"));
        mIcon->SetName(_s(more_vert));

}
