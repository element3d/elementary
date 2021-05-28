#include <e3/Application.h>
#include "MDIcon.h"
#include "MaterialDesign.h"
#include <fstream>

std::map<std::string, std::string> MDIcon::sIconMap;
std::map<std::string, std::string> MDIcon::sIconMapOutlined;

MDIcon::MDIcon()
	: MDIconBase()
{
	mIconType = EMDIconType::Regular;
	setFont("MaterialDesign/icons/MaterialIcons-Regular.ttf");
	SetTextColor(MDColors::Grey::Get("800"));
	if (!sIconMap.size()) _InitIconMap();
}

void MDIcon::Render()
{
	if (!mName.size()) return;

	if (mNameUpdated)
	{
		switch (mIconType)
		{
		case EMDIconType::Regular:
			SetCharcode(sIconMap[mName]);
			break;
		case EMDIconType::Outlined:
			SetCharcode(sIconMapOutlined[mName]);
			break;
		default:
			break;
		}

		mNameUpdated = false;
	}

	e3::FontIcon::Render();
}

void MDIcon::SetName(const std::string& name) 
{
	mName = name;
	mNameUpdated = true;
}

std::string MDIcon::GetName() 
{
	return mName;
}

void MDIcon::SetIconType(EMDIconType iconType) 
{
	mIconType = iconType;
	switch (mIconType)
	{
	case EMDIconType::Regular:
		setFont("MaterialDesign/icons/MaterialIcons-Regular.ttf");
		break;
	case EMDIconType::Outlined:
		setFont("MaterialDesign/icons/MaterialIcons-Regular.ttf");
		//setFont("MaterialDesign/icons/MaterialIconsOutlined-Regular.otf");
		break;
	default:
		break;
	}
}

EMDIconType MDIcon::GetIconType() 
{
	return mIconType;
}

void MDIcon::_InitIconMap() 
{
	{
		std::string cp = GetApplication()->GetAssetManager()->GetAssetPath("MaterialDesign/icons/MaterialIcons-Regular.codepoints");
		std::ifstream infile(cp);
		std::string name, code;
		while (infile >> name >> code)
		{
			sIconMap[name] = code;
		}
	}
	{
		std::string cp = GetApplication()->GetAssetManager()->GetAssetPath("MaterialDesign/icons/MaterialIconsOutlined-Regular.codepoints");
		std::ifstream infile(cp);
		std::string name, code;
		while (infile >> name >> code)
		{
			sIconMapOutlined[name] = code;
		}
	}

	return;
}