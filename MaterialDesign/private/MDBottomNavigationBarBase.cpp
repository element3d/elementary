#include "MDBottomNavigationBarBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDBottomNavigationBarBase::MDBottomNavigationBarBase()
	: e3::Element()
{
        this->SetWidth("100%");
        this->SetHeight(e3::Dim("60", "60", "120", "60", "60", "60"));
        this->SetBackgroundColor(glm::vec4(150.000000, 10.000000, 155.000000, 255.000000));

}
