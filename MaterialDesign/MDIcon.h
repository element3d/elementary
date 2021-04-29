
#ifndef MDIcon_H_
#define MDIcon_H_

#include "private/MDIconBase.h"

enum class EMDIconType 
{
	Regular,
	Outlined
};

class E3_EXPORT MDIcon : public MDIconBase
{
public:
	MDIcon();

	virtual void Render() override;

public:
	void SetName(const std::string& name);
	std::string GetName();

	void SetIconType(EMDIconType iconType);
	EMDIconType GetIconType();

private:
	static void _InitIconMap();

private:
	static std::map<std::string, std::string> sIconMap;
	static std::map<std::string, std::string> sIconMapOutlined;

	std::string mName;
	bool mNameUpdated = false;
	EMDIconType mIconType;
};

#endif // MDIcon_H_

