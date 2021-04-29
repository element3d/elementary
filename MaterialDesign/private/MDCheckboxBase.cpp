#include "MDCheckboxBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDCheckboxBase::MDCheckboxBase()
	: e3::Element()
{
        this->SetWidth(e3::Dim("25", "30", "48", "25", "25", "25"));
        this->SetAspectRatio(1.000000);
        this->SetBorderSize(2.000000);
        this->SetBorderRadius(glm::vec4(3.000000, 3.000000, 3.000000, 3.000000));
        mIcon = new MDIcon();
        AddElement(mIcon);
        mIcon->SetName(_s(done));
        mIcon->SetWidth(e3::Dim("18", "18", "30", "18", "18", "18"));
        mIcon->SetAspectRatio(1.000000);
        mIcon->SetTextColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));

}
