#include "MDAppBarBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDAppBarBase::MDAppBarBase()
	: e3::Element()
{
        this->SetWidth("100%");
        this->SetHeight(55.000000);
        this->SetBackgroundColor(glm::vec4(150.000000, 10.000000, 155.000000, 255.000000));

}
