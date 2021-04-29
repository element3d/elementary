#include "MDInputBase.h"

#include <e3/ViewFactory.h>
#include "MaterialDesignValues.h"

MDInputBase::MDInputBase()
	: e3::Input()
{
        this->SetWidth(e3::Dim("300", "400", "600", "300", "300", "300"));
        this->SetHeight(e3::Dim("60", "80", "120", "60", "60", "60"));
        this->SetPaddingTop(e3::Dim("15", "15", "30", "15", "15", "15"));
        this->SetFontSize(e3::Dim("17", "22", "34", "17", "17", "17"));
        this->SetOrientation((EOrientation)1);
        mHintText = e3::ViewFactory::CreateText();
        AddElement(mHintText);
        mHintText->SetText("Name*");
        mHintText->SetFontSize(e3::Dim("17", "22", "34", "17", "17", "17"));
        mHintText->SetMarginLeft(e3::Dim("10", "15", "20", "10", "10", "10"));
        mHintText->SetPositionType((e3::EPositionType)1);
        mHintText->SetLeft(0.000000);
        mUnderline = e3::ViewFactory::CreateShape( EOrientation::Horizontal);
        AddElement(mUnderline);
        mUnderline->SetWidth("100%");
        mUnderline->SetHeight(e3::Dim("2", "2", "4", "2", "2", "2"));

}
